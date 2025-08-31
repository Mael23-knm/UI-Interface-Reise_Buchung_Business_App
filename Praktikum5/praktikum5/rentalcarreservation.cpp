

#include "rentalcarreservation.h"
#include <iostream>
#include <QInputDialog>
#include<string>
using namespace std;

RentalCarReservation::RentalCarReservation(std::string id, long travelId, double price, std::string fromDate, std::string toDate, string type,
                                           std::string pickupLocation, std::string returnLocation, std::string company,  std::string vehicleClass,
                                           double pickupLatitude, double pickupLongitude,double returnLatitude,double returnLongitude )
    : Booking(id,travelId, price, fromDate, toDate,type), _pickupLocation(pickupLocation), _returnLocation(returnLocation), _company(company), _vehicleClass(vehicleClass),
    _pickupLatitude(pickupLatitude), _pickupLongitude(pickupLongitude), _returnLatitude(returnLatitude), _returnLongitude(returnLongitude){}

RentalCarReservation::~RentalCarReservation(){

}

std::string RentalCarReservation::showDetails()const {
    return "* Mietwagenreservierung mit " + _company + ". Abholung am " + _fromDate + " in " + _pickupLocation
           + ". Rückgabe am " + _toDate + " in " + _returnLocation + ". Preis: " + to_string(_price) + " Euro" ;

}

std::string RentalCarReservation:: getPickupLocation() const{
    return _pickupLocation;
}
std::string RentalCarReservation:: getReturnLocation() const{
    return _returnLocation;
}

std::string RentalCarReservation:: getVehicleClass() const{
    return _vehicleClass;
}

std::string RentalCarReservation:: getCompany() const{
    return _company;
}

double RentalCarReservation:: getPickupLatitude()const{
    return _pickupLatitude;
}
double RentalCarReservation:: getPickupLongitude()const{
    return _pickupLongitude;
}
double RentalCarReservation:: getReturnLatitude()const{
    return _returnLatitude;
}
double RentalCarReservation:: getReturnLongitude()const{
    return _returnLongitude;
}





void RentalCarReservation:: setPickupLocation(std::string pickupLocation){
    _pickupLocation = pickupLocation;
}
void RentalCarReservation:: setReturnLocation(std::string returnLocation){
    _returnLocation = returnLocation;
}
void RentalCarReservation:: setCompany(std::string company){
    _company = company;
}
void RentalCarReservation:: setVehicleClass(std::string vehicleClass){
    _vehicleClass = vehicleClass;
}

void RentalCarReservation:: OriginalAttribute_RentalCarReservation(){
_pickupLocationOriginal = _pickupLocation ;
_returnLocationOriginal = _returnLocation;
_companyOriginal = _company;
_vehicleClassOriginal = _vehicleClass;
}

void RentalCarReservation:: wiederherstellen_RentalCarReservation(){
_pickupLocation = _pickupLocationOriginal ;
_returnLocation = _returnLocationOriginal;
_company = _companyOriginal;
_vehicleClass = _vehicleClassOriginal;
}
