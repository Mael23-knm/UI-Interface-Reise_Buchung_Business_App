#include "customer.h"

Customer::Customer(long id, std::string lastName, std::string firstName)
    : _id(id), _lastName(lastName), _firstName(firstName) {}

Customer::~Customer(){

}

void Customer::addTravel(std::shared_ptr<Travel> travel) {
    _travelList.push_back(travel);
}

long Customer::getId() const {
    return _id;
}

std::vector<std::shared_ptr<Travel>> Customer::getTravelList() const {
    return _travelList;
}

std::string Customer:: getCustomerLastname() const{
    return _lastName;
}
std::string Customer:: getCustomerFirstname() const{
    return _firstName;
}
