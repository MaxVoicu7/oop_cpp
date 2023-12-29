#include <iostream>
#include <string>
#include "transport.h"

#ifndef AIR_TRANSPORT_H
#define AIR_TRANSPORT_H

using std::string;
using std::cout;
using std::endl;

class AirTransport : virtual public Transport {
  private:
    int maxAltitude;
    string engineType;       
    bool hasAutoPilot;

  public:
    // constructors
    AirTransport();
    AirTransport(const string& typeValue, const bool isActiveValue, const int capacityValue,
                 const int maxAltValue, const string& engineTypeValue, const bool hasAutoPilotValue);

    // destructor
    virtual ~AirTransport();

    // setters
    void setMaxAltitude(const int maxAltValue);
    void setEngineType(const string& typeValue);
    void setHasAutoPilot(const bool hasAutoPilotValue);

    // display function
    void displayDetails() const;
};

#endif 