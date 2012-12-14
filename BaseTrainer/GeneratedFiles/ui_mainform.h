/********************************************************************************
** Form generated from reading UI file 'mainform.ui'
**
** Created: Sat 1. Dec 09:45:02 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFormClass
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QWidget *centralWidget;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QCheckBox *botChk;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QCheckBox *hackChk;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_3;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QGridLayout *gridLayout_4;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *senderTxt;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_5;
    QMenuBar *menuBar;
    QMenu *menuMain;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainFormClass)
    {
        if (MainFormClass->objectName().isEmpty())
            MainFormClass->setObjectName(QString::fromUtf8("MainFormClass"));
        MainFormClass->resize(224, 303);
        actionSave = new QAction(MainFormClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/MainForm/Resources/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon);
        actionLoad = new QAction(MainFormClass);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/MainForm/Resources/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoad->setIcon(icon1);
        centralWidget = new QWidget(MainFormClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_5 = new QGridLayout(centralWidget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(64, 64));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/MainForm/Resources/robot.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(64, 64));
        pushButton->setFlat(true);

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        botChk = new QCheckBox(centralWidget);
        botChk->setObjectName(QString::fromUtf8("botChk"));
        botChk->setLayoutDirection(Qt::RightToLeft);

        gridLayout->addWidget(botChk, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_2);


        gridLayout->addLayout(horizontalLayout, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer, 0, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMinimumSize(QSize(64, 64));
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(64, 64));
        pushButton_2->setFlat(true);

        gridLayout_2->addWidget(pushButton_2, 0, 1, 1, 1);

        hackChk = new QCheckBox(centralWidget);
        hackChk->setObjectName(QString::fromUtf8("hackChk"));
        hackChk->setLayoutDirection(Qt::RightToLeft);

        gridLayout_2->addWidget(hackChk, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(label_3);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 3, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMinimumSize(QSize(64, 64));
        pushButton_3->setIcon(icon2);
        pushButton_3->setIconSize(QSize(64, 64));
        pushButton_3->setFlat(true);

        gridLayout_3->addWidget(pushButton_3, 0, 1, 1, 1);

        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setLayoutDirection(Qt::RightToLeft);

        gridLayout_3->addWidget(checkBox_3, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(label_4);


        gridLayout_3->addLayout(horizontalLayout_3, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 1, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMinimumSize(QSize(64, 64));
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(64, 64));
        pushButton_4->setFlat(true);

        gridLayout_4->addWidget(pushButton_4, 0, 1, 1, 1);

        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setLayoutDirection(Qt::RightToLeft);

        gridLayout_4->addWidget(checkBox_4, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(label_5);


        gridLayout_4->addLayout(horizontalLayout_4, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 3, 1, 1);

        senderTxt = new QLineEdit(centralWidget);
        senderTxt->setObjectName(QString::fromUtf8("senderTxt"));

        gridLayout_5->addWidget(senderTxt, 2, 1, 1, 3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_5, 0, 4, 1, 1);

        MainFormClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainFormClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 224, 21));
        menuMain = new QMenu(menuBar);
        menuMain->setObjectName(QString::fromUtf8("menuMain"));
        MainFormClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainFormClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainFormClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainFormClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainFormClass->setStatusBar(statusBar);

        menuBar->addAction(menuMain->menuAction());
        menuMain->addAction(actionSave);
        menuMain->addAction(actionLoad);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionLoad);

        retranslateUi(MainFormClass);
        QObject::connect(pushButton, SIGNAL(clicked()), MainFormClass, SLOT(openBotForm()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainFormClass, SLOT(openHacksForm()));
        QObject::connect(actionLoad, SIGNAL(triggered()), MainFormClass, SLOT(loadSettings()));
        QObject::connect(actionSave, SIGNAL(triggered()), MainFormClass, SLOT(saveSettings()));
        QObject::connect(senderTxt, SIGNAL(returnPressed()), MainFormClass, SLOT(sendPacket()));

        QMetaObject::connectSlotsByName(MainFormClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainFormClass)
    {
        MainFormClass->setWindowTitle(QApplication::translate("MainFormClass", "BaseTrainer Source", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainFormClass", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("MainFormClass", "Save current settings", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionLoad->setText(QApplication::translate("MainFormClass", "Load", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        actionLoad->setStatusTip(QApplication::translate("MainFormClass", "Load old setting", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_STATUSTIP
        pushButton->setStatusTip(QApplication::translate("MainFormClass", "Make your char auto attack, loot, cc...", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton->setText(QString());
        botChk->setText(QString());
        label_2->setText(QApplication::translate("MainFormClass", "AutoBot", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_2->setStatusTip(QApplication::translate("MainFormClass", "Change Ms memory to take advantage", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_2->setText(QString());
        hackChk->setText(QString());
        label_3->setText(QApplication::translate("MainFormClass", "Hacks", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_3->setStatusTip(QApplication::translate("MainFormClass", "Not coded yet :(", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_3->setText(QString());
        checkBox_3->setText(QString());
        label_4->setText(QApplication::translate("MainFormClass", "Other", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        pushButton_4->setStatusTip(QApplication::translate("MainFormClass", "Not coded yet :(", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        pushButton_4->setText(QString());
        checkBox_4->setText(QString());
        label_5->setText(QApplication::translate("MainFormClass", "Other", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        senderTxt->setToolTip(QApplication::translate("MainFormClass", "Press enter to send the packet!", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        menuMain->setTitle(QApplication::translate("MainFormClass", "Main", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainFormClass: public Ui_MainFormClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
