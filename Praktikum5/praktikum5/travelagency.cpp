#include "flightbooking.h"
#include "trainticket.h"
#include "travelagency.h"
#include "hotelbooking.h"
#include "rentalcarreservation.h"
#include <iostream>
#include<string>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <iostream>
#include <stdexcept>


// Für die Verarbeitung von JSON-Dateien
#include <fstream>
#include <iostream>





TravelAgency::TravelAgency() {}

TravelAgency::~TravelAgency() {
   /* for (auto& booking : _bookings) {
        delete booking;
    }
    for (auto& travel : _travels) {
        delete travel;
    }
    for (auto& customer : _customers) {
        delete customer;
    }
 */
}

std::vector<std::shared_ptr<Booking>>TravelAgency:: getBookings(){
    return _bookings;
}
std::vector<std::shared_ptr<Customer>> TravelAgency:: getCustomers(){
    return _customers;
}
std::vector<std::shared_ptr<Travel>> TravelAgency:: getTravels(){
    return _travels;
}

TravelAgency::Map TravelAgency::getAirportMap(){
    return airportMap;
}



void TravelAgency::readFile(const QString fileName) {

    _bookings.clear();
    _travels.clear();
    _customers.clear();

    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Die JSON Datei kann nicht geöffnet werden!\n";
            return;
    }

    QByteArray fileData = file.readAll();
    QJsonParseError jsonError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData, &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        file.close();
        std::cerr << "Fehler beim Parsen der JSON-Daten: " << jsonError.errorString().toStdString() << std::endl;
        throw std::invalid_argument(jsonError.errorString().toStdString());
        return;
    }

    QJsonArray jsonData = jsonDocument.array();

    for (const QJsonValue& bookingData : jsonData) {
        QJsonObject bookingObject = bookingData.toObject();

        std::string id = bookingObject["id"].toString().toStdString();
        std::string type = bookingObject["type"].toString().toStdString();
        double price = bookingObject["price"].toDouble();
        std::string fromDate = bookingObject["fromDate"].toString().toStdString();
        std::string toDate = bookingObject["toDate"].toString().toStdString();

        std::string customerFirstname = bookingObject["customerFirstName"].toString().toStdString();
        long customerId = bookingObject["customerId"].toDouble();
        std::string customerLastname = bookingObject["customerLastName"].toString().toStdString();
        long travelId = bookingObject["travelId"].toDouble();


        // Weitere Prüfungen und Objekterstellung für customerId, customerLastname und customerFirstname
        if (customerFirstname.empty() || customerLastname.empty()) {
            qDebug() << "Unvollständige oder falsche Kundeninformationen.";
                continue;
        }


        std::shared_ptr<Customer> newCustomer = findCustomer(customerId);
        if (!newCustomer) {
                newCustomer = std::make_shared<Customer>(customerId, customerLastname, customerFirstname);
            _customers.push_back(newCustomer);
        }

        std::shared_ptr<Travel> newTravel = findTravel(travelId);
        if (!newTravel) {
            newTravel = std::make_shared<Travel>(travelId, customerId);
            _travels.push_back(newTravel);
        }

        std::shared_ptr<Booking> booking = findBooking(id);
        if(!booking){
            if (type == "Flight") {
                // Ähnlich für Flight
                std::string fromDestination = bookingObject["fromDest"].toString().toStdString();
                std::string toDestination = bookingObject["toDest"].toString().toStdString();
                std::string airline = bookingObject["airline"].toString().toStdString();
                std::string bookingClass = bookingObject["bookingClass"].toString().toStdString();
                double fromDestLatitude = bookingObject["fromDestLatitude"].toDouble();
                double fromDestLongitude = bookingObject["fromDestLongitude"].toDouble();
                double toDestLatitude = bookingObject["toDestLatitude"].toDouble();
                double toDestLongitude = bookingObject["toDestLongitude"].toDouble();


                booking = std::make_shared<FlightBooking>(id, travelId, price, fromDate, toDate,type, fromDestination, toDestination, airline, bookingClass,fromDestLatitude,fromDestLongitude,toDestLatitude,toDestLongitude);
                _bookings.push_back(booking);
                newTravel->addBooking(booking);
                newCustomer->addTravel(newTravel);
            } else if (type == "Hotel") {
                // Ähnlich für Hotel
                std::string hotel = bookingObject["hotel"].toString().toStdString();
                std::string town = bookingObject["town"].toString().toStdString();
                std::string roomType = bookingObject["roomType"].toString().toStdString();
                double hotelLatitude = bookingObject["hotelLatitude"].toDouble();
                double hotelLongitude = bookingObject["hotelLongitude"].toDouble();



                booking = std::make_shared<HotelBooking>(id, travelId, price, fromDate, toDate,type, hotel, town, roomType,hotelLatitude,hotelLongitude);
                _bookings.push_back(booking);
                newTravel->addBooking(booking);
                newCustomer->addTravel(newTravel);
            } else if (type == "RentalCar") {
                // Ähnlich für RentalCar
                std::string pickupLocation = bookingObject["pickupLocation"].toString().toStdString();
                std::string returnLocation = bookingObject["returnLocation"].toString().toStdString();
                std::string company = bookingObject["company"].toString().toStdString();
                std::string vehicleClass = bookingObject["vehicleClass"].toString().toStdString();
                double pickupLatitude = bookingObject["pickupLatitude"].toDouble();
                double pickupLongitude = bookingObject["pickupLongitude"].toDouble();
                double returnLatitude = bookingObject["returnLatitude"].toDouble();
                double returnLongitude = bookingObject["returnLongitude"].toDouble();


                booking = std::make_shared<RentalCarReservation>(id, travelId, price, fromDate, toDate,type, pickupLocation, returnLocation, company, vehicleClass,pickupLatitude,pickupLongitude,returnLatitude,returnLongitude);
                _bookings.push_back(booking);
                newTravel->addBooking(booking);
                newCustomer->addTravel(newTravel);
            } else if (type == "Train") {
                // Ähnlich für Train
                std::string fromStation = bookingObject["fromStation"].toString().toStdString();
                std::string toStation = bookingObject["toStation"].toString().toStdString();
                std::string departureTime = bookingObject["departureTime"].toString().toStdString();
                std::string arrivalTime = bookingObject["arrivalTime"].toString().toStdString();
                std::string ticketType = bookingObject["ticketType"].toString().toStdString();
                double fromStationLatitude = bookingObject["fromStationLatitude"].toDouble();
                double fromStationLongitude = bookingObject["fromStationLongitude"].toDouble();
                double toStationLatitude = bookingObject["toStationLatitude"].toDouble();
                double toStationLongitude = bookingObject["toStationLongitude"].toDouble();
                QJsonArray connectingStationsArray = bookingObject["connectingStations"].toArray();

                std::vector<std::string> connectingStations;
                for (const QJsonValue& station : connectingStationsArray) {
                    connectingStations.push_back(station.toString().toStdString());
                }

                booking = std::make_shared<TrainTicket>(id, travelId, price, fromDate, toDate,type, fromStation, toStation, departureTime, arrivalTime, ticketType,fromStationLatitude, fromStationLongitude,toStationLatitude, toStationLongitude ,connectingStations);
                _bookings.push_back(booking);
                newTravel->addBooking(booking);
                newCustomer->addTravel(newTravel);
            }
        }

    }
    for (const std::shared_ptr<Booking> &booking : _bookings) {
        if (const std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking)) {
            _flight++;
            _totalFlightPrice += flightBooking->getPrice();
        } else if (const std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
            _car++;
            _totalRentalCarPrice += rentalCarBooking->getPrice();
        } else if (const std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking)) {
            _hotel++;
            _totalHotelPrice += hotelBooking->getPrice();
        } else if  (const std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking)) {
            _totalTrainPrice += trainBooking->getPrice();
            _train++;
        }
    }

    file.close();
}


