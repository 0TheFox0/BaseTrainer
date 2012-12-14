#include "mainform.h"
#include <Windows.h>
#include <QFileDialog>
#include <QSettings>
#include <QMessageBox>

MainForm* thisTrainer = 0;

MainForm::MainForm(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	//Set up the gui
	ui.setupUi(this);

	//Set up global pointer
	thisTrainer = this;

	//Create Bot manager object
	m_BotManager = new BotManager(this);
	//Connect the main form bot check box with bot manager global enable/disable
	connect(this->ui.botChk,SIGNAL(toggled(bool)),m_BotManager,SLOT(activate(bool)));

	//Create new Hack manager object
	m_HackManager = new HacksManager(this);
	//Connect the main form hacks check box with hack manager global enable/disable
	connect(this->ui.hackChk,SIGNAL(toggled(bool)),m_HackManager,SLOT(activate(bool)));
}

MainForm::~MainForm()
{
	#if _DEBUG
	FreeConsole();
	#endif
}


void MainForm::Log(const wchar_t *fmt, ...)
{
	#if _DEBUG
	//Thanks to Moose for this, taken from Moby.
	va_list list;
	static wchar_t buffer[1024];
	static DWORD w;
	FILE *f;

	va_start(list, fmt);

	DWORD len = wvsprintf(buffer, fmt, list);
	WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), buffer, len, (DWORD *)&w, NULL);

	va_end(list);
	#endif
}
void MainForm::Log(QString it)
{
	#if _DEBUG
	QDateTime time(QDateTime::currentDateTime());
	it.prepend(time.toString("hh:mm:ss :: "));
	it.append("\n");
	const wchar_t * wt = reinterpret_cast<const wchar_t *>(it.utf16());   
	Log(wt);
	#endif
}

void MainForm::openBotForm()
{
	//Create new Bot form object
	BotForm botForm(this,m_BotManager);
	//Show it
	botForm.exec();
}
void MainForm::openHacksForm()
{
	//Create new Hacks form object
	HacksForm hackForm(this,m_HackManager);
	//Show it
	hackForm.exec();
}
void MainForm::saveSettings()
{
	QString filename;		
	//Get the output file name with a save dialog
	filename = QFileDialog::getSaveFileName (this, tr("Select file to save settings"),
		"C:\\",tr("Setting File (*.ini)"));	 

	//Create a setting object
	QSettings settings(filename, QSettings::IniFormat);

	//Begin a group for auto bot settings
	settings.beginGroup("AutoBot");
	//Save Attacking status in "Attacking" key
	settings.setValue("Attacking",m_BotManager->attacking());
	//Save Looting status "Looting" key
	settings.setValue("Looting",m_BotManager->looting());
	//End the bot group
	settings.endGroup();	

	//Begin a group for hack settings
	settings.beginGroup("Hacks");
	//Save god mode status in "GodMode" key
	settings.setValue("GodMode",m_HackManager->Gm());
	//Save vac status in "Vac" key
	settings.setValue("Vac",m_HackManager->Vac());
	//End the hacks group
	settings.endGroup();
}
void MainForm::loadSettings()
{
	QString filename;				
	//Get the input file name with a open file dialog
	filename = QFileDialog::getOpenFileName(this, tr("Select file to save settings"),
		"C:\\",tr("Setting File (*.ini)"));	 

	//Create a setting object
	QSettings settings(filename, QSettings::IniFormat);

	//Begin to read the auto bot group
	settings.beginGroup("AutoBot");
	//Get the "Attacking" key value and set up bot manager attacking flag
	m_BotManager->setAttacking(settings.value("Attacking").toBool());
	//Get the "Looting" key value and set up bot manager looting flag
	m_BotManager->setLooting(settings.value("Looting").toBool());
	//End reading auto bot group
	settings.endGroup();	

	//Begin to read the hacks group
	settings.beginGroup("Hacks");
	//Get the "GodMode" key value and set up hack manager god mode flag
	m_HackManager->setGm(settings.value("GodMode").toBool());
	//Get the "Vac" key value and set up hack manager vac flag
	m_HackManager->setVac(settings.value("Vac").toBool());
	//End reading hacks group
	settings.endGroup();
}
void MainForm::sendPacket()
{
	QString error;
	if(!PacketsManager::sendPacket(ui.senderTxt->text(),error))
		QMessageBox::warning(this,"Error on send packet",error);
}