

#ifndef TRAINTICKET_H
#define TRAINTICKET_H

#include "booking.h"
#include <string>
#include <vector>

class TrainTicket : public Booking {
public:
    TrainTicket(std::string id, long travelId, double price, std::string fromDate, std::string toDate,std::string type, std::string fromDestination, std::string toDestination,
                std::string departureTime, std::string arrivalTime,  std::string ticketType , double fromStationLatitude, double fromStationLongitude, double toStationLatitude,
                double toStationLongitude,std::vector<std::string> connectingStations
               );
    ~TrainTicket();
    virtual std::string showDetails()const override;

    std::string getFromDestination()const;
    std::string getToDestination()const;
    std::vector<std::string> getConnectingsStations()const;
    std::string getTicketType()const;
    std::string getDepartureTime()const;
    std::string getArrivalTime()const;
    double getFromStationLatitude()const;
    double getFromStationLongitude()const;
    double getToStationLatitude()const;
    double getToStationLongitude()const;
    double getLatitude()const;
    double getLongitude()const;
    std::string getStationName()const;

    void setFromDestination(std::string fromDestination);
    void setToDestination(std::string toDestination);
    void setDepartureTime(std::string departureTime);
    void setArrivalTime(std::string arrivalTime);
    void setTicketType(std::string ticketType);

    void OriginalAttribute_TrainTicket();
    void wiederherstellen_TrainTicket();
    std::string _fromDestinationOriginal;
    std::string _toDestinationOriginal;
    std::string _departureTimeOriginal;
    std::string _arrivalTimeOriginal;
    std::string _ticketTypeOriginal;






private:
    std::string _fromDestination;
    std::string _toDestination;
    std::string _departureTime;
    std::string _arrivalTime;
    std::string _ticketType;
    double _fromStationLatitude;
    double _fromStationLongitude;
    double _toStationLatitude;
    double _toStationLongitude;
    double _latitude;
    double _longitude;
    std::string _stationName;
    std::vector<std::string> _connectingStations;
};

#endif
