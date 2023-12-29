#include "AirTransport.h"

// ============================= Constructors & Destructor =============================

// default constructor
AirTransport::AirTransport() : isPassangerAircraft{false}, fuelCapacity{0}, registrationNumber{"Unknown"}, weight{0.0f} {}

// parameterized constructor
AirTransport::AirTransport(const bool isForPassangers, const int fuelCapacityValue, const string regNrValue, const float weightValue)
  : isPassangerAircraft{isForPassangers} {
    setFuelCapacity(fuelCapacityValue);      
    setRegistrationNumber(regNrValue);          
    setWeight(weightValue);                     
}

// destructor
AirTransport::~AirTransport() {}



// ========================================= Setters ====================================

// if the aircraft can transport passengers => true
// else => false
void AirTransport::setIsPassengerAircraft(const bool isForPassengers) {
  isPassangerAircraft = isForPassengers;
}

// checks if fuelCapacityValue(argument) >= 0, if yes sets the provided value
// else sets 0 and notifies the user
void AirTransport::setFuelCapacity(const int fuelCapacityValue) {
  if (fuelCapacityValue <= 0) {
    cout << "INVALID VALUE FOR FUEL CAPACITY!" << endl;
    fuelCapacity = 0;
    return;
  }

  fuelCapacity = fuelCapacityValue;
}

// checks if the length of the regNumberValue(argument) == 8, if yes sets the provided value
// else sets Unknown and notifies the user
void AirTransport::setRegistrationNumber(const string &regNumberValue) {
  if (regNumberValue.length() != 8) {
    cout << "INVALID REGISTRATION NUMBER!" << endl;
    registrationNumber = "Unknown";
    return;
  }

  registrationNumber = regNumberValue;
}

// checks if weightValue(argument) >= 0, if yes sets the provided value
// else sets 0 and notifies the user
void AirTransport::setWeight(const float weightValue) {
  if (weightValue <= 0) {
    cout << "INVALID VALUE FOR WEIGHT!" << endl;
    weight = 0.0f;
    return;
  }

  weight = weightValue;
}



// ================================= friend functions ================================

// friend function for << operator
ostream& operator<<(ostream& os, const AirTransport& plane) {
  os << "Passenger Aircraft: " << (plane.isPassangerAircraft ? "Yes" : "No") << endl
     << "Fuel Capacity: " << plane.fuelCapacity << endl
     << "Registration Number: " << plane.registrationNumber << endl
     << "Weight: " << plane.weight << endl;
  return os;
}

// friend function for >> operator
istream& operator>>(istream& is, AirTransport& plane) {
  bool isForPassengers;
  int fuelCapacityValue;
  string regNumberValue;
  float weightValue;

  cout << "Enter if it's a passenger aircraft (1 for Yes, 0 for No): ";
  is >> isForPassengers;
  plane.setIsPassengerAircraft(isForPassengers);

  cout << "Enter fuel capacity: ";
  is >> fuelCapacityValue;
  plane.setFuelCapacity(fuelCapacityValue);

  cout << "Enter registration number: ";
  is >> regNumberValue;
  plane.setRegistrationNumber(regNumberValue);

  cout << "Enter weight: ";
  is >> weightValue;
  plane.setWeight(weightValue);

  return is;
}