#include "passengerTransport.h"

// ========================= CONSTRUCTORS AND DESTRUCTOR ===========================

// default constructor
PassengerTransport::PassengerTransport() : Transport(), seatCapacity{0}, isLuxuryClass{false} {}

// parameterized constructor
PassengerTransport::PassengerTransport(const string& typeValue, bool isActiveValue, int capacityValue,
                                       int seatCapacityValue, bool isLuxuryValue)
  : Transport(typeValue, isActiveValue, capacityValue), seatCapacity{seatCapacityValue}, isLuxuryClass{isLuxuryValue} {}

// destructor
PassengerTransport::~PassengerTransport() {}



// =============================== SETTERS ================================== 

// checking the seat capacity, if value negative, setting 0
void PassengerTransport::setSeatCapacity(int seatCapacityValue) {
  if (seatCapacityValue < 0) {
    cout << "INVALID SEAT CAPACITY VALUE. SETTING TO 0." << endl;
    seatCapacity = 0;
    return;
  }
            
  seatCapacity = seatCapacityValue;
}

// setting to true if the plane has luxuryClass, otherwise false
void PassengerTransport::setIsLuxuryClass(bool isLuxuryValue) {
  isLuxuryClass = isLuxuryValue;
}



// =============================== DISPLAY FUNCTION ==================================

// method that displays the info about the passanger Transport
void PassengerTransport::displayDetails(bool showBaseDetails) const {
  if (showBaseDetails) 
    Transport::displayDetails();
  
  cout << "Seat Capacity: " << seatCapacity << ", "
       << "Luxury Class: " << (isLuxuryClass ? "Yes" : "No") << endl;
}