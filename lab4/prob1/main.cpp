#include <iostream>
#include "building.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

// ===========================================================================================================
// =                                           Building class                                                =
// ===========================================================================================================

  Building building1;
  cout << "Building1 (implicit constructor): " << endl << building1 << endl;

  building1.setConstructionYear(2000);
  building1.setNrFloors(10);
  building1.setSurface(2000);
  building1.setAddress("Decebal 10");
  cout << "Building1 (after setting values): " << endl << building1 << endl;

  Building building2(1990, 5, 1500.25, "Burebista 13");
  cout << "Building2 (parametrized constructor): " << endl << building2 << endl;

  building2.renovateBuilding(2020, 6, 1600);
  cout << "Building2 (after renovation): " << endl << building2 << endl;

  Building building3;
  building3 = building2;
  cout << "Building3 (after assignment from building2): " << endl << building3 << endl;

  Building building4(building1);
  cout << "Building4 (copy constructor from building1): " << endl << building4 << endl;

  cout << "Surface per floor for building1: " << building1.surfacePerFloor() << endl;
  cout << "Surface per floor for building2: " << building2.surfacePerFloor() << endl << endl;

  Building building5;
  cout << "Enter data for a new building: " << endl;
  cin >> building5;
  cout << "Building5 (user input): " << endl << building5 << endl;




// ===========================================================================================================
// =                                     Administrative Building class                                       =
// ===========================================================================================================

  AdministrativeBuilding adminBuilding1;
  cout << "AdminBuilding1 (implicit constructor): " << endl << adminBuilding1 << endl;

  adminBuilding1.setNrOffices(20);
  adminBuilding1.setNrEmployees(100);
  adminBuilding1.setNrCompanies(5);
  adminBuilding1.setRentPricePerOffice(500.0f);
  adminBuilding1.setParkingSpace(true);
  bool days[7] = {true, true, true, true, true, false, false};
  adminBuilding1.setOperationalDays(days);
  adminBuilding1.setOpeningHour("08:00");
  adminBuilding1.setClosingHour("18:00");
  cout << "AdminBuilding1 (after setting values): " << endl << adminBuilding1 << endl;

  AdministrativeBuilding adminBuilding2(adminBuilding1);
  cout << "AdminBuilding2 (copy constructor from AdminBuilding1): " << endl << adminBuilding2 << endl;

  AdministrativeBuilding adminBuilding3;
  adminBuilding3 = adminBuilding2;
  cout << "AdminBuilding3 (after assignment from AdminBuilding2): " << endl << adminBuilding3 << endl;

  adminBuilding3.setNrOffices(15);
  adminBuilding3.setNrEmployees(50);
  cout << "AdminBuilding3 (after modifications): " << endl << adminBuilding3 << endl;

  adminBuilding3.displayOperationalSchedule();

  cout << "Total rent income for AdminBuilding3: " << adminBuilding3.calculateTotalRentIncome() << endl << endl;

  AdministrativeBuilding adminBuilding4;
  cout << "Enter data for a new administrative building: " << endl;
  cin >> adminBuilding4;
  cout << "AdminBuilding4 (user input): " << endl << adminBuilding4 << endl;





// ===========================================================================================================
// =                                        Residential Building class                                       =
// ===========================================================================================================

  ResidentialBuilding rb1;
  cout << "ResidentialBuilding rb1 (implicit constructor):" << endl << rb1 << endl;

  rb1.setConstructionYear(2005);
  rb1.setNrFloors(8);
  rb1.setSurface(1500.5);
  rb1.setAddress("Bulevardul Moscova 4");
  rb1.setNrApartments(40);
  rb1.setNrResidents(100);
  rb1.setHasElevator(true);
  rb1.setHasUndergroundParking(true);
  cout << "ResidentialBuilding rb1 (after setting values):" << endl << rb1 << endl;

  ResidentialBuilding rb2(1995, 5, 1200, "Kiev 14", 25, 60, false, false);
  cout << "ResidentialBuilding rb2 (parametrized constructor):" << endl << rb2 << endl;

  ResidentialBuilding rb3;
  rb3 = rb2;
  cout << "ResidentialBuilding rb3 (after assignment from rb2):" << endl << rb3 << endl;

  ResidentialBuilding rb4(rb1);
  cout << "ResidentialBuilding rb4 (copy constructor from rb1):" << endl << rb4 << endl;

  ResidentialBuilding rb5;
  cout << "Enter data for a new residential building:" << endl;
  cin >> rb5;
  cout << "ResidentialBuilding rb5 (user input):" << endl << rb5 << endl;

  return 0;
}