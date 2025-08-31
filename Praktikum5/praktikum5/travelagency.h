

#ifndef TRAVELAGENCY_H
#define TRAVELAGENCY_H

#include <string>
#include <vector>
#include "booking.h"
#include "customer.h"
#include "qobject.h"
#include "travel.h"
#include "airport.h"
#include <QString>
#include <QMap>

class TravelAgency {

public:
    TravelAgency();
    ~TravelAgency();

    using Map = std::map<std::string, std::shared_ptr<Airport>>;

    void readFile(const QString fileName);
    void writeFile(const QString fileName);
    void iatacodeFile(const QString fileName);
    std::string showAllBookings();
    double getTotalFlightPrice();
    double getTotalRentalCarPrice();
    double getTotalHotelPrice();
    double getTotalTrainPrice();
    double getFlight();
    double getCar();
    double getTrain();
    double getHotel();
    double getSumme();
    int getZeilenummer();
    std::vector<std::shared_ptr<Booking>> getBookings();
    std::vector<std::shared_ptr<Customer>> getCustomers();
    std::vector<std::shared_ptr<Travel>> getTravels();
    std::shared_ptr<Booking> getBookingAt(int row);

    Map getAirportMap();

    std::shared_ptr<Booking> findBooking(std::string id)const;
    std::shared_ptr<Travel> findTravel(long id)const;
    std::shared_ptr<Customer> findCustomer(long id)const;



private:
    std::vector<std::shared_ptr<Booking>> _bookings;
    std::vector<std::shared_ptr<Customer>> _customers;
    std::vector<std::shared_ptr<Travel>> _travels;
    int zeileNummer = 0;
    double _totalFlightPrice = 0.0;
    double _totalRentalCarPrice = 0.0;
    double _totalHotelPrice = 0.0;
    double _totalTrainPrice = 0.0;
    double _summe = 0.0;
    int _flight = 0, _car = 0, _train=0, _hotel=0;

    Map airportMap;
    Map::iterator it;




};

#endif
