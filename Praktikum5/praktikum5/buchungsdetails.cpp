#include "buchungsdetails.h"
#include "flightbooking.h"
#include "ui_buchungsdetails.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include "trainticket.h"
#include "booking.h"
#include "airport.h"
#include "travelagency.h"
#include <ostream>



Buchungsdetails::Buchungsdetails(std::shared_ptr<Booking> booking, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Buchungsdetails),
    booking(booking)




{
    ui->setupUi(this);
    ui->pushButton_OK->setEnabled(false);
    // Detailsanzeige für die ausgewählte Buchung aktualisieren
    if (std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking)) {
        QString classDescription;
        // Mapping für Flugbuchungsklassen
        if (flightBooking->getBookingClass() == "Y") {
            classDescription = "Economy";
        } else if (flightBooking->getBookingClass() == "W") {
            classDescription = "Premium Economy";
        } else if (flightBooking->getBookingClass() == "J") {
            classDescription = "Business";
        } else if (flightBooking->getBookingClass() == "F") {
            classDescription = "First";
        }
        //std::shared_ptr<Airport> newAirport;
        //ui->lineEdit_Flughafen_name->setText(QString::fromStdString(newAirport->getName()));
        ui->lineEdit_ID_Buchungsdetails->setText(QString::fromStdString(flightBooking->getId()));
        ui->doubleSpinBox_Preis_Buchungsdetails->setMaximum(9999.99);
        ui->doubleSpinBox_Preis_Buchungsdetails->setValue(flightBooking->getPrice());
        ui->dateEdit_Von_Buchungsdetails->setDate(QDate::fromString(QString::fromStdString(flightBooking->getFromDate()), "yyyyMMdd"));
        ui->dateEdit_Bis_Buchungsdetails->setDate(QDate::fromString(QString::fromStdString(flightBooking->getToDate()), "yyyyMMdd"));
        ui->lineEdit_Bookingclass_Flug_Buchungsdetails->setText(classDescription);
        ui->lineEdit_Abfahrt_Flug_Buchungsdetails->setText(QString::fromStdString(flightBooking->getFromDestination()));
        ui->lineEdit_Ankunft_Flug_Buchungsdetails->setText(QString::fromStdString(flightBooking->getToDestination()));
        ui->lineEdit_Airline_Flug_Buchungsdetails->setText(QString::fromStdString(flightBooking->getAirline()));


    } else if (std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking)) {
        QString roomTypeDescription;
        // Mapping für Hotelzimmertypen
        if (hotelBooking->getRoomType() == "EZ") {
            roomTypeDescription = "Einzelzimmer";
        } else if (hotelBooking->getRoomType() == "DZ") {
            roomTypeDescription = "Doppelzimmer";
        } else if (hotelBooking->getRoomType() == "SU") {
            roomTypeDescription = "Suite";
        } else if (hotelBooking->getRoomType() == "AP") {
            roomTypeDescription = "Appartment";
        }
        ui->lineEdit_Roomtyp_Hotel_Buchungsdetails->setText(roomTypeDescription);
        ui->lineEdit_ID_Buchungsdetails->setText(QString::fromStdString(hotelBooking->getId()));
        ui->doubleSpinBox_Preis_Buchungsdetails->setMaximum(9999.99);
        ui->doubleSpinBox_Preis_Buchungsdetails->setValue(hotelBooking->getPrice());
        ui->dateEdit_Von_Buchungsdetails->setDate(QDate::fromString(QString::fromStdString(hotelBooking->getFromDate()), "yyyyMMdd"));
        ui->dateEdit_Bis_Buchungsdetails->setDate(QDate::fromString(QString::fromStdString(hotelBooking->getToDate()), "yyyyMMdd"));
        ui->lineEdit_Hotel_Buchungsdetails->setText(QString::fromStdString(hotelBooking->getHotel()));
        ui->lineEdit_Stadt_Hotel_Buchungsdetails->setText(QString::fromStdString(hotelBooking->getTown()));


    } else if (std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
        ui->lineEdit_Vehicleclass_Car_Buchungsdetails->setText(QString::fromStdString(rentalCarBooking->getVehicleClass()));
        ui->lineEdit_ID_Buchungsdetails->setText(QString::fromStdString(rentalCarBooking->getId()));
        ui->doubleSpinBox_Preis_Buchungsdetails->setMaximum(9999.99);
        ui->doubleSpinBox_Preis_Buchungsdetails->setValue(rentalCarBooking->getPrice());
        ui->dateEdit_Von_Buchungsdetails->setDate(QDate::fromString(QString::fromStdString(rentalCarBooking->getFromDate()), "yyyyMMdd"));
        ui->dateEdit_Bis_Buchungsdetails->setDate(QDate::fromString(QString::fromStdString(rentalCarBooking->getToDate()), "yyyyMMdd"));
        ui->lineEdit_Abholort_Car__Buchungsdetails->setText(QString::fromStdString(rentalCarBooking->getPickupLocation()));
        ui->lineEdit_Ruckgabeort_Car_Buchungsdetails->setText(QString::fromStdString(rentalCarBooking->getReturnLocation()));
        ui->lineEdit_Unternehmen_Car_Buchungsdetails->setText(QString::fromStdString(rentalCarBooking->getCompany()));


    } else if (std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking)) {
        QString ticketTypeDescription;
        // Mapping für Zugtickettypen
        if (trainBooking->getTicketType() == "SSP1") {
            ticketTypeDescription = "Supersparpreis 1. Klasse";
        } else if (trainBooking->getTicketType() == "SSP2") {
            ticketTypeDescription = "Supersparpreis 2. Klasse";
        } else if (trainBooking->getTicketType() == "SP1") {
            ticketTypeDescription = "Sparpreis 1. Klasse";
        } else if (trainBooking->getTicketType() == "SP2") {
            ticketTypeDescription = "Sparpreis 2. Klasse";
        } else if (trainBooking->getTicketType() == "FP1") {
            ticketTypeDescription = "Flexpreis 1. Klasse";
        } else if (trainBooking->getTicketType() == "FP2") {
            ticketTypeDescription = "Flexpreis 2. Klasse";
        }
        ui->lineEdit_Tickettyp_Zug_Buchungsdetails->setText(ticketTypeDescription);
        ui->lineEdit_ID_Buchungsdetails->setText(QString::fromStdString(trainBooking->getId()));
        ui->doubleSpinBox_Preis_Buchungsdetails->setMaximum(9999.99);
        ui->doubleSpinBox_Preis_Buchungsdetails->setValue(trainBooking->getPrice());
        ui->dateEdit_Von_Buchungsdetails->setDate(QDate::fromString(QString::fromStdString(trainBooking->getFromDate()), "yyyyMMdd"));
        ui->dateEdit_Bis_Buchungsdetails->setDate(QDate::fromString(QString::fromStdString(trainBooking->getToDate()), "yyyyMMdd"));
        ui->lineEdit_Von_Zug_Buchungsdetails->setText(QString::fromStdString(trainBooking->getFromDestination()));
        ui->lineEdit_Nach_Zug_Buchungsdetails->setText(QString::fromStdString(trainBooking->getToDestination()));
        ui->timeEdit_Abfahrt_Zug_Buchungsdetails->setTime(QTime::fromString(QString::fromStdString(trainBooking->getDepartureTime())));
        ui->timeEdit_Ankunft_Zug_Buchungsdetails->setTime(QTime::fromString(QString::fromStdString(trainBooking->getArrivalTime())));
        // die Verbindungsbahnhöfe zur Liste hinzu
        QStringList connectingStations;
        for (const std::string& station : trainBooking->getConnectingsStations()) {
            connectingStations << QString::fromStdString(station);
        }
        ui->listWidget_Uber_Zug_Buchungsdetails->addItems(connectingStations);

    }
}

