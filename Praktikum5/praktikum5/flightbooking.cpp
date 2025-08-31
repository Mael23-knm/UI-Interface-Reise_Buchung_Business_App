#include "flightbooking.h"

FlightBooking::FlightBooking(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string type,
                             std::string fromDestination, std::string toDestination, std::string airline, std::string bookingClass,
                              double fromDestLatitude, double fromDestLongitude, double toDestLatitude, double toDestLongitude)
    : Booking(id, travelId, price, fromDate, toDate,type),
    _fromDestination(fromDestination),
    _toDestination(toDestination),
    _airline(airline),
    _bookingClass(bookingClass),
    _fromDestLatitude(fromDestLatitude),
    _fromDestLongitude(fromDestLongitude),
    _toDestLatitude(toDestLatitude),
    _toDestLongitude(toDestLongitude){}

FlightBooking::~FlightBooking(){

}

std::string FlightBooking::showDetails() const {
    return "* Flugbuchung von " + _fromDestination + " nach " + _toDestination + " mit " + _airline +
           " am " + _fromDate + ". Preis: " + std::to_string(_price) + " Euro";
}

std::string FlightBooking::getFromDestination() const {
    return _fromDestination;
}

std::string FlightBooking::getToDestination() const {
    return _toDestination;
}

std::string FlightBooking::getAirline() const {
    return _airline;
}

std::string FlightBooking:: getBookingClass()const{
    return _bookingClass;
}
double FlightBooking:: getFromDestLatitude()const{
    return _fromDestLatitude;
}
double FlightBooking:: getFromDestLongitude()const{
    return _fromDestLongitude;
}
double FlightBooking:: getToDestLatitude()const{
    return _toDestLatitude;
}
double FlightBooking:: getToDestLongitude()const{
    return _toDestLongitude;
}




void FlightBooking:: setFromDestination( std::string fromDestination){
    _fromDestination = fromDestination;
}
void FlightBooking:: setToDestination( std::string toDestination){
    _toDestination = toDestination;
}
void FlightBooking:: setAirline( std::string airline){
    _airline = airline;
}
void FlightBooking:: setBookingClass( std::string bookingClass){
    _bookingClass = bookingClass;
}


void FlightBooking:: OriginalAttribute_Flightbooking(){
 _fromDestinationOriginal = _fromDestination;
 _toDestinationOriginal = _toDestination;
 _airlineOriginal = _airline;
_bookingClassOriginal = _bookingClass;
}

void FlightBooking:: wiederherstellen_Flightbooking(){
_fromDestination = _fromDestinationOriginal;
_toDestination = _toDestinationOriginal;
_airline = _airlineOriginal;
_bookingClass = _bookingClassOriginal;
}
