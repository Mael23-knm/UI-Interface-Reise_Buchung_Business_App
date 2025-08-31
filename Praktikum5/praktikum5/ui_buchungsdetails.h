/********************************************************************************
** Form generated from reading UI file 'buchungsdetails.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUCHUNGSDETAILS_H
#define UI_BUCHUNGSDETAILS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Buchungsdetails
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *lineEdit_ID_Buchungsdetails;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_Preis_Buchungsdetails;
    QLabel *label_3;
    QDateEdit *dateEdit_Von_Buchungsdetails;
    QLabel *label_4;
    QDateEdit *dateEdit_Bis_Buchungsdetails;
    QTabWidget *tabWidget_Buchungstyp;
    QWidget *tab;
    QLabel *label_5;
    QLineEdit *lineEdit_Von_Zug_Buchungsdetails;
    QTimeEdit *timeEdit_Abfahrt_Zug_Buchungsdetails;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_Nach_Zug_Buchungsdetails;
    QLabel *label_8;
    QTimeEdit *timeEdit_Ankunft_Zug_Buchungsdetails;
    QLabel *label_9;
    QLineEdit *lineEdit_Tickettyp_Zug_Buchungsdetails;
    QLabel *label_10;
    QListWidget *listWidget_Uber_Zug_Buchungsdetails;
    QWidget *tab_2;
    QLabel *label_15;
    QLineEdit *lineEdit_Vehicleclass_Car_Buchungsdetails;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *lineEdit_Abholort_Car__Buchungsdetails;
    QLineEdit *lineEdit_Ruckgabeort_Car_Buchungsdetails;
    QLineEdit *lineEdit_Unternehmen_Car_Buchungsdetails;
    QWidget *tab_3;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *lineEdit_Roomtyp_Hotel_Buchungsdetails;
    QLineEdit *lineEdit_Stadt_Hotel_Buchungsdetails;
    QLineEdit *lineEdit_Hotel_Buchungsdetails;
    QWidget *tab_4;
    QLabel *label_14;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *lineEdit_Bookingclass_Flug_Buchungsdetails;
    QLineEdit *lineEdit_Abfahrt_Flug_Buchungsdetails;
    QLineEdit *lineEdit_Ankunft_Flug_Buchungsdetails;
    QLineEdit *lineEdit_Airline_Flug_Buchungsdetails;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *lineEdit_iatacodes;
    QLineEdit *lineEdit_Flughafen_name;
    QPushButton *pushButton_OK;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Buchungsdetails)
    {
        if (Buchungsdetails->objectName().isEmpty())
            Buchungsdetails->setObjectName("Buchungsdetails");
        Buchungsdetails->resize(393, 696);
        centralwidget = new QWidget(Buchungsdetails);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 49, 16));
        lineEdit_ID_Buchungsdetails = new QLineEdit(centralwidget);
        lineEdit_ID_Buchungsdetails->setObjectName("lineEdit_ID_Buchungsdetails");
        lineEdit_ID_Buchungsdetails->setGeometry(QRect(50, 20, 211, 22));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 60, 49, 16));
        doubleSpinBox_Preis_Buchungsdetails = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_Preis_Buchungsdetails->setObjectName("doubleSpinBox_Preis_Buchungsdetails");
        doubleSpinBox_Preis_Buchungsdetails->setGeometry(QRect(50, 60, 141, 22));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 49, 16));
        dateEdit_Von_Buchungsdetails = new QDateEdit(centralwidget);
        dateEdit_Von_Buchungsdetails->setObjectName("dateEdit_Von_Buchungsdetails");
        dateEdit_Von_Buchungsdetails->setGeometry(QRect(50, 100, 141, 22));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 140, 49, 16));
        dateEdit_Bis_Buchungsdetails = new QDateEdit(centralwidget);
        dateEdit_Bis_Buchungsdetails->setObjectName("dateEdit_Bis_Buchungsdetails");
        dateEdit_Bis_Buchungsdetails->setGeometry(QRect(50, 140, 141, 22));
        tabWidget_Buchungstyp = new QTabWidget(centralwidget);
        tabWidget_Buchungstyp->setObjectName("tabWidget_Buchungstyp");
        tabWidget_Buchungstyp->setGeometry(QRect(20, 170, 371, 441));
        tabWidget_Buchungstyp->setTabBarAutoHide(false);
        tab = new QWidget();
        tab->setObjectName("tab");
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 20, 49, 16));
        lineEdit_Von_Zug_Buchungsdetails = new QLineEdit(tab);
        lineEdit_Von_Zug_Buchungsdetails->setObjectName("lineEdit_Von_Zug_Buchungsdetails");
        lineEdit_Von_Zug_Buchungsdetails->setGeometry(QRect(40, 20, 131, 22));
        timeEdit_Abfahrt_Zug_Buchungsdetails = new QTimeEdit(tab);
        timeEdit_Abfahrt_Zug_Buchungsdetails->setObjectName("timeEdit_Abfahrt_Zug_Buchungsdetails");
        timeEdit_Abfahrt_Zug_Buchungsdetails->setGeometry(QRect(60, 60, 61, 22));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 60, 49, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 100, 49, 16));
        lineEdit_Nach_Zug_Buchungsdetails = new QLineEdit(tab);
        lineEdit_Nach_Zug_Buchungsdetails->setObjectName("lineEdit_Nach_Zug_Buchungsdetails");
        lineEdit_Nach_Zug_Buchungsdetails->setGeometry(QRect(50, 100, 121, 22));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 140, 49, 16));
        timeEdit_Ankunft_Zug_Buchungsdetails = new QTimeEdit(tab);
        timeEdit_Ankunft_Zug_Buchungsdetails->setObjectName("timeEdit_Ankunft_Zug_Buchungsdetails");
        timeEdit_Ankunft_Zug_Buchungsdetails->setGeometry(QRect(60, 140, 61, 22));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 180, 49, 16));
        lineEdit_Tickettyp_Zug_Buchungsdetails = new QLineEdit(tab);
        lineEdit_Tickettyp_Zug_Buchungsdetails->setObjectName("lineEdit_Tickettyp_Zug_Buchungsdetails");
        lineEdit_Tickettyp_Zug_Buchungsdetails->setGeometry(QRect(60, 180, 131, 22));
        label_10 = new QLabel(tab);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 220, 49, 16));
        listWidget_Uber_Zug_Buchungsdetails = new QListWidget(tab);
        listWidget_Uber_Zug_Buchungsdetails->setObjectName("listWidget_Uber_Zug_Buchungsdetails");
        listWidget_Uber_Zug_Buchungsdetails->setGeometry(QRect(60, 210, 256, 141));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../build-newPraktikum3-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/train.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Buchungstyp->addTab(tab, icon, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_15 = new QLabel(tab_2);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 30, 71, 16));
        lineEdit_Vehicleclass_Car_Buchungsdetails = new QLineEdit(tab_2);
        lineEdit_Vehicleclass_Car_Buchungsdetails->setObjectName("lineEdit_Vehicleclass_Car_Buchungsdetails");
        lineEdit_Vehicleclass_Car_Buchungsdetails->setGeometry(QRect(90, 30, 113, 22));
        label_16 = new QLabel(tab_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(20, 100, 49, 16));
        label_17 = new QLabel(tab_2);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(20, 170, 71, 16));
        label_18 = new QLabel(tab_2);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(20, 240, 81, 16));
        lineEdit_Abholort_Car__Buchungsdetails = new QLineEdit(tab_2);
        lineEdit_Abholort_Car__Buchungsdetails->setObjectName("lineEdit_Abholort_Car__Buchungsdetails");
        lineEdit_Abholort_Car__Buchungsdetails->setGeometry(QRect(90, 100, 231, 22));
        lineEdit_Ruckgabeort_Car_Buchungsdetails = new QLineEdit(tab_2);
        lineEdit_Ruckgabeort_Car_Buchungsdetails->setObjectName("lineEdit_Ruckgabeort_Car_Buchungsdetails");
        lineEdit_Ruckgabeort_Car_Buchungsdetails->setGeometry(QRect(90, 170, 231, 22));
        lineEdit_Unternehmen_Car_Buchungsdetails = new QLineEdit(tab_2);
        lineEdit_Unternehmen_Car_Buchungsdetails->setObjectName("lineEdit_Unternehmen_Car_Buchungsdetails");
        lineEdit_Unternehmen_Car_Buchungsdetails->setGeometry(QRect(100, 240, 113, 22));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../build-newPraktikum3-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/car.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Buchungstyp->addTab(tab_2, icon1, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_11 = new QLabel(tab_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(30, 40, 61, 16));
        label_12 = new QLabel(tab_3);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 160, 49, 16));
        label_13 = new QLabel(tab_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 270, 49, 16));
        lineEdit_Roomtyp_Hotel_Buchungsdetails = new QLineEdit(tab_3);
        lineEdit_Roomtyp_Hotel_Buchungsdetails->setObjectName("lineEdit_Roomtyp_Hotel_Buchungsdetails");
        lineEdit_Roomtyp_Hotel_Buchungsdetails->setGeometry(QRect(100, 40, 151, 22));
        lineEdit_Stadt_Hotel_Buchungsdetails = new QLineEdit(tab_3);
        lineEdit_Stadt_Hotel_Buchungsdetails->setObjectName("lineEdit_Stadt_Hotel_Buchungsdetails");
        lineEdit_Stadt_Hotel_Buchungsdetails->setGeometry(QRect(100, 160, 151, 22));
        lineEdit_Hotel_Buchungsdetails = new QLineEdit(tab_3);
        lineEdit_Hotel_Buchungsdetails->setObjectName("lineEdit_Hotel_Buchungsdetails");
        lineEdit_Hotel_Buchungsdetails->setGeometry(QRect(100, 270, 151, 22));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../build-newPraktikum3-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/hotel.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Buchungstyp->addTab(tab_3, icon2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        label_14 = new QLabel(tab_4);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 160, 81, 16));
        label_19 = new QLabel(tab_4);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(20, 220, 61, 16));
        label_20 = new QLabel(tab_4);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(20, 290, 61, 16));
        label_21 = new QLabel(tab_4);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(20, 360, 49, 16));
        lineEdit_Bookingclass_Flug_Buchungsdetails = new QLineEdit(tab_4);
        lineEdit_Bookingclass_Flug_Buchungsdetails->setObjectName("lineEdit_Bookingclass_Flug_Buchungsdetails");
        lineEdit_Bookingclass_Flug_Buchungsdetails->setGeometry(QRect(110, 160, 151, 22));
        lineEdit_Abfahrt_Flug_Buchungsdetails = new QLineEdit(tab_4);
        lineEdit_Abfahrt_Flug_Buchungsdetails->setObjectName("lineEdit_Abfahrt_Flug_Buchungsdetails");
        lineEdit_Abfahrt_Flug_Buchungsdetails->setGeometry(QRect(110, 220, 151, 22));
        lineEdit_Ankunft_Flug_Buchungsdetails = new QLineEdit(tab_4);
        lineEdit_Ankunft_Flug_Buchungsdetails->setObjectName("lineEdit_Ankunft_Flug_Buchungsdetails");
        lineEdit_Ankunft_Flug_Buchungsdetails->setGeometry(QRect(110, 290, 151, 22));
        lineEdit_Airline_Flug_Buchungsdetails = new QLineEdit(tab_4);
        lineEdit_Airline_Flug_Buchungsdetails->setObjectName("lineEdit_Airline_Flug_Buchungsdetails");
        lineEdit_Airline_Flug_Buchungsdetails->setGeometry(QRect(110, 360, 151, 22));
        label_22 = new QLabel(tab_4);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(20, 90, 61, 16));
        label_23 = new QLabel(tab_4);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(20, 20, 49, 16));
        lineEdit_iatacodes = new QLineEdit(tab_4);
        lineEdit_iatacodes->setObjectName("lineEdit_iatacodes");
        lineEdit_iatacodes->setGeometry(QRect(110, 90, 151, 22));
        lineEdit_Flughafen_name = new QLineEdit(tab_4);
        lineEdit_Flughafen_name->setObjectName("lineEdit_Flughafen_name");
        lineEdit_Flughafen_name->setGeometry(QRect(70, 20, 291, 22));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../build-newPraktikum3-Desktop_Qt_6_5_0_MinGW_64_bit-Debug/flight.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget_Buchungstyp->addTab(tab_4, icon3, QString());
        pushButton_OK = new QPushButton(centralwidget);
        pushButton_OK->setObjectName("pushButton_OK");
        pushButton_OK->setGeometry(QRect(200, 620, 75, 24));
        Buchungsdetails->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Buchungsdetails);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 393, 22));
        Buchungsdetails->setMenuBar(menubar);
        statusbar = new QStatusBar(Buchungsdetails);
        statusbar->setObjectName("statusbar");
        Buchungsdetails->setStatusBar(statusbar);

        retranslateUi(Buchungsdetails);

        tabWidget_Buchungstyp->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Buchungsdetails);
    } // setupUi

    void retranslateUi(QMainWindow *Buchungsdetails)
    {
        Buchungsdetails->setWindowTitle(QCoreApplication::translate("Buchungsdetails", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Buchungsdetails", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("Buchungsdetails", "Preis", nullptr));
        label_3->setText(QCoreApplication::translate("Buchungsdetails", "Von", nullptr));
        label_4->setText(QCoreApplication::translate("Buchungsdetails", "Bis", nullptr));
        label_5->setText(QCoreApplication::translate("Buchungsdetails", "von", nullptr));
        label_6->setText(QCoreApplication::translate("Buchungsdetails", "Abfahrt", nullptr));
        label_7->setText(QCoreApplication::translate("Buchungsdetails", "nach", nullptr));
        label_8->setText(QCoreApplication::translate("Buchungsdetails", "Ankunft", nullptr));
        label_9->setText(QCoreApplication::translate("Buchungsdetails", "TicketTyp", nullptr));
        label_10->setText(QCoreApplication::translate("Buchungsdetails", "\303\274ber", nullptr));
        tabWidget_Buchungstyp->setTabText(tabWidget_Buchungstyp->indexOf(tab), QCoreApplication::translate("Buchungsdetails", "Zug", nullptr));
        label_15->setText(QCoreApplication::translate("Buchungsdetails", "VehicleClass", nullptr));
        label_16->setText(QCoreApplication::translate("Buchungsdetails", "Abholort", nullptr));
        label_17->setText(QCoreApplication::translate("Buchungsdetails", "R\303\274ckgabeort", nullptr));
        label_18->setText(QCoreApplication::translate("Buchungsdetails", "Unternehmen", nullptr));
        tabWidget_Buchungstyp->setTabText(tabWidget_Buchungstyp->indexOf(tab_2), QCoreApplication::translate("Buchungsdetails", "Mietwagen", nullptr));
        label_11->setText(QCoreApplication::translate("Buchungsdetails", "RoomTyp", nullptr));
        label_12->setText(QCoreApplication::translate("Buchungsdetails", "Stadt", nullptr));
        label_13->setText(QCoreApplication::translate("Buchungsdetails", "Hotel", nullptr));
        tabWidget_Buchungstyp->setTabText(tabWidget_Buchungstyp->indexOf(tab_3), QCoreApplication::translate("Buchungsdetails", "Hotel", nullptr));
        label_14->setText(QCoreApplication::translate("Buchungsdetails", "BookingClass", nullptr));
        label_19->setText(QCoreApplication::translate("Buchungsdetails", "Abfahrt in", nullptr));
        label_20->setText(QCoreApplication::translate("Buchungsdetails", "Ankunft in", nullptr));
        label_21->setText(QCoreApplication::translate("Buchungsdetails", "Airline", nullptr));
        label_22->setText(QCoreApplication::translate("Buchungsdetails", "iatacodes", nullptr));
        label_23->setText(QCoreApplication::translate("Buchungsdetails", "Name", nullptr));
        tabWidget_Buchungstyp->setTabText(tabWidget_Buchungstyp->indexOf(tab_4), QCoreApplication::translate("Buchungsdetails", "Flug", nullptr));
        pushButton_OK->setText(QCoreApplication::translate("Buchungsdetails", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Buchungsdetails: public Ui_Buchungsdetails {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUCHUNGSDETAILS_H
