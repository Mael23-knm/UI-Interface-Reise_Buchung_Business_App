// check.h

#ifndef CHECK_H
#define CHECK_H

#include "travelagency.h"

class Check
{
public:
    Check(std::shared_ptr<TravelAgency> travelagency);
     bool checkTravelsDisjunct(QString& message);

     bool operator()();

private:
    std::shared_ptr<TravelAgency> travelagency;


};

#endif // CHECK_H
