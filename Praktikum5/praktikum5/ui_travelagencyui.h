/********************************************************************************
** Form generated from reading UI file 'travelagencyui.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAVELAGENCYUI_H
#define UI_TRAVELAGENCYUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TravelAgencyUI
{
public:
    QAction *actionDatei_einlesen;
    QAction *actionSuche;
    QAction *actionSpeichern;
    QAction *action_iatacodes_einlesen;
    QWidget *centralwidget;
    QGroupBox *groupBox_Kunde;
    QLabel *label;
    QLineEdit *lineEdit_ID;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_Name;
    QTableWidget *tableWidget_Reisen;
    QGroupBox *groupBox_Reise;
    QLabel *label_4;
    QLineEdit *lineEdit_ReiseID;
    QLabel *label_5;
    QTableWidget *tableWidget_Buchungen;
    QMenuBar *menubar;
    QMenu *menuDatei;
    QMenu *menuKund_Innen;
    QMenu *menuSpeichern;
    QMenu *menu_iatacodes;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *TravelAgencyUI)
    {
        if (TravelAgencyUI->objectName().isEmpty())
            TravelAgencyUI->setObjectName("TravelAgencyUI");
        TravelAgencyUI->resize(602, 704);
        actionDatei_einlesen = new QAction(TravelAgencyUI);
        actionDatei_einlesen->setObjectName("actionDatei_einlesen");
        QIcon icon;
        icon.addFile(QString::fromUtf8("import_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDatei_einlesen->setIcon(icon);
        actionSuche = new QAction(TravelAgencyUI);
        actionSuche->setObjectName("actionSuche");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("search.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSuche->setIcon(icon1);
        actionSpeichern = new QAction(TravelAgencyUI);
        actionSpeichern->setObjectName("actionSpeichern");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("speichern.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionSpeichern->setIcon(icon2);
        action_iatacodes_einlesen = new QAction(TravelAgencyUI);
        action_iatacodes_einlesen->setObjectName("action_iatacodes_einlesen");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("iatacodes.jpeg"), QSize(), QIcon::Normal, QIcon::Off);
        action_iatacodes_einlesen->setIcon(icon3);
        centralwidget = new QWidget(TravelAgencyUI);
        centralwidget->setObjectName("centralwidget");
        groupBox_Kunde = new QGroupBox(centralwidget);
        groupBox_Kunde->setObjectName("groupBox_Kunde");
        groupBox_Kunde->setGeometry(QRect(9, 10, 581, 281));
        label = new QLabel(groupBox_Kunde);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 49, 16));
        lineEdit_ID = new QLineEdit(groupBox_Kunde);
        lineEdit_ID->setObjectName("lineEdit_ID");
        lineEdit_ID->setGeometry(QRect(40, 30, 31, 22));
        label_2 = new QLabel(groupBox_Kunde);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 70, 49, 16));
        label_3 = new QLabel(groupBox_Kunde);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 49, 16));
        lineEdit_Name = new QLineEdit(groupBox_Kunde);
        lineEdit_Name->setObjectName("lineEdit_Name");
        lineEdit_Name->setGeometry(QRect(70, 70, 181, 22));
        tableWidget_Reisen = new QTableWidget(groupBox_Kunde);
        if (tableWidget_Reisen->columnCount() < 3)
            tableWidget_Reisen->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Reisen->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Reisen->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Reisen->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_Reisen->setObjectName("tableWidget_Reisen");
        tableWidget_Reisen->setGeometry(QRect(70, 100, 401, 171));
        tableWidget_Reisen->verticalHeader()->setVisible(false);
        tableWidget_Reisen->verticalHeader()->setHighlightSections(true);
        groupBox_Reise = new QGroupBox(centralwidget);
        groupBox_Reise->setObjectName("groupBox_Reise");
        groupBox_Reise->setGeometry(QRect(10, 300, 581, 301));
        label_4 = new QLabel(groupBox_Reise);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 30, 49, 16));
        lineEdit_ReiseID = new QLineEdit(groupBox_Reise);
        lineEdit_ReiseID->setObjectName("lineEdit_ReiseID");
        lineEdit_ReiseID->setGeometry(QRect(80, 30, 41, 22));
        label_5 = new QLabel(groupBox_Reise);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 80, 71, 16));
        tableWidget_Buchungen = new QTableWidget(groupBox_Reise);
        if (tableWidget_Buchungen->columnCount() < 4)
            tableWidget_Buchungen->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Buchungen->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Buchungen->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Buchungen->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Buchungen->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        tableWidget_Buchungen->setObjectName("tableWidget_Buchungen");
        tableWidget_Buchungen->setGeometry(QRect(90, 90, 481, 192));
        tableWidget_Buchungen->verticalHeader()->setVisible(false);
        TravelAgencyUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TravelAgencyUI);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 602, 22));
        menuDatei = new QMenu(menubar);
        menuDatei->setObjectName("menuDatei");
        menuKund_Innen = new QMenu(menubar);
        menuKund_Innen->setObjectName("menuKund_Innen");
        menuSpeichern = new QMenu(menubar);
        menuSpeichern->setObjectName("menuSpeichern");
        menu_iatacodes = new QMenu(menubar);
        menu_iatacodes->setObjectName("menu_iatacodes");
        TravelAgencyUI->setMenuBar(menubar);
        statusbar = new QStatusBar(TravelAgencyUI);
        statusbar->setObjectName("statusbar");
        TravelAgencyUI->setStatusBar(statusbar);
        toolBar = new QToolBar(TravelAgencyUI);
        toolBar->setObjectName("toolBar");
        TravelAgencyUI->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuDatei->menuAction());
        menubar->addAction(menuKund_Innen->menuAction());
        menubar->addAction(menuSpeichern->menuAction());
        menubar->addAction(menu_iatacodes->menuAction());
        menuDatei->addAction(actionDatei_einlesen);
        menuKund_Innen->addAction(actionSuche);
        menuSpeichern->addAction(action_iatacodes_einlesen);
        menuSpeichern->addAction(actionSpeichern);
        menu_iatacodes->addAction(action_iatacodes_einlesen);
        toolBar->addAction(actionDatei_einlesen);
        toolBar->addAction(actionSuche);
        toolBar->addAction(actionSpeichern);
        toolBar->addAction(action_iatacodes_einlesen);

        retranslateUi(TravelAgencyUI);

        QMetaObject::connectSlotsByName(TravelAgencyUI);
    } // setupUi

    void retranslateUi(QMainWindow *TravelAgencyUI)
    {
        TravelAgencyUI->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "TravelAgencyUI", nullptr));
        actionDatei_einlesen->setText(QCoreApplication::translate("TravelAgencyUI", "Datei einlesen", nullptr));
        actionSuche->setText(QCoreApplication::translate("TravelAgencyUI", "Suche", nullptr));
        actionSpeichern->setText(QCoreApplication::translate("TravelAgencyUI", "Speichern", nullptr));
        action_iatacodes_einlesen->setText(QCoreApplication::translate("TravelAgencyUI", " iatacodes einlesen", nullptr));
        groupBox_Kunde->setTitle(QCoreApplication::translate("TravelAgencyUI", "Kund*in", nullptr));
        label->setText(QCoreApplication::translate("TravelAgencyUI", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("TravelAgencyUI", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("TravelAgencyUI", "Reisen", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Reisen->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("TravelAgencyUI", "Reise-ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Reisen->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("TravelAgencyUI", "Beginn der Reise", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Reisen->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("TravelAgencyUI", "Ende der Reise", nullptr));
        groupBox_Reise->setTitle(QCoreApplication::translate("TravelAgencyUI", "Reise", nullptr));
        label_4->setText(QCoreApplication::translate("TravelAgencyUI", "Reise-ID", nullptr));
        label_5->setText(QCoreApplication::translate("TravelAgencyUI", "Buchungen", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Buchungen->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("TravelAgencyUI", "Buchungstyp", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Buchungen->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("TravelAgencyUI", "Start", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Buchungen->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("TravelAgencyUI", "Ende", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Buchungen->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("TravelAgencyUI", "Preis", nullptr));
        menuDatei->setTitle(QCoreApplication::translate("TravelAgencyUI", "Datei", nullptr));
        menuKund_Innen->setTitle(QCoreApplication::translate("TravelAgencyUI", "Kund*Innen", nullptr));
        menuSpeichern->setTitle(QCoreApplication::translate("TravelAgencyUI", "Speichern", nullptr));
        menu_iatacodes->setTitle(QCoreApplication::translate("TravelAgencyUI", " iatacodes", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("TravelAgencyUI", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TravelAgencyUI: public Ui_TravelAgencyUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAVELAGENCYUI_H
