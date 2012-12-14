/********************************************************************************
** Form generated from reading UI file 'botform.ui'
**
** Created: Sat 1. Dec 09:37:57 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOTFORM_H
#define UI_BOTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_BotForm
{
public:
    QGridLayout *gridLayout;
    QCheckBox *attChk;
    QCheckBox *lootChk;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *BotForm)
    {
        if (BotForm->objectName().isEmpty())
            BotForm->setObjectName(QString::fromUtf8("BotForm"));
        BotForm->resize(222, 298);
        gridLayout = new QGridLayout(BotForm);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        attChk = new QCheckBox(BotForm);
        attChk->setObjectName(QString::fromUtf8("attChk"));

        gridLayout->addWidget(attChk, 0, 0, 1, 1);

        lootChk = new QCheckBox(BotForm);
        lootChk->setObjectName(QString::fromUtf8("lootChk"));

        gridLayout->addWidget(lootChk, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 231, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(BotForm);

        QMetaObject::connectSlotsByName(BotForm);
    } // setupUi

    void retranslateUi(QDialog *BotForm)
    {
        BotForm->setWindowTitle(QApplication::translate("BotForm", "BotForm", 0, QApplication::UnicodeUTF8));
        attChk->setText(QApplication::translate("BotForm", "AutoAttack [CTRL]", 0, QApplication::UnicodeUTF8));
        lootChk->setText(QApplication::translate("BotForm", "AutoLoot [0]", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BotForm: public Ui_BotForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOTFORM_H
