#include "boing.h"

// ========================= CONSTRUCTORS AND DESTRUCTOR ===========================

// default constructor
Boing747::Boing747() : AirTransport(), PassengerTransport(), yearOfManufacture{0}, countryOfOrigin{"Unknown"} {}

// destructor
Boing747::~Boing747() {}



// =============================== SETTERS ================================== 

// if year of manufacture < 1903, sets 1903 and announces
void Boing747::setYearOfManufacture(const int yearValue) {
  if (yearValue < 1903) {
    cout << "INVALID YEAR OF MANUFACTURE VALUE. SETTING TO 1903." << endl;
    yearOfManufacture = 1903;
    return;
  }
            
  yearOfManufacture = yearValue;
}

// sets the country of origin
void Boing747::setCountryOfOrigin(const string& country) {
  countryOfOrigin = country;
}



// =============================== DISPLAY FUNCTION ==================================

// method that displays the info about the Boing
void Boing747::displayDetails() const {
  AirTransport::displayDetails(); 
  PassengerTransport::displayDetails(false);
  
  cout << "Year of Manufacture: " << yearOfManufacture << ", "
       << "Country of Origin: " << countryOfOrigin << endl;
}
