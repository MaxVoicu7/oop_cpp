#include "transport.h"

// ========================= CONSTRUCTORS AND DESTRUCTOR ===========================

// default constructor
Transport::Transport() : type{"Unknown"}, isActive{false}, capacity{0} {}

// parameterized constructor
Transport::Transport(const string& typeValue, bool isActiveValue, int capacityValue)
  : type{typeValue}, isActive{isActiveValue}, capacity{capacityValue} {}

// destructor
Transport::~Transport() {}



// =============================== SETTERS ================================== 

// setting the type of the transport, like aerian or marin
void Transport::setType(const string& typeValue) {
  type = typeValue;
}

// setting to true if the transport is active, otherwise false
void Transport::setIsActive(const bool isActiveValue) {
  isActive = isActiveValue;
}

// setting the capacity of the transport
void Transport::setCapacity(const int capacityValue) {
  if (capacityValue < 0) {
    cout << "INVALID CAPACITY VALUE. SETTING TO 0." << endl;
    capacity = 0;
    return;
  }  
            
  capacity = capacityValue;
}



// =============================== METHODS ==================================

// method that updates the capacity of the transport
void Transport::updateCapacity(int change) {
  if (capacity + change >= 0) 
    capacity += change;
  else
    capacity += 0;
}

// method that sets the transport to active
void Transport::activate() {
  isActive = true;
}

// methods that deactivates the transport
void Transport::deactivate() {
  isActive = false;
}



// =============================== DISPLAY FUNCTION ==================================

// method that displays the info about the transport
void Transport::displayDetails() const {
  cout << "This transport is of type '" 
       << type << "' and has a capacity of " 
       << capacity << " units. It is currently " 
       << (isActive ? "active." : "inactive.") << endl;
}