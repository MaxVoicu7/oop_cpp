#include "airTransport.h"

// ========================= CONSTRUCTORS AND DESTRUCTOR ===========================

// default constructor
AirTransport::AirTransport() : Transport(), maxAltitude{0}, engineType{"Unknown"}, hasAutoPilot{false} {}

// parameterized constructor
AirTransport::AirTransport(const string& typeValue, bool isActiveValue, int capacityValue,
                           int maxAltValue, const string& engineTypeValue, bool hasAutoPilotValue)
  : Transport(typeValue, isActiveValue, capacityValue), 
    maxAltitude{maxAltValue}, engineType{engineTypeValue}, hasAutoPilot{hasAutoPilotValue} {}

// destructor
AirTransport::~AirTransport() {}



// =============================== SETTERS ================================== 

// checking the altitude, if value negative, setting 0
void AirTransport::setMaxAltitude(const int altitudeValue) {
  if (altitudeValue < 0) {
    cout << "INVALID ALTITUDE VALUE. SETTING TO 0." << endl;
    maxAltitude = 0;
    return;
  }
            
  maxAltitude = altitudeValue;
}

// setting the engine of the air transport
void AirTransport::setEngineType(const string& typeValue) {
  engineType = typeValue;
}

// setting to true if the plane has autoPilot, otherwise false
void AirTransport::setHasAutoPilot(const bool hasAutoPilotValue) {
  hasAutoPilot = hasAutoPilotValue;
}



// =============================== DISPLAY FUNCTION ==================================

// method that displays the info about the plane
void AirTransport::displayDetails() const {
  Transport::displayDetails();
  
  cout << "Max Altitude: " << maxAltitude << " meters, "
       << "Engine Type: " << engineType << ", "
       << "Auto Pilot: " << (hasAutoPilot ? "Yes" : "No") << endl;
}