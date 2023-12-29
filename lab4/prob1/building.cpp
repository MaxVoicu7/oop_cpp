#include "building.h"





// ===========================================================================================================
// =                                           Building class                                                =
// ===========================================================================================================



// ================ constructors and destructor ==================

// default constructor, everything initialized with default values
Building::Building() : constructionYear {}, nrFloors {1}, surface {0.0}, address {nullptr} {};

// paratemerized constructor, sets the values given as parameters
Building::Building(const int yearValue, const int floorsValue, const float surfaceValue, const char* addressValue)
  : constructionYear {yearValue}, surface {surfaceValue}, nrFloors {floorsValue}, address {nullptr} {
    setAddress(addressValue);
}

// copy constructor, sets the values from other Building object
Building::Building(const Building &otherBuilding) {
  constructionYear = otherBuilding.constructionYear;
  nrFloors = otherBuilding.nrFloors;
  surface = otherBuilding.surface;

  if (otherBuilding.address) {
    address = new char[std::strlen(otherBuilding.address) + 1];
    std::strcpy(address, otherBuilding.address);
  } else
    address = nullptr;
}

// destructor
Building::~Building() {
  delete[] address;
}



// ================= setters =====================

// setting the construction Year, checkinf if the values is between 1799 and 2024
void Building::setConstructionYear(const int constructionYearValue) {
  if (constructionYearValue > 1799 && constructionYearValue < 2024)
    constructionYear = constructionYearValue;
  else {
    cout << "INCORRECT CONSTRUCTION YEAR VALUE" << endl;
    constructionYear = 0;
  }
}

// setting the number of floors, checking if the value is between 0 and 1001
void Building::setNrFloors(const int nrFloorsValue) {
  if (nrFloorsValue > 0 && nrFloorsValue < 1001)
    nrFloors = nrFloorsValue;
  else {
    cout << "INCORRECT NUMBER OF FLOORS VALUE" << endl;
    nrFloors = 0;
  }
}

// setting the surface, checking if the values is greater than 0
void Building::setSurface(const float surfaceValue) {
  if (surfaceValue > 0)
    surface = surfaceValue;
  else {
    cout << "INCORRECT SURFACE VALUE" << endl;
    surface = 0;
  }
}

// setting the address, dealocate the memory if necessary and alocate new memmory
void Building::setAddress(const char* newAddress) {
  if (newAddress) {
    char* temp = new char[std::strlen(newAddress) + 1];
    std::strcpy(temp, newAddress);

    if (address) 
      delete[] address;
    
    address = temp;
  } else {
    if (address) {
      delete[] address;
      address = nullptr;
    }
  }
}



// ================= member functions =====================

// returns the surface per floor
float Building::surfacePerFloor() const {
  return surface / nrFloors;
}

// modifies some of the parameters that describes building
void Building::renovateBuilding(const int renovationYear, int newNrFloors = 1, float newSurface = 0.0) {
  if (renovationYear > constructionYear) {
    constructionYear = renovationYear;

    // if value not provided, number of floors stays the same
    if (newNrFloors > 1)
      nrFloors = newNrFloors;

    // if value not provided, surface stays the same
    if (newSurface > 0.0)
      surface = newSurface;

    cout << "Building was renovated in " <<  renovationYear << endl;
  } else
    cout << "RENOVATION YEAR SHOULD BE GREATER THAN CONSTRUCTION YEAR" << endl;
}



// ================= operators overloading =====================

// << operator overload
std::ostream& operator<<(std::ostream &os, const Building &b) {
  os << "Construction year: " << b.constructionYear << endl
     << "Surface: " << b.surface << endl
     << "Number of floors: " << b.nrFloors << endl
     << "Address: ";

  if (b.address != nullptr)
    os << b.address;
  else
    os << "Address not available";
  
  os << endl;
  
  return os;
}

