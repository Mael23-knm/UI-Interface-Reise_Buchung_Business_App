#include "hotelbooking.h"

HotelBooking::HotelBooking(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string type,
                           std::string hotel, std::string town, std::string roomType, double hotelLatitude, double hotelLongitude)
    : Booking(id, travelId, price, fromDate, toDate,type),
    _hotel(hotel),
    _town(town),
    _roomType(roomType),
    _hotelLatitude(hotelLatitude),
    _hotelLongitude(hotelLongitude){}

HotelBooking::~HotelBooking(){

}

std::string HotelBooking::showDetails() const {
    return "* Hotelbuchung im Hotel " + _hotel + " in " + _town + " vom " + _fromDate + " bis " + _toDate +
           ". Zimmer: " + _roomType + ". Preis: " + std::to_string(_price) + " Euro";
}

std::string HotelBooking::getHotel() const {
    return _hotel;
}

std::string HotelBooking::getTown() const {
    return _town;
}

std::string HotelBooking:: getRoomType()const{
    return _roomType;
}

double HotelBooking:: getHotelLatitude()const{
    return _hotelLatitude;
}
double HotelBooking:: getHotelLongitude()const{
    return _hotelLongitude;
}


void HotelBooking:: setHotel(std::string hotel){
    _hotel = hotel;
}
void HotelBooking:: setTown(std::string town){
    _town = town;
}
void HotelBooking:: setRoomType(std::string roomtype){
    _roomType = roomtype;
}


void HotelBooking:: OriginalAttribute_Hotelbooking(){
_hotelOriginal = _hotel;
_townOriginal = _town;
_roomTypeOriginal = _roomType;
}

void HotelBooking:: wiederherstellen_Hotelbooking(){
_hotel = _hotelOriginal;
_town = _townOriginal;
_roomType = _roomTypeOriginal;
}
