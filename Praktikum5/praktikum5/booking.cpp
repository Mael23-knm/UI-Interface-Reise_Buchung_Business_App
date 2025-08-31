#include "booking.h"

Booking::Booking(std::string id, long travelId, double price, std::string fromDate, std::string toDate,std::string type)
    : _id(id), _travelId(travelId), _price(price), _fromDate(fromDate), _toDate(toDate),_type(type) {}

Booking::~Booking() {}

double Booking::getPrice() const {
    return _price;
}

std::string Booking::getId() const {
    return _id;
}

std::string Booking::getFromDate() const {
    return _fromDate;
}

std::string Booking::getToDate() const {
    return _toDate;
}

long Booking:: getTravelId()const{
    return _travelId;
}
std::string Booking:: getType()const{
    return _type;
}



void Booking:: setId(std::string id){
    _id = id;
}
void Booking:: setTravelId(long travelId){
    _travelId = travelId;
}
void Booking:: setPrice( double price){
    _price = price;
}
void Booking:: setFromDate(std::string fromDate){
    _fromDate = fromDate;
}
void Booking:: setToDate(std::string toDate){
    _toDate = toDate;
}

void Booking:: OriginalAttribute_booking(){
    _idOrigrinal = _id;
    _travelIdOrigrinal = _travelId;
    _priceOrigrinal = _price;
    _fromDateOrigrinal = _fromDate;
    _toDateOrigrinal = _toDate;

}

void Booking:: wiederherstellen_booking(){
    _id = _idOrigrinal;
    _travelId = _travelIdOrigrinal;
    _price = _priceOrigrinal;
    _fromDate = _fromDateOrigrinal;
    _toDate = _toDateOrigrinal;
}