// >> operator overload
std::istream& operator>>(std::istream &is, Building &b) {
  cout << "Enter the construction year of the building: ";
  is >> b.constructionYear;
  cout << "Enter the surface of the building: ";
  is >> b.surface;
  cout << "Enter the number of the floors: ";
  is >> b.nrFloors;

  cout << "Enter the address of the building: ";
  is.ignore();
  char tempAddress[256];
  is.getline(tempAddress, 256);

  b.setAddress(tempAddress);

  return is;
}

// = operator overload
Building& Building::operator=(const Building& otherBuilding) {
  if (this != &otherBuilding) {
    setConstructionYear(otherBuilding.constructionYear);
    setNrFloors(otherBuilding.nrFloors);
    setSurface(otherBuilding.surface);
    setAddress(otherBuilding.address);
  }

  return *this;
}





// ===========================================================================================================
// =                                     Administrative Building class                                       =
// ===========================================================================================================



// ================ constructors and destructor ==================

// default constructor
AdministrativeBuilding::AdministrativeBuilding() 
  : Building(), nrOffices(0), nrEmployees(0), nrCompanies(0), rentPricePerOffice(0.0), parkingSpace(false) {

    // initially working days considered from monday to friday
    for (int i = 0; i < 7; ++i) 
      operationalDays[i] = (i < 5);
        
    strcpy(openingHour, "08:00");
    strcpy(closingHour, "18:00");
}

// copy constructor
AdministrativeBuilding::AdministrativeBuilding(const AdministrativeBuilding &other) 
  : Building(other),
    nrOffices(other.nrOffices), 
    nrEmployees(other.nrEmployees), 
    nrCompanies(other.nrCompanies), 
    rentPricePerOffice(other.rentPricePerOffice),
    parkingSpace(other.parkingSpace) {
       

      for (int i = 0; i < 7; ++i) 
        operationalDays[i] = other.operationalDays[i];
 
      strcpy(openingHour, other.openingHour);
      strcpy(closingHour, other.closingHour);
}

// destructor
AdministrativeBuilding::~AdministrativeBuilding() {}



// ================= setters =====================

// setting the opening hour after validation
void AdministrativeBuilding::setOpeningHour(const char* hour) {
  if (isValidTimeFormat(hour))
    strcpy(openingHour, hour);
  else {
    cout << "INVALID TIME FORMAT FOR OPENING HOUR" << endl;
    strcpy(openingHour, "08:00");
  }
}

// setting the closing hour after validation
void AdministrativeBuilding::setClosingHour(const char* hour) {
  if (isValidTimeFormat(hour)) 
    strcpy(closingHour, hour);
  else {
    cout << "INVALID TIME FORMAT FOR CLOSING HOUR" << endl;
    strcpy(closingHour, "08:00");
  }
}

// setting the number of offices to a value >= 0
void AdministrativeBuilding::setNrOffices(int offices) {
  if (offices >= 0) 
    nrOffices = offices;
  else {
    cout << "INVALID NUMBER OF OFFICES VALUE" << endl;
    nrOffices = 0;
  }
}

// setting the number of employees to a value >= 0
void AdministrativeBuilding::setNrEmployees(int employees) {
  if (employees >= 0) 
    nrEmployees = employees;
  else {
    cout << "INVALID NUMBER OF EMPLOYEES VALUE" << endl;
    nrEmployees = 0;
  }
}

// setting the number of companies to a value >= 0
void AdministrativeBuilding::setNrCompanies(int companies) {
  if (companies >= 0) 
    nrCompanies = companies;
  else {
    cout << "INVALID NUMBER OF COMPANIES VALUE" << endl;
    nrCompanies = 0;
  }
}

// setting the number of companies to a value >= 0
void AdministrativeBuilding::setRentPricePerOffice(float price) {
  if (price >= 0.0) 
    rentPricePerOffice = price;
  else {
    cout << "INVALID RENT PRICE VALUE" << endl;
    nrCompanies = 0;
  }
}