Buchungsdetails::~Buchungsdetails()
{
    delete ui;
}


void Buchungsdetails::on_pushButton_OK_clicked()
{
    emit checkSignal();
    ui->pushButton_OK->setEnabled(false);
    ui->statusbar->showMessage(" Änderungen wurden gespeichert",5000);

}

void Buchungsdetails::on_lineEdit_ID_Buchungsdetails_textEdited(const QString &arg1)
{
    booking->setId(arg1.toStdString());
    ui->pushButton_OK->setEnabled(true);
}


void Buchungsdetails::on_doubleSpinBox_Preis_Buchungsdetails_valueChanged(double arg1)
{
    booking->setPrice(arg1);
}




void Buchungsdetails::on_dateEdit_Von_Buchungsdetails_userDateChanged(const QDate &date)
{
    booking->setFromDate(date.toString("yyyyMMdd").toStdString());
}


void Buchungsdetails::on_dateEdit_Bis_Buchungsdetails_userDateChanged(const QDate &date)
{
    booking->setToDate(date.toString("yyyyMMdd").toStdString());
}



void Buchungsdetails::on_timeEdit_Abfahrt_Zug_Buchungsdetails_userTimeChanged(const QTime &time)
{
    std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking) ;
    trainBooking->setDepartureTime(time.toString().toStdString());
    //ui->pushButton_OK->setEnabled(true);


}

