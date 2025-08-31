

#ifndef RENTALCARRESERVATION_H
#define RENTALCARRESERVATION_H

#include "booking.h"
#include <string>

class RentalCarReservation : public Booking {
public:
    RentalCarReservation(std::string id,long travelId, double price, std::string fromDate, std::string toDate,std::string type,
                         std::string pickupLocation, std::string returnLocation, std::string company, std::string vehicleClass,
                         double pickupLatitude, double pickupLongitude,double returnLatitude,double returnLongitude );
    ~RentalCarReservation();
    virtual std::string showDetails()const override;

    std::string getPickupLocation()const;
    std::string getReturnLocation()const;
    std::string getCompany()const;
    std::string getVehicleClass()const;
    double getPickupLatitude()const;
    double getPickupLongitude()const;
    double getReturnLatitude()const;
    double getReturnLongitude()const;

    void setPickupLocation(std::string pickupLocation);
    void setReturnLocation(std::string returnLocation);
    void setCompany(std::string company);
    void setVehicleClass(std::string vehicleClass);

    void OriginalAttribute_RentalCarReservation();
    void wiederherstellen_RentalCarReservation();
    std::string _pickupLocationOriginal;
    std::string _returnLocationOriginal;
    std::string _companyOriginal;
    std::string _vehicleClassOriginal;


private:
    std::string _pickupLocation;
    std::string _returnLocation;
    std::string _company;
    std::string _vehicleClass;
    double _pickupLatitude;
    double _pickupLongitude;
    double _returnLatitude;
    double _returnLongitude;
};

#endif
