#ifndef TRAVELAGENCYUI_H
#define TRAVELAGENCYUI_H

#include "buchungsdetails.h"
#include "check.h"
#include "flightbooking.h"
#include "hotelbooking.h"
#include "qmessagebox.h"
#include "rentalcarreservation.h"
#include "trainticket.h"
#include "travelagency.h"
#include <QMainWindow>

#include <QGraphicsScene>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDesktopServices>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>

namespace Ui {
class TravelAgencyUI;
}

class TravelAgencyUI : public QMainWindow{
    Q_OBJECT

public:
    explicit TravelAgencyUI( std::shared_ptr<TravelAgency> travelagency, QWidget *parent = nullptr);
    ~TravelAgencyUI();
    std::string getTravel_LatestEndDate(const std::shared_ptr<Travel> travel) const;
    std::string getTravel_EarliestStartDate(const std::shared_ptr<Travel> travel) const;

    void showRentalCarOnMap(const std::shared_ptr<RentalCarReservation>& rentalCarBooking);
    void showFlightOnMap(const std::shared_ptr<FlightBooking> &flightBooking);
    void showHotelOnMap(const std::shared_ptr<HotelBooking>& hotelBooking);
    void showTrainOnMap(const std::shared_ptr<TrainTicket>& trainBooking);

    //void showMap(const std::shared_ptr<Booking> &booking);



private slots:


    void on_actionDatei_einlesen_triggered();
    void on_actionSuche_triggered();
    void on_actionSpeichern_triggered();
    void on_action_iatacodes_einlesen_triggered();

    void on_tableWidget_Reisen_cellDoubleClicked(int row, int column);
    void on_tableWidget_Buchungen_cellDoubleClicked(int row, int column);

    void slotCheck();








private:


    std::shared_ptr<TravelAgency> travelagency = nullptr;
    std::shared_ptr<Booking> booking;
    std::shared_ptr<Buchungsdetails> buchungsdetails = nullptr;
    Ui::TravelAgencyUI *ui;
    std::vector<std::shared_ptr<Booking>> buchungen;
    Check check;

};

#endif // TRAVELAGENCYUI_H