// sets the parkingSpace value
void AdministrativeBuilding::setParkingSpace(bool hasParking) {
  parkingSpace = hasParking;
}

// setts the operational days. 0 = Monday, if true, then building works
void AdministrativeBuilding::setOperationalDays(const bool days[7]) {
  for (int i = 0; i < 7; ++i) 
    operationalDays[i] = days[i];
}



// ====================== member functions =========================

// checks if the provided time string is in a valid form
bool AdministrativeBuilding::isValidTimeFormat(const char* time) {
  return std::strlen(time) == 5 && time[2] == ':'
    && isdigit(time[0]) && isdigit(time[1])
    && isdigit(time[3]) && isdigit(time[4]);
}

// returns the rent income
float AdministrativeBuilding::calculateTotalRentIncome() const {
  return nrOffices * rentPricePerOffice;
}

// displays the working schedule of the building
void AdministrativeBuilding::displayOperationalSchedule() const {
  const char* daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
  cout << "Operational Schedule:" << endl;
  for (int i = 0; i < 7; ++i) {
    cout << daysOfWeek[i] << ": " << (operationalDays[i] ? "Open" : "Closed");
    
    if (operationalDays[i]) 
      cout << " (Hours: " << openingHour << " - " << closingHour << ")";
        
    cout << endl;
  }
}



// ================= operators overloading =====================

// << operator overload
std::ostream& operator<<(std::ostream &os, const AdministrativeBuilding &ab) {

  os << static_cast<const Building&>(ab);

  os << "Number of offices: " << ab.nrOffices << endl
     << "Number of employees: " << ab.nrEmployees << endl
     << "Number of companies: " << ab.nrCompanies << endl
     << "Rent price per office: " << ab.rentPricePerOffice << endl
     << "Parking space: " << (ab.parkingSpace ? "Yes" : "No") << endl
     << "Opening hours: " << ab.openingHour << " - " << ab.closingHour << endl;

  os << "Operational days: ";
  const char* daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  for (int i = 0; i < 7; ++i) 
    os << daysOfWeek[i] << ": " << (ab.operationalDays[i] ? "Yes" : "No") << " ";
    
  os << endl;

  return os;
}

