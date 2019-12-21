/********************************************************************************
** Form generated from reading UI file 'QtGuiApplication2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUIAPPLICATION2_H
#define UI_QTGUIAPPLICATION2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGuiApplication2Class
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *startButton;
    QPushButton *stopButton;
    QComboBox *selectMinutes;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtGuiApplication2Class)
    {
        if (QtGuiApplication2Class->objectName().isEmpty())
            QtGuiApplication2Class->setObjectName(QString::fromUtf8("QtGuiApplication2Class"));
        QtGuiApplication2Class->setWindowModality(Qt::ApplicationModal);
        QtGuiApplication2Class->resize(808, 699);
        QtGuiApplication2Class->setBaseSize(QSize(0, 0));
        centralWidget = new QWidget(QtGuiApplication2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 150, 281, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Papyrus"));
        font.setPointSize(36);
        label->setFont(font);
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(30, 270, 161, 61));
        QFont font1;
        font1.setPointSize(15);
        startButton->setFont(font1);
        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(200, 270, 161, 61));
        stopButton->setFont(font1);
        selectMinutes = new QComboBox(centralWidget);
        selectMinutes->addItem(QString());
        selectMinutes->addItem(QString());
        selectMinutes->setObjectName(QString::fromUtf8("selectMinutes"));
        selectMinutes->setGeometry(QRect(380, 160, 161, 51));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        selectMinutes->setFont(font2);
        selectMinutes->setLayoutDirection(Qt::LeftToRight);
        selectMinutes->setEditable(false);
        selectMinutes->setFrame(false);
        QtGuiApplication2Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtGuiApplication2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 808, 21));
        QtGuiApplication2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtGuiApplication2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtGuiApplication2Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtGuiApplication2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtGuiApplication2Class->setStatusBar(statusBar);

        retranslateUi(QtGuiApplication2Class);

        QMetaObject::connectSlotsByName(QtGuiApplication2Class);
    } // setupUi

    void retranslateUi(QMainWindow *QtGuiApplication2Class)
    {
        QtGuiApplication2Class->setWindowTitle(QApplication::translate("QtGuiApplication2Class", "QtGuiApplication2", nullptr));
        label->setText(QApplication::translate("QtGuiApplication2Class", "00:00", nullptr));
        startButton->setText(QApplication::translate("QtGuiApplication2Class", "START", nullptr));
        stopButton->setText(QApplication::translate("QtGuiApplication2Class", "STOP", nullptr));
        selectMinutes->setItemText(0, QApplication::translate("QtGuiApplication2Class", "25 Minutes", nullptr));
        selectMinutes->setItemText(1, QApplication::translate("QtGuiApplication2Class", "40 Minutes", nullptr));

    } // retranslateUi

};

namespace Ui {
    class QtGuiApplication2Class: public Ui_QtGuiApplication2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUIAPPLICATION2_H
