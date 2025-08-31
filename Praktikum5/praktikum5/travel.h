
#ifndef TRAVEL_H
#define TRAVEL_H

#include "booking.h"
#include <memory>
#include <vector>

class Travel
{
public:
    Travel();
    Travel(long id, long customerId);
    ~Travel();
    void addBooking (std::shared_ptr<Booking> booking);
    long getId()const;
    long getCustomerId()const;
    std::vector<std::shared_ptr<Booking>> getTravelBookings()const;

    bool überlappen(const std::shared_ptr<Travel>& other) const;
    bool bookingsÜberlappen(const std::shared_ptr<Booking>& booking1, const std::shared_ptr<Booking>& booking2) const ;

private:
    long _id;
    long _customerId;
    std::vector<std::shared_ptr<Booking>> _travelBookings;
};


#endif // TRAVEL_H
