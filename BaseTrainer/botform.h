#ifndef BOTFORM_H
#define BOTFORM_H

#include <QDialog>
#include "ui_botform.h"
#include "botmanager.h"
class BotForm : public QDialog
{
	Q_OBJECT

public:
	BotForm(QWidget *parent = 0 , BotManager * manager = 0);
	~BotForm();
	
private:
	void updateGuiFromManager(BotManager * manager);
	void connectGuiAndManager(BotManager * manager);
	Ui::BotForm ui;
};

#endif // BOTFORM_H
