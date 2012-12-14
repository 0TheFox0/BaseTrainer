#ifndef MAINFORM_H
#define MAINFORM_H

#include <QtGui/QMainWindow>
#include "ui_mainform.h"
#include <QDateTime>

#include "botform.h"
#include "botmanager.h"

#include "hacksform.h"
#include "hacksmanager.h"

#include "packetsmanager.h"
class MainForm : public QMainWindow
{
	Q_OBJECT

public:
	MainForm(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainForm();

	//Debugging Log
	void Log(const wchar_t *fmt, ...);
	void Log(QString it);

private slots: 
	void openBotForm();
	void openHacksForm();

	void saveSettings();
	void loadSettings();

	void sendPacket();
private:
	Ui::MainFormClass ui;
	BotManager * m_BotManager;
	HacksManager* m_HackManager;
};
//Global Pointer to main form
extern MainForm * thisTrainer;

#endif // MAINFORM_H
