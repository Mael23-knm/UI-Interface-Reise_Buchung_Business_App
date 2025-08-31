#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "travel.h"
#include <memory>
#include <string>
#include <vector>

class Customer {
public:
    Customer(long id, std::string lastName, std::string firstName);
    ~Customer();
    void addTravel(std::shared_ptr<Travel> travel);
    long getId() const;
    std::string getCustomerLastname()const;
    std::string getCustomerFirstname()const;
    std::vector<std::shared_ptr<Travel>> getTravelList() const;

private:
    long _id;
    std::string _lastName;
    std::string _firstName;
    std::vector<std::shared_ptr<Travel>> _travelList;
};

#endif
