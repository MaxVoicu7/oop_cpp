#include "boing.h"

// ============================= Constructors & Destructor =============================

// default constructor
Boing747::Boing747() : AirTransport(), PassengerTransport(), isInOperation{false}, airlineCompany{"Unknown"} {}

// parameterized constructor
Boing747::Boing747(bool isForPassengers, int fuelCapacity, const string& regNumber, float weight, int seatNr, 
                   bool isInternational, float luggageVolume, bool inOperation, const string& company)
  : AirTransport(isForPassengers, fuelCapacity, regNumber, weight),
    PassengerTransport(seatNr, isInternational, luggageVolume),
    isInOperation{inOperation}, airlineCompany{company} {}

// destructor
Boing747::~Boing747() {}



// ========================================= Setters ====================================

// if the boing is used => true
// else => false
void Boing747::setIsInOperation(bool inOperation) {
  isInOperation = inOperation;
}

// sets the value for the airlineCompany
void Boing747::setAirlineCompany(const string& company) {
  airlineCompany = company;
}



// ================================= friend functions ================================

// friend function for << operator
ostream& operator<<(ostream& os, const Boing747& boing) {
  os << static_cast<const AirTransport&>(boing)
     << static_cast<const PassengerTransport&>(boing)
     << "Is In Operation: " << (boing.isInOperation ? "Yes" : "No") << endl
     << "Airline Company: " << boing.airlineCompany << endl;

  return os;
}

// friend function for >> operator
istream& operator>>(istream& is, Boing747& boing) {
  is >> static_cast<AirTransport&>(boing)
     >> static_cast<PassengerTransport&>(boing);

  cout << "Enter if the aircraft is in operation (1 for Yes, 0 for No): ";
  is >> boing.isInOperation;

  cout << "Enter the airline company: ";
  is >> boing.airlineCompany;

  return is;
}