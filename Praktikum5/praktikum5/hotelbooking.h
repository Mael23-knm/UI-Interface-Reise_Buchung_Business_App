#ifndef HOTELBOOKING_H
#define HOTELBOOKING_H

#include "booking.h"
#include <string>

class HotelBooking : public Booking {
public:
    HotelBooking(std::string id, long travelId, double price, std::string fromDate, std::string toDate,std::string type,
                 std::string hotel, std::string town, std::string roomType, double hotelLatitude, double hotelLongitude );
    ~HotelBooking();
    virtual std::string showDetails() const override;

    std::string getHotel() const;
    std::string getTown() const;
    std::string getRoomType()const;
    double getHotelLatitude()const;
    double getHotelLongitude()const;

    void setHotel(std::string hotel);
    void setTown(std::string town);
    void setRoomType(std::string roomtype);

    void OriginalAttribute_Hotelbooking();
    void wiederherstellen_Hotelbooking();
    std::string _hotelOriginal;
    std::string _townOriginal;
    std::string _roomTypeOriginal;


private:
    std::string _hotel;
    std::string _town;
    std::string _roomType;
    double _hotelLatitude;
    double _hotelLongitude;
};

#endif
