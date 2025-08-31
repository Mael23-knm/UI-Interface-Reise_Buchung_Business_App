#ifndef BUCHUNGSDETAILS_H
#define BUCHUNGSDETAILS_H

#include "booking.h"
#include "travelagency.h"
#include <QMainWindow>

namespace Ui {
class Buchungsdetails;
}

class Buchungsdetails : public QMainWindow
{
    Q_OBJECT

public:
    explicit Buchungsdetails(std::shared_ptr<Booking> booking, QWidget *parent = nullptr);
    ~Buchungsdetails();
signals:
  void checkSignal();

private slots:



    void on_pushButton_OK_clicked();


    void on_dateEdit_Von_Buchungsdetails_userDateChanged(const QDate &date);

    void on_dateEdit_Bis_Buchungsdetails_userDateChanged(const QDate &date);

    void on_timeEdit_Abfahrt_Zug_Buchungsdetails_userTimeChanged(const QTime &time);

    void on_timeEdit_Ankunft_Zug_Buchungsdetails_userTimeChanged(const QTime &time);

    void on_listWidget_Uber_Zug_Buchungsdetails_currentTextChanged(const QString &currentText);

    void on_lineEdit_Von_Zug_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Nach_Zug_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Tickettyp_Zug_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Vehicleclass_Car_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_ID_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Abholort_Car__Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Ruckgabeort_Car_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Unternehmen_Car_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Roomtyp_Hotel_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Stadt_Hotel_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Hotel_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Bookingclass_Flug_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Abfahrt_Flug_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Ankunft_Flug_Buchungsdetails_textEdited(const QString &arg1);

    void on_lineEdit_Airline_Flug_Buchungsdetails_textEdited(const QString &arg1);

    void on_doubleSpinBox_Preis_Buchungsdetails_valueChanged(double arg1);



    void on_lineEdit_iatacodes_textEdited(const QString &arg1);

private:
    Ui::Buchungsdetails *ui;
    std::shared_ptr<Booking> booking;
    std::shared_ptr<Airport> airport;
    std::shared_ptr<TravelAgency> travelagency = nullptr;


};

#endif // BUCHUNGSDETAILS_H
