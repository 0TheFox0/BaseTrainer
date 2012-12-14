#ifndef PACKETSMANAGER_H
#define PACKETSMANAGER_H

#include <QObject>
#include <Windows.h>
/* MapleStory data packet */
//21st Century
struct COutPacket
{
	BOOL fLoopback;
	union
	{
		LPBYTE lpbData;
		LPVOID lpvData;
		LPWORD lpwHeader;
	};
	DWORD dwcbData;
	UINT uOffset;
	BOOL fEncryptedByShanda;
};

typedef void (__fastcall* lpfnSendPacket)(LPVOID lpvClass, LPVOID lpvEDX, COutPacket* pPacket);
extern lpfnSendPacket _SendPacket;
VOID __fastcall SendPacket(__in LPVOID thisSocket, __in DWORD dwEDX, __in COutPacket* pPacket);

class PacketsManager : public QObject
{
	Q_OBJECT

public:
	PacketsManager(QObject *parent);
	~PacketsManager();
	static bool sendPacket(QString packet, QString& Error);
private:
	static bool preparePacket(QString& input, QString& Error);
	static void randomizePacket(QString& input);
};

#endif // PACKETSMANAGER_H
