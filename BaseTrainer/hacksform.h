#ifndef HACKSFORM_H
#define HACKSFORM_H

#include <QDialog>
#include "ui_hacksform.h"
#include "hacksmanager.h"

class HacksForm : public QDialog
{
	Q_OBJECT

public:
	HacksForm(QWidget *parent = 0, HacksManager* manager = 0);
	~HacksForm();

private:
	void updateGuiFromManager(HacksManager * manager);
	void connectGuiAndManager(HacksManager * manager);
	Ui::HacksForm ui;
};

#endif // HACKSFORM_H
