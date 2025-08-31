
#include "airport.h"

Airport::Airport(std::string name, std::string iso_country, std::string municipality,std::string iata_code):
_name(name), _iso_country(iso_country), _municipality(municipality), _iata_code(iata_code)
{}

Airport::~Airport(){}

std::string Airport:: getName()const{
    return _name;
}
std::string Airport:: getIso_country()const{
    return _iso_country;
}
std::string Airport:: getMunicipality()const{
    return _municipality;
}
std::string Airport:: getIata_code()const{
    return _iata_code;
}


void Airport:: setIata_code(std::string iata_code){
    _iata_code = iata_code;
}
