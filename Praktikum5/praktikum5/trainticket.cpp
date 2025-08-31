

#include "trainticket.h"
#include <iostream>
#include <QInputDialog>
#include<string>


TrainTicket::TrainTicket(std::string id, long travelId, double price, std::string fromDate, std::string toDate, std::string type, std::string fromDestination, std::string toDestination,
                         std::string departureTime, std::string arrivalTime, std::string ticketType, double fromStationLatitude, double fromStationLongitude, double toStationLatitude, double toStationLongitude , std::vector<std::string> connectingStations)
    : Booking(id,travelId, price, fromDate, toDate, type), _fromDestination(fromDestination), _toDestination(toDestination),
    _departureTime(departureTime), _arrivalTime(arrivalTime), _ticketType(ticketType),  _fromStationLatitude(fromStationLatitude),
    _fromStationLongitude(fromStationLongitude), _toStationLatitude(toStationLatitude), _toStationLongitude(toStationLongitude), _connectingStations(connectingStations){}
TrainTicket::~TrainTicket(){

}

std::string TrainTicket::showDetails()const {
    std::string connections;
    for (const std::string& station : _connectingStations) {
        connections = station;
    }
    return "* Zugticket von " + _fromDestination + " nach " + _toDestination + " am " + _fromDate + " von "
           +  _departureTime +  " bis " + _arrivalTime + ". Preis: " + std::to_string(_price) +  " Euro"
           + "Verbindungsbahnhoefe: " + connections ;

}

std::string TrainTicket:: getFromDestination() const{
    return _fromDestination;
}

std::string TrainTicket:: getToDestination() const{
    return _toDestination;
}

std::vector<std::string> TrainTicket:: getConnectingsStations() const{
    return _connectingStations;
}

std::string TrainTicket:: getTicketType() const{
    return _ticketType;
}

std::string TrainTicket:: getDepartureTime() const{
    return _departureTime;
}
std::string TrainTicket:: getArrivalTime() const{
    return _arrivalTime;
}

double TrainTicket:: getFromStationLatitude()const{
    return _fromStationLatitude;
}
double TrainTicket:: getFromStationLongitude()const{
    return _fromStationLongitude;
}
double TrainTicket:: getToStationLatitude()const{
    return _toStationLatitude;
}
double TrainTicket:: getToStationLongitude()const{
    return _toStationLongitude;
}
double TrainTicket:: getLatitude()const{
    return _latitude;
}
double TrainTicket:: getLongitude()const{
    return _longitude;
}
std::string TrainTicket:: getStationName()const{
    return _stationName;
}






void TrainTicket:: setFromDestination(std::string fromDestination){
    _fromDestination = fromDestination;
}
void TrainTicket:: setToDestination(std::string toDestination){
    _toDestination = toDestination;
}
void TrainTicket:: setDepartureTime(std::string departureTime){
    _departureTime = departureTime;
}
void TrainTicket:: setArrivalTime(std::string arrivalTime){
    _arrivalTime = arrivalTime;
}
void TrainTicket:: setTicketType(std::string ticketType){
    _ticketType = ticketType;
}


void TrainTicket:: OriginalAttribute_TrainTicket(){
_fromDestinationOriginal = _fromDestination;
_toDestinationOriginal = _toDestination;
_departureTimeOriginal = _departureTime;
_arrivalTimeOriginal = _arrivalTime;
_ticketTypeOriginal = _ticketType;
}

void TrainTicket:: wiederherstellen_TrainTicket(){
_fromDestination = _fromDestinationOriginal;
_toDestination = _toDestinationOriginal;
_departureTime = _departureTimeOriginal;
_arrivalTime = _arrivalTimeOriginal;
_ticketType = _ticketTypeOriginal;
}
