#include "botmanager.h"
#include "mainform.h"
#include <QMessageBox>

BotManager::BotManager(QObject *parent)
	: QObject(parent)
{
	thisTrainer->Log("BotManager object created");
	m_active = false;
	m_attacking = false;
	m_looting = false;

	bot = new QTimer(this);
	if(connect(bot,SIGNAL(timeout()),this,SLOT(botLoop())))
		thisTrainer->Log("     * BotManager::Timer coneccted");

	m_HWND = BotManager::FindProcessWindow();
	if (m_HWND == NULL)
		QMessageBox::critical(thisTrainer,"AutoBot error","Cant find Maplestory window, bots wont work :'(");
}

BotManager::~BotManager()
{
	thisTrainer->Log("BotManager destroyed");
}

HWND BotManager::FindProcessWindow()
{
	//Thanks to DRT for this... 
	TCHAR szBuffer[200];
	DWORD dwTemp;

	for (HWND hWnd = GetTopWindow(NULL); hWnd != NULL; hWnd = GetNextWindow(hWnd, GW_HWNDNEXT))
	{
		GetWindowThreadProcessId(hWnd, &dwTemp);

		if (dwTemp != GetCurrentProcessId())
		{
			continue;
		}

		if (!GetClassName(hWnd, szBuffer, sizeof(szBuffer) / sizeof(TCHAR)))
		{
			continue;
		}

		if (!wcscmp(szBuffer, L"MapleStoryClass"))
		{
			return hWnd;
		}
	}

	return NULL;
}

bool BotManager::attacking()
{
	return this->m_attacking;
}
void BotManager::setAttacking(bool state)
{
	m_attacking = state;
	if(this->isActive())//If main form checkbox is checked
		if(!this->bot->isActive())//& timer isn't enabled yet
			bot->start(100);//start with 100 ms delay
}

bool BotManager::looting()
{
	return this->m_looting;
}
void BotManager::setLooting(bool state)
{
	m_looting = state;

	if(this->isActive())//If main form checkbox is checked
		if(!this->bot->isActive())//& timer isn't enabled yet
			bot->start(100);//start with 100 ms delay
}
bool BotManager::isActive()
{
	return this->m_active;
}
void BotManager::activate(bool state)
{
	//Set up active flag
	this->m_active = state;

	if(state)//On enable
	{
		if(this->attacking() || this->looting())
			bot->start(100);
	}
	else //On disable
	{
		bot->stop();
	}	
}
void BotManager::botLoop()
{
	if(this->attacking())
		sendKey(VK_CONTROL);
	if(this->looting())
		sendKey(VK_NUMPAD0);
}
void BotManager::sendKey(int key)
{
	::PostMessage(this->m_HWND, WM_KEYDOWN, key, ::MapVirtualKey(key, 0) << 16);
}