void Buchungsdetails::on_timeEdit_Ankunft_Zug_Buchungsdetails_userTimeChanged(const QTime &time)
{
    std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking);
    trainBooking->setArrivalTime(time.toString().toStdString());
    //ui->pushButton_OK->setEnabled(true);

}



void Buchungsdetails::on_listWidget_Uber_Zug_Buchungsdetails_currentTextChanged(const QString &currentText)
{
    std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking);
    //ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Von_Zug_Buchungsdetails_textEdited(const QString &arg1)
{
    std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking) ;
    trainBooking->setFromDestination(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Nach_Zug_Buchungsdetails_textEdited(const QString &arg1)
{    std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking);
     trainBooking->setToDestination(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Tickettyp_Zug_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking) ;
     trainBooking->setTicketType(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}

void Buchungsdetails::on_lineEdit_Vehicleclass_Car_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking) ;
     rentalCarBooking->setVehicleClass(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Abholort_Car__Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking) ;
     rentalCarBooking->setPickupLocation(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Ruckgabeort_Car_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking) ;
     rentalCarBooking->setReturnLocation(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Unternehmen_Car_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking) ;
     rentalCarBooking->setCompany(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);



}


void Buchungsdetails::on_lineEdit_Roomtyp_Hotel_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking) ;
     hotelBooking->setRoomType(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Stadt_Hotel_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking) ;
     hotelBooking->setTown(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Hotel_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking) ;
     hotelBooking->setHotel(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Bookingclass_Flug_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking) ;
     flightBooking->setBookingClass(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Abfahrt_Flug_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking) ;
     flightBooking->setFromDestination(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);
}


void Buchungsdetails::on_lineEdit_Ankunft_Flug_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking);
     flightBooking->setToDestination(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}


void Buchungsdetails::on_lineEdit_Airline_Flug_Buchungsdetails_textEdited(const QString &arg1)
{
     std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking);
     flightBooking->setAirline(arg1.toStdString());
     ui->pushButton_OK->setEnabled(true);

}





void Buchungsdetails::on_lineEdit_iatacodes_textEdited(const QString &arg1)
{
      std::string iataCode = arg1.toStdString();
     auto it = travelagency->getAirportMap().find(iataCode);
     if (it != travelagency->getAirportMap().end()) {
        // IATA-Code gefunden, zeige den zugehörigen Flughafennamen
        ui->lineEdit_Flughafen_name->setText(QString::fromStdString(it->second->getName()));
        airport->setIata_code(iataCode);
        ui->pushButton_OK->setEnabled(true);

     } else {
        // IATA-Code existiert nicht, gib eine Fehlermeldung in roter Farbe aus
        ui->lineEdit_Flughafen_name->setText("Ungültiger IATA-Code");
        ui->lineEdit_Flughafen_name->setStyleSheet("QLineEdit { color: red; }");
     }
}
