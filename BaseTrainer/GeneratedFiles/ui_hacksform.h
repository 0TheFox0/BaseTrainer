/********************************************************************************
** Form generated from reading UI file 'hacksform.ui'
**
** Created: Sat 1. Dec 09:37:57 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HACKSFORM_H
#define UI_HACKSFORM_H

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

class Ui_HacksForm
{
public:
    QGridLayout *gridLayout;
    QCheckBox *gmChk;
    QCheckBox *vacChk;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *HacksForm)
    {
        if (HacksForm->objectName().isEmpty())
            HacksForm->setObjectName(QString::fromUtf8("HacksForm"));
        HacksForm->resize(221, 299);
        gridLayout = new QGridLayout(HacksForm);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gmChk = new QCheckBox(HacksForm);
        gmChk->setObjectName(QString::fromUtf8("gmChk"));

        gridLayout->addWidget(gmChk, 0, 0, 1, 1);

        vacChk = new QCheckBox(HacksForm);
        vacChk->setObjectName(QString::fromUtf8("vacChk"));

        gridLayout->addWidget(vacChk, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 232, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(HacksForm);

        QMetaObject::connectSlotsByName(HacksForm);
    } // setupUi

    void retranslateUi(QDialog *HacksForm)
    {
        HacksForm->setWindowTitle(QApplication::translate("HacksForm", "HacksForm", 0, QApplication::UnicodeUTF8));
        gmChk->setText(QApplication::translate("HacksForm", "Dojang Godmode", 0, QApplication::UnicodeUTF8));
        vacChk->setText(QApplication::translate("HacksForm", "Vac Right", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HacksForm: public Ui_HacksForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HACKSFORM_H
