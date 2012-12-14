#include "botform.h"
#include "mainform.h"

BotForm::BotForm(QWidget *parent , BotManager* manager)
	: QDialog(parent)
{
	thisTrainer->Log("BotForm created");
	ui.setupUi(this);
	
	updateGuiFromManager(manager);
	connectGuiAndManager(manager);
}

BotForm::~BotForm()
{
	thisTrainer->Log("BotForm destroyed");
}
void BotForm::updateGuiFromManager(BotManager * manager)
{
	//Set up check boxes status
	this->ui.attChk->setChecked(manager->attacking());
	this->ui.lootChk->setChecked(manager->looting());

	thisTrainer->Log("     *BotForm:: Updated Gui from manager.");
}
void BotForm::connectGuiAndManager(BotManager * manager)
{
	bool connected = true;
	//Connect check boxes with manager slots
	connected &= connect(this->ui.attChk,SIGNAL(toggled(bool)),manager,SLOT(setAttacking(bool)));
	connected &= connect(this->ui.lootChk,SIGNAL(toggled(bool)),manager,SLOT(setLooting(bool)));
	
	thisTrainer->Log(QString("     *BotForm:: %1 Gui to manager.").arg(connected ? "Connected": "Error, Can't connect"));
}