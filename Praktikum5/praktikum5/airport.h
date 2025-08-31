

#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

class Airport
{
public:
    Airport(std::string name, std::string iso_country, std::string municipality,std::string iata_code  );

    ~Airport();
    std::string getName()const;
    std::string getIso_country()const;
    std::string getMunicipality()const;
    std::string getIata_code()const;

    void setIata_code(std::string iata_code);

private:
    std::string _name;
    std::string _iso_country;
    std::string _municipality;
    std::string _iata_code;
};

#endif // AIRPORT_H
