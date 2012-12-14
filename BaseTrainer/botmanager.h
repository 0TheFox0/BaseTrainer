#ifndef BOTMANAGER_H
#define BOTMANAGER_H

#include <QObject>
#include <QTimer>
#include <Windows.h>
class BotManager : public QObject
{
	Q_OBJECT

public:
	BotManager(QObject *parent);
	~BotManager();
	void sendKey(int key);
public slots:
	bool isActive();
	void activate(bool state);

	bool attacking();
	void setAttacking(bool state);

	bool looting();
	void setLooting(bool state);

private slots:
	void botLoop();

private:
	static HWND FindProcessWindow();
	HWND m_HWND;

	QTimer* bot;
	bool m_active;

	bool m_attacking;
	bool m_looting;
};

#endif // BOTMANAGER_H
