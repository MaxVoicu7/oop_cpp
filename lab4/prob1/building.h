#include <iostream>
#include <cstring>

using std::cout;
using std::endl;
using std::cin;





// ===========================================================================================================
// =                                           HIERARCHY OF CLASSES                                          =
// ===========================================================================================================

//                                                   Building
//                                        ______________|_______________
//                                       |                             |
//                          Adminstrative Building          Residential Building





// ===========================================================================================================
// =                                           Building class                                                =
// ===========================================================================================================



class Building {
  private:
    int constructionYear;
    float surface;
    int nrFloors;
    char* address;

  public:
    // ========== constructors ============
    Building();
    Building(const Building &otherBuilding);
    Building(const int yearValue, const int floorsValue, const float surfaceValue, const char* addressValue);

    // ========== destructor ==============
    ~Building();

    // ========== operators ==============
    Building& operator=(const Building& otherBuilding);

    // ========== member functions ==============
    float surfacePerFloor() const;
    void renovateBuilding(const int renovationYear, int newNrFloors, float newSurface);

    // ============= setters =============
    void setConstructionYear(int);
    void setNrFloors(int);
    void setSurface(float);
    void setAddress(const char* addressValue);

    // ============= << and >> =============
    friend std::ostream& operator<<(std::ostream &os, const Building &b);
    friend std::istream& operator>>(std::istream &is, Building &b);
};





// ===========================================================================================================
// =                                     Administrative Building class                                       =
// ===========================================================================================================



class AdministrativeBuilding : public Building {
  private:
    int nrOffices;
    int nrEmployees;
    int nrCompanies;
    float rentPricePerOffice;
    bool parkingSpace;
    bool operationalDays[7];
    char openingHour[6];
    char closingHour[6];

  public:
    // ========== constructors ============
    AdministrativeBuilding();
    AdministrativeBuilding(const AdministrativeBuilding &other);

    // ========== destructor ==============
    ~AdministrativeBuilding();

    // ============= setters =============
    void setOpeningHour(const char* hour);
    void setClosingHour(const char* hour);
    void setNrOffices(int offices);
    void setNrEmployees(int employees);
    void setNrCompanies(int companies);
    void setRentPricePerOffice(float price);
    void setParkingSpace(bool hasParking);
    void setOperationalDays(const bool days[7]);

    // ========== member functions ==============
    bool isValidTimeFormat(const char* time);
    float calculateTotalRentIncome() const;
    void displayOperationalSchedule() const;

    // ========== operators ==============
    AdministrativeBuilding& operator=(const AdministrativeBuilding& other);

    // ============= << and >> =============
    friend std::ostream& operator<<(std::ostream &os, const AdministrativeBuilding &ab);
    friend std::istream& operator>>(std::istream &is, AdministrativeBuilding &ab);
};





// ===========================================================================================================
// =                                        Residential Building class                                       =
// ===========================================================================================================



class ResidentialBuilding : public Building {
  private:
    int nrApartments;
    int nrResidents;
    bool hasElevator;
    bool hasUndergroundParking;

  public:
    // ========== constructors ============
    ResidentialBuilding();
    ResidentialBuilding(const ResidentialBuilding &other);
    ResidentialBuilding(const int yearValue, const int floorsValue, const float surfaceValue, const char* addressValue, 
                        int nrApartmentsValue, int nrResidentsValue, bool hasElevatorValue, bool hasUndergroundParkingValue);

    // ========== destructor ==============
    ~ResidentialBuilding();

    // ============= setters =============
    void setNrApartments(int apartments);
    void setNrResidents(int residents);
    void setHasElevator(bool elevator);
    void setHasUndergroundParking(bool parking);

    // ========== operators ==============
    ResidentialBuilding& operator=(const ResidentialBuilding& other);

    // ============= << and >> =============
    friend std::ostream& operator<<(std::ostream &os, const ResidentialBuilding &rb);
    friend std::istream& operator>>(std::istream &is, ResidentialBuilding &rb);
};