// >> operator overload
std::istream& operator>>(std::istream &is, AdministrativeBuilding &ab) {
  is >> static_cast<Building&>(ab);

  cout << "Enter the number of offices: ";
  is >> ab.nrOffices;

  cout << "Enter the number of employees: ";
  is >> ab.nrEmployees;

  cout << "Enter the number of companies: ";
  is >> ab.nrCompanies;

  cout << "Enter the rent price per office: ";
  is >> ab.rentPricePerOffice;

  cout << "Is there parking space? (1 for Yes, 0 for No): ";
  is >> ab.parkingSpace;

  cout << "Enter opening hour (HH:MM): ";
  is.ignore();
  is.getline(ab.openingHour, 6);

  cout << "Enter closing hour (HH:MM): ";
  is.getline(ab.closingHour, 6);

  const char* daysOfWeek[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  for (int i = 0; i < 7; ++i) {
    cout << "Is the building operational on " << daysOfWeek[i] << "? (1 for Yes, 0 for No): ";
    is >> ab.operationalDays[i];
  }

  return is;
}

// = operator overload
AdministrativeBuilding &AdministrativeBuilding::operator=(const AdministrativeBuilding& other) {
  if (this != &other) {
    Building::operator=(other);

    nrOffices = other.nrOffices;
    nrEmployees = other.nrEmployees;
    nrCompanies = other.nrCompanies;
    rentPricePerOffice = other.rentPricePerOffice;
    parkingSpace = other.parkingSpace;

    for (int i = 0; i < 7; ++i) 
      operationalDays[i] = other.operationalDays[i];

    strncpy(openingHour, other.openingHour, sizeof(openingHour) - 1);
    openingHour[sizeof(openingHour) - 1] = '\0';

    strncpy(closingHour, other.closingHour, sizeof(closingHour) - 1);
    closingHour[sizeof(closingHour) - 1] = '\0';
  }

  return *this;
}





// ===========================================================================================================
// =                                        Residential Building class                                       =
// ===========================================================================================================



// ================ constructors and destructor ==================

// default constructor
ResidentialBuilding::ResidentialBuilding() 
  : Building(), nrApartments(0), nrResidents(0), hasElevator(false), hasUndergroundParking(false) {}

// parameterized constructor
ResidentialBuilding::ResidentialBuilding(const int yearValue, const int floorsValue, const float surfaceValue, const char* addressValue, 
                                         int nrApartmentsValue, int nrResidentsValue, bool hasElevatorValue, bool hasUndergroundParkingValue) 
  : Building(yearValue, floorsValue, surfaceValue, addressValue), 
    nrApartments(nrApartmentsValue), nrResidents(nrResidentsValue), 
    hasElevator(hasElevatorValue), hasUndergroundParking(hasUndergroundParkingValue) {}

// copy constructor
ResidentialBuilding::ResidentialBuilding(const ResidentialBuilding &other) 
  : Building(other), nrApartments(other.nrApartments), nrResidents(other.nrResidents), 
    hasElevator(other.hasElevator), hasUndergroundParking(other.hasUndergroundParking) {}

// destructor
ResidentialBuilding::~ResidentialBuilding() {}



// ================= setters =====================

// setting the number of apartments
void ResidentialBuilding::setNrApartments(int nrApartmentsValue) {
  if (nrApartmentsValue >= 0)
    nrApartments = nrApartmentsValue;
  else {
    nrApartments = 0;
    cout << "INVALID NUMBER OF APARTMENTS VALUE" << endl;
  }
}

// setting the number of residents
void ResidentialBuilding::setNrResidents(int nrResidentsValue) {
  if (nrResidentsValue >= 0) 
    nrResidents = nrResidentsValue;
  else {
    nrResidentsValue = 0;
    cout << "INVALID NUMBER OF RESIDENTS VALUE" << endl;
  }
}

// setting if the building has an elevator
void ResidentialBuilding::setHasElevator(bool hasElevatorValue) {
  hasElevator = hasElevatorValue;
}

// setting ig the building has an underground parking
void ResidentialBuilding::setHasUndergroundParking(bool hasUndergroundParkingValue) {
  hasUndergroundParking = hasUndergroundParkingValue;
}



// ================= operators overloading =====================

// << overload
std::ostream& operator<<(std::ostream &os, const ResidentialBuilding &rb) {
  os << static_cast<const Building&>(rb);

  os << "Number of Apartments: " << rb.nrApartments << endl
     << "Number of Residents: " << rb.nrResidents << endl
     << "Has Elevator: " << (rb.hasElevator ? "Yes" : "No") << endl
     << "Has Underground Parking: " << (rb.hasUndergroundParking ? "Yes" : "No") << endl;

  return os;
}

// >> overload
std::istream& operator>>(std::istream &is, ResidentialBuilding &rb) {
  is >> static_cast<Building&>(rb);

  cout << "Enter the number of apartments: ";
  is >> rb.nrApartments;
  cout << "Enter the number of residents: ";
  is >> rb.nrResidents;
  cout << "Does it have an elevator? (1 for Yes, 0 for No): ";
  is >> rb.hasElevator;
  cout << "Does it have underground parking? (1 for Yes, 0 for No): ";
  is >> rb.hasUndergroundParking;

    return is;
}

// = overload
ResidentialBuilding& ResidentialBuilding::operator=(const ResidentialBuilding& other) {
  if (this != &other) {
    Building::operator=(other);

    nrApartments = other.nrApartments;
    nrResidents = other.nrResidents;
    hasElevator = other.hasElevator;
    hasUndergroundParking = other.hasUndergroundParking;
  }

  return *this;
}