void TravelAgency:: iatacodeFile(const QString fileName){
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        std::cerr << "Die JSON Datei kann nicht geöffnet werden!\n";
            return;
    }

    QByteArray fileData = file.readAll();
    QJsonParseError jsonError;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData, &jsonError);

    if (jsonError.error != QJsonParseError::NoError) {
        file.close();
        std::cerr << "Fehler beim Parsen der JSON-Daten: " << jsonError.errorString().toStdString() << std::endl;
        throw std::invalid_argument(jsonError.errorString().toStdString());
        return;
    }

    QJsonArray jsonData = jsonDocument.array();

    for (const QJsonValue& bookingData : jsonData) {
        QJsonObject bookingObject = bookingData.toObject();

        std::string name = bookingObject["name"].toString().toStdString();
        std::string iso_country = bookingObject["iso_country"].toString().toStdString();
        std::string municipality = bookingObject["municipality"].toString().toStdString();
        std::string iata_code = bookingObject["iata_code"].toString().toStdString();

        // neues Airport-Objekt
        std::shared_ptr<Airport> newAirport = std::make_shared<Airport>(name, iso_country, municipality, iata_code);

        // das Airport-Objekt zur Map hinzufügen
        airportMap[iata_code] = newAirport;
    }



    file.close();
}


