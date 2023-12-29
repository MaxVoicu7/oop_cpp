#include <iostream>
#include <string>
#include "Transport.h"

#ifndef PASSENGER_TRANSPORT_H
#define PASSENGER_TRANSPORT_H

using std::string;
using std::cout;
using std::endl;

class PassengerTransport : virtual public Transport {
  private:
    int seatCapacity;
    bool isLuxuryClass;

public:
    // constructors
    PassengerTransport();
    PassengerTransport(const string& typeValue, bool isActiveValue, int capacityValue,
                       int seatCapacityValue, bool isLuxuryValue);

    // destructor
    virtual ~PassengerTransport();

    // setters
    void setSeatCapacity(int seatCapacityValue);
    void setIsLuxuryClass(bool isLuxuryValue);

    // Metoda de afișare a detaliilor
    void displayDetails(bool showBaseDetails = true) const;
};

#endif