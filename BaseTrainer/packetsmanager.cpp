#include "packetsmanager.h"
#include <QStringList>
#include <vector>

//EMS 83.3
// MapleStory Send method
//21st Century source

//Client socket pointer
const LPVOID* lppvCClientSocket = reinterpret_cast<const LPVOID*>(0x00F15FF8);

//SendPacket function
lpfnSendPacket _SendPacket = reinterpret_cast<lpfnSendPacket>(0x004ABE10);

//Some ret opcode on MapleStory memory 
const LPVOID lpvSomeRet = reinterpret_cast<const LPVOID>(0x004ABE07);

void __declspec(naked) InjectPacket(COutPacket* pPacket) 
{
	__asm
	{
		//set class ptr
		mov ecx,[lppvCClientSocket]
		mov ecx,[ecx]

		//push packet and fake return address
		push [esp+4]
		push [lpvSomeRet]

		//send packet
		jmp [_SendPacket]
	}
}

bool WINAPI SendPacket ( std::vector<BYTE>& vData )
{
	//21st Century / ZPE
	COutPacket Packet;
	SecureZeroMemory(&Packet, sizeof(COutPacket));

	Packet.dwcbData = vData.size();
	Packet.lpbData = vData.data();

	try 
	{
		InjectPacket(&Packet);
		return true;
	} 
	catch (...) {return false;}
}

PacketsManager::PacketsManager(QObject *parent)
	: QObject(parent)
{
	//seed the rand function
	srand(GetTickCount());
}

PacketsManager::~PacketsManager()
{

}

//Check if packet is valid & format it for be split
bool PacketsManager::preparePacket(QString& input, QString& Error)
{
	QString aux = input.remove(" ");
	
	if ( (aux.length()%2) != 0)
	{
		Error="Check packet length!";
		return false;
	}
	//check for invalid characters
	for (int i=0;i<aux.length();i++)
	{
		if (aux.at(i) >= QChar('a') && aux.at(i) <= QChar('f'))
			continue;
		if (aux.at(i) >= QChar('A') && aux.at(i) <= QChar('F'))
			continue;
		if (aux.at(i) >= QChar('0') && aux.at(i) <= QChar('9'))
			continue;
		if (aux.at(i) == '*')
			continue;
		Error="Found invalid character in packet!";
		return false;
	}

	//this will format the packet so it can be split later
	//"aabbcc" -> "aa bb cc" -> "aa"+"bb"+"cc"
	int ilength = (aux.length()-2)/2;
	for(int n=0, i=2 ; n<ilength; i+=3 , n++)
	{
		aux.insert(i," ");
	}
	input = aux;
	return true;
}

void PacketsManager::randomizePacket(QString& input)
{	
	//  This will replace "*" for a random number
	for (int i=0;i<input.length();i++)
	{
		if (input.at(i) == '*')		//we'll use "*" as random mark on packet string
		{
			int rndm = rand()%16;	//%16 cause we only want it between 0-F (0-15)
			input[i] = QString::number(rndm,16).at(0);
		}
	}
}
bool PacketsManager::sendPacket(QString packet, QString& error)
{
	bool valid_packet = preparePacket(packet,error);
	if(valid_packet)
	{
		randomizePacket(packet);

		bool valid_hex;									//needed to QString::toUInt, see bellow
		std::vector<BYTE> vData;						//Vector to store packet data
		QStringList packet_bytes = packet.split(" ");	//List of tokens on packet string, we can use this cause of prepare packet

		for each(QString s in packet_bytes)				//loop the list & convert it to bytes, then store them on vector
			vData.push_back(static_cast<BYTE>(s.toUInt(&valid_hex,16)));

		if(!SendPacket(vData))							//send the packet
		{
			valid_packet = false;
			error = "Error sending the packet.";
		}
	}
	return valid_packet;	
}
