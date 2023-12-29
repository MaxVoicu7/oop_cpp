#include <iostream>
#include <string>
#include "AirTransport.h"
#include "PassengerTransport.h"

#ifndef BOING_H
#define BOING_H

using std::string;
using std::cout;
using std::endl;

class Boing747 : public AirTransport, public PassengerTransport {
  private:
    int yearOfManufacture;
    string countryOfOrigin;

  public:
    // constructor
    Boing747();

    // destructor
    ~Boing747();

    // setters
    void setYearOfManufacture(const int yearValue);
    void setCountryOfOrigin(const string& country);

    // display function
    void displayDetails() const;
};

#endif