void TravelAgency::writeFile(const QString fileName) {
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        std::cerr << "Die JSON-Datei kann nicht zum Schreiben geöffnet werden!\n";
            return;
    }

    QJsonArray jsonData;

    for (const std::shared_ptr<Booking> &booking : _bookings) {
        QJsonObject bookingObject;
        bookingObject["id"] = QString::fromStdString(booking->getId());
        bookingObject["type"] = QString::fromStdString(booking->getType());
        bookingObject["price"] = QJsonValue(booking->getPrice());
        bookingObject["fromDate"] = QString::fromStdString(booking->getFromDate());
        bookingObject["toDate"] = QString::fromStdString(booking->getToDate());
        bookingObject["travelId"] = static_cast<qint64>(booking->getTravelId());

        std::shared_ptr<Travel> travel = findTravel(booking->getTravelId());
        bookingObject["customerId"] = static_cast<qint64>(travel->getCustomerId());
        std::shared_ptr<Customer> customer = findCustomer(travel->getCustomerId());
        bookingObject["customerFirstname"] = QString::fromStdString(customer->getCustomerFirstname());
        bookingObject["customerLastname"] = QString::fromStdString(customer->getCustomerLastname());


        if (const std::shared_ptr<FlightBooking> flightBooking = std::dynamic_pointer_cast<FlightBooking>(booking)) {
            bookingObject["fromDest"] = QString::fromStdString(flightBooking->getFromDestination());
            bookingObject["toDest"] = QString::fromStdString(flightBooking->getToDestination());
            bookingObject["airline"] = QString::fromStdString(flightBooking->getAirline());
            bookingObject["bookingClass"] = QString::fromStdString(flightBooking->getBookingClass());
        } else if (const std::shared_ptr<HotelBooking> hotelBooking = std::dynamic_pointer_cast<HotelBooking>(booking)) {
            bookingObject["hotel"] = QString::fromStdString(hotelBooking->getHotel());
            bookingObject["town"] = QString::fromStdString(hotelBooking->getTown());
            bookingObject["roomType"] = QString::fromStdString(hotelBooking->getRoomType());
        } else if (const std::shared_ptr<RentalCarReservation> rentalCarBooking = std::dynamic_pointer_cast<RentalCarReservation>(booking)) {
            bookingObject["pickupLocation"] = QString::fromStdString(rentalCarBooking->getPickupLocation());
            bookingObject["returnLocation"] = QString::fromStdString(rentalCarBooking->getReturnLocation());
            bookingObject["company"] = QString::fromStdString(rentalCarBooking->getCompany());
            bookingObject["vehicleClass"] = QString::fromStdString(rentalCarBooking->getVehicleClass());
        } else if (const std::shared_ptr<TrainTicket> trainBooking = std::dynamic_pointer_cast<TrainTicket>(booking)) {
            bookingObject["fromStation"] = QString::fromStdString(trainBooking->getFromDestination());
            bookingObject["toStation"] = QString::fromStdString(trainBooking->getToDestination());
            bookingObject["departureTime"] = QString::fromStdString(trainBooking->getDepartureTime());
            bookingObject["arrivalTime"] = QString::fromStdString(trainBooking->getArrivalTime());
            bookingObject["ticketType"] = QString::fromStdString(trainBooking->getTicketType());

            QJsonArray connectingStationsArray;
            for (const std::string& station : trainBooking->getConnectingsStations()) {
                connectingStationsArray.append(QString::fromStdString(station));
            }
            bookingObject["connectingStations"] = connectingStationsArray;
        }

        jsonData.append(bookingObject);
    }

    QJsonDocument jsonDocument(jsonData);
    file.write(jsonDocument.toJson());
    file.close();
}





std::string TravelAgency::showAllBookings() {
    std:: string details;
    for (auto booking : _bookings) {
        details = booking->showDetails();
    }

    return details;
}

std::shared_ptr<Booking> TravelAgency::findBooking(std::string id)const {
    for (auto booking : _bookings) {
        if (booking->getId() == id) {
            return booking;
        }
    }
    return nullptr;
}

std::shared_ptr<Travel> TravelAgency::findTravel(long id)const {
    for (auto travel : _travels) {
        if (travel->getId() == id) {
            return travel;
        }
    }
    return nullptr;
}

std::shared_ptr<Customer> TravelAgency::findCustomer(long id)const {
    for (auto customer : _customers) {
        if (customer->getId() == id) {
            return customer;
        }
    }
    return nullptr;
}

std::shared_ptr<Booking> TravelAgency::getBookingAt(int row) {

    std::shared_ptr<Travel> travel = nullptr;
    std::vector<std::shared_ptr<Booking>> booking = travel->getTravelBookings();
    if (row >= 0 && row < booking.size()) {
        return booking[row];
    } else {
        return nullptr; // Oder eine geeignete Fehlerbehandlung, wenn der Index ungültig ist
    }
}

int TravelAgency:: getZeilenummer(){
    return zeileNummer;
}
double TravelAgency:: getTotalFlightPrice(){
    return _totalFlightPrice;
}
double TravelAgency:: getTotalRentalCarPrice(){
    return _totalRentalCarPrice;
}
double TravelAgency:: getTotalHotelPrice(){
    return _totalHotelPrice;
}
double TravelAgency:: getTotalTrainPrice(){
    return _totalTrainPrice;
}
double TravelAgency:: getFlight(){
    return _flight;
}
double TravelAgency:: getCar(){
    return _car;
}
double TravelAgency:: getTrain(){
    return _train;
}
double TravelAgency:: getHotel(){
    return _hotel;
}

double TravelAgency:: getSumme(){
    _summe = _totalFlightPrice + _totalHotelPrice + _totalRentalCarPrice + _totalTrainPrice;
    return _summe;
}
