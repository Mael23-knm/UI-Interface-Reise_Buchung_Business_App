#ifndef BOOKING_H
#define BOOKING_H

#include <string>



class Booking {
public:
    Booking(std::string id, long travelId, double price, std::string fromDate, std::string toDate,std::string type);
    virtual ~Booking();
    virtual std::string showDetails() const = 0;

    double getPrice() const;
    std::string getId() const;
    std::string getFromDate() const;
    std::string getToDate() const;
    std::string getType()const;
    long getTravelId()const;

    void setId(std::string id);
    void setTravelId(long travelId);
    void setPrice( double price);
    void setFromDate(std::string fromDate);
    void setToDate(std::string toDate);


    void OriginalAttribute_booking();
    void wiederherstellen_booking();
    std::string _idOrigrinal;
    long _travelIdOrigrinal;
    double _priceOrigrinal;
    std::string _fromDateOrigrinal;
    std::string _toDateOrigrinal;




protected:
    std::string _id;
    long _travelId;
    double _price;
    std::string _fromDate;
    std::string _toDate;
    std::string _type;


};

#endif
