#ifndef FLIGHTBOOKING_H
#define FLIGHTBOOKING_H

#include "booking.h"
#include <string>

class FlightBooking : public Booking {
public:
    FlightBooking(std::string id, long travelId, double price, std::string fromDate, std::string toDate,std::string type,
                  std::string fromDestination, std::string toDestination, std::string airline, std::string bookingClass,
                  double fromDestLatitude, double fromDestLongitude, double toDestLatitude, double toDestLongitude);
    ~FlightBooking();
    virtual std::string showDetails() const override;

    std::string getFromDestination() const;
    std::string getToDestination() const;
    std::string getAirline() const;
    std::string getBookingClass()const;
    double getFromDestLatitude()const;
    double getFromDestLongitude()const;
    double getToDestLatitude()const;
    double getToDestLongitude()const;


    void setFromDestination( std::string fromDestination);
    void setToDestination( std::string toDestination);
    void setAirline( std::string airline);
    void setBookingClass( std::string bookingClass);

    void OriginalAttribute_Flightbooking();
    void wiederherstellen_Flightbooking();
    std::string _fromDestinationOriginal;
    std::string _toDestinationOriginal;
    std::string _airlineOriginal;
    std::string _bookingClassOriginal;



private:
    std::string _fromDestination;
    std::string _toDestination;
    std::string _airline;
    std::string _bookingClass;
    double _fromDestLatitude;
    double _fromDestLongitude;
    double _toDestLatitude;
    double _toDestLongitude;

};

#endif
