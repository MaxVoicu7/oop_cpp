#include "passengerTransport.h"

// ============================= Constructors & Destructor =============================

// default constructor
PassengerTransport::PassengerTransport() : seatNumber{0}, isInternational{false}, luggageVolume{0.0f} {}

// parameterized constructor
PassengerTransport::PassengerTransport(const int seatNr, bool isInternationalValue, float luggageVolumeValue) 
	: isInternational{isInternationalValue} {
    setSeatNumber(seatNr);
    setLuggageVolume(luggageVolumeValue);   
}

// destructor
PassengerTransport::~PassengerTransport() {}



// ========================================= Setters ====================================

// checks if seatNr(argument) >= 0, if yes sets the provided value
// else sets 0 and notifies the user
void PassengerTransport::setSeatNumber(int seatNr) {
  if (seatNr <= 0) {
    cout << "INVALID VALUE FOR SEAT NUMBER!" << endl;
    seatNumber = 0;
		return;
  }
            
	seatNumber = seatNr;
}

// if the transport goes on international routes => true
// else => false
void PassengerTransport::setIsInternational(bool isInternationalValue) {
  isInternational = isInternationalValue;
}

// checks if luggageVolumeValue(argument) >= 0, if yes sets the provided value
// else sets 0 and notifies the user
void PassengerTransport::setLuggageVolume(float luggageVolumeValue) {
  if (luggageVolumeValue < 0) {
    cout << "INVALID VALUE FOR LUGGAGE VOLUME!" << endl;
    luggageVolume = 0.0f;
		return;
  }
  
	luggageVolume = luggageVolumeValue;
}



// ================================= friend functions ================================

// friend function for << operator
ostream& operator<<(ostream& os, const PassengerTransport& transport) {
  os << "Seat Number: " << transport.seatNumber << endl
     << "Is International: " << (transport.isInternational ? "Yes" : "No") << endl
     << "Luggage Volume: " << transport.luggageVolume << " cubic meters" << endl;
  return os;
}

// friend function for >> operator
istream& operator>>(istream& is, PassengerTransport& transport) {
  int seatNr;
  bool isInternationalValue;
  float luggageVolumeValue;

  cout << "Enter seat number: ";
  is >> seatNr;
  transport.setSeatNumber(seatNr);

	cout << "Is it an international transport? (1 for Yes, 0 for No): ";
	is >> isInternationalValue;
	transport.setIsInternational(isInternationalValue);

  cout << "Enter luggage volume: ";
  is >> luggageVolumeValue;
  transport.setLuggageVolume(luggageVolumeValue);

  return is;
}