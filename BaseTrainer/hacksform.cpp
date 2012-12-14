#include "hacksform.h"
#include "mainform.h"
HacksForm::HacksForm(QWidget *parent, HacksManager* manager)
	: QDialog(parent)
{
	thisTrainer->Log("HackForm created");
	ui.setupUi(this);

	updateGuiFromManager(manager);
	connectGuiAndManager(manager);
}

HacksForm::~HacksForm()
{
	thisTrainer->Log("HackForm destroyed");
}
void HacksForm::updateGuiFromManager(HacksManager * manager)
{
	//Set up check boxes status
	this->ui.gmChk->setChecked(manager->Gm());
	this->ui.vacChk->setChecked(manager->Vac());

	thisTrainer->Log("     *HackForm:: Updated Gui from manager.");
}
void HacksForm::connectGuiAndManager(HacksManager * manager)
{
	bool connected = true;
	//Connect check boxes with manager slots
	connected &= connect(this->ui.gmChk,SIGNAL(toggled(bool)),manager,SLOT(setGm(bool)));
	connected &= connect(this->ui.vacChk,SIGNAL(toggled(bool)),manager,SLOT(setVac(bool)));

	thisTrainer->Log(QString("     *HackForm:: %1 Gui to manager.").arg(connected ? "Connected": "Error, Can't connect"));
}
