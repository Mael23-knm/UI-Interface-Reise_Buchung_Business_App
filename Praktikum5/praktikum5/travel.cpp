
#include "travel.h"

Travel::Travel(long id, long customerId): _id(id), _customerId(customerId)
{

}
Travel::Travel(){

}

Travel::~Travel(){

}

void Travel:: addBooking (std::shared_ptr<Booking> booking){
    _travelBookings.push_back(booking);
}

long Travel:: getId()const {
    return _id;
}

std::vector<std::shared_ptr<Booking>> Travel:: getTravelBookings()const{
    return _travelBookings;
}

long Travel:: getCustomerId() const{
    return _customerId;
}


bool Travel:: überlappen(const std::shared_ptr<Travel>& other) const{
    const auto& myBookings = getTravelBookings();
    const auto& otherBookings = other->getTravelBookings();

    for (const auto& myBooking : myBookings) {
        for (const auto& otherBooking : otherBookings) {
            if (bookingsÜberlappen(myBooking, otherBooking)) {
                return true;
            }
        }
    }

    return false;
}
bool Travel:: bookingsÜberlappen(const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) const {
    // Start- und Enddaten der Buchungen abrufen
    const std::string& myFromDate = booking1->getFromDate();
    const std::string& myToDate = booking1->getToDate();
    const std::string& otherFromDate = booking2->getFromDate();
    const std::string& otherToDate = booking2->getToDate();

    // Überlappung prüfen
    if (myFromDate <= otherToDate && myToDate >= otherFromDate) {
        // Überlappung gefunden
        return true;
    }

    return false;
}
