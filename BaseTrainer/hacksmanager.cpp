#include "hacksmanager.h"
#include "mainform.h"
#define jmp(frm, to) (int)(((int)to - (int)frm) - 5)
HacksManager::HacksManager(QObject *parent)
	: QObject(parent)
{
	thisTrainer->Log("HackManager object created");
	m_active = false;

	m_Gm = false;
	m_Vac = false;
}

HacksManager::~HacksManager()
{
	thisTrainer->Log("HackManager object destroyed");
}

bool HacksManager::isActive()
{
	return this->m_active;
}
void HacksManager::activate(bool state)
{
	m_active = state;
	setGm(m_Gm);
	setVac(m_Vac);
}

//////////////////////////////////////////////////////////////////////////
//
//		GODMODE
//
////////////////////////////////////////////////////////////
unsigned long ulSevenMissReturn = 0x00A065F4 +5;
unsigned long sevencall = 0x00AA4600;
unsigned long dwMiss = 0;
void __declspec(naked) SevenMiss() {
	
	__asm 
	{
		inc [dwMiss]
		cmp dword ptr[dwMiss],07 //amount of misses
		jbe MissReset
		mov dword ptr [dwMiss ],00
		call sevencall

		MissReset:
		jmp [ulSevenMissReturn]
	}
}
bool HacksManager::Gm()
{
	return m_Gm;
}
void HacksManager::setGm(bool state)
{
	m_Gm = state;

	if(m_Gm && m_active)
	{
		Jump(0x00A065F4, SevenMiss, 0);
	}
	else
	{	//00A065F4 - E8 07E00900  
		BYTE disable[]={0xE8, 0x07, 0xE0, 0x09, 0x00};
		WriteAddress((LPVOID)0x00A065F4,disable,sizeof(disable));
	}
}

//////////////////////////////////////////////////////////////////////////
//
//		VAC RIGTH
//
////////////////////////////////////////////////////////////
bool HacksManager::Vac()
{
	return m_Vac;
}
void HacksManager::setVac(bool state)
{
	m_Vac = state;

	if (m_Vac && m_active)
	{
		BYTE enable[]={0x75, 0x48};
		WriteAddress((LPVOID)0x00AA43F0,enable,sizeof(enable));
	}
	else
	{
		BYTE disable[]={0x75 , 0x23};
		WriteAddress((LPVOID)0x00AA43F0,disable,sizeof(disable));
	}
}

bool HacksManager::Jump(unsigned long ulAddress, void* Function, unsigned long ulNops) 
{ 
	__try 
	{ 
		unsigned long oldProtect;
		VirtualProtect((LPVOID)ulAddress,5+ulNops,PAGE_EXECUTE_READWRITE, &oldProtect);
		*(unsigned char*)ulAddress = 0xE9; 
		*(unsigned long*)(ulAddress + 1) = jmp(ulAddress, Function);
		memset((void*)(ulAddress + 5), 0x90, ulNops); 
		VirtualProtect((LPVOID)ulAddress,5+ulNops,oldProtect, &oldProtect);
		return true; 
	} 
	__except (EXCEPTION_EXECUTE_HANDLER) { return false; } 
}
bool HacksManager::WriteAddress(__in LPVOID lpcvBase, __in LPCVOID lpcvWriteValue, __in size_t uSize)
{
	DWORD old_protection = 0;

	__try
	{ 
		if(VirtualProtect(lpcvBase, uSize, PAGE_READWRITE, &old_protection))
		{
			memcpy_s(lpcvBase, uSize, lpcvWriteValue, uSize);
			VirtualProtect(lpcvBase, uSize, old_protection, &old_protection);
		}
		else
			return false;
	} 
	__except(EXCEPTION_EXECUTE_HANDLER)
	{      
		return false;
	}
	return true;
}