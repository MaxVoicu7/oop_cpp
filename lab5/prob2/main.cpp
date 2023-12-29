#include <iostream>
#include "transport.h"
#include "airTransport.h"
#include "passengerTransport.h"
#include "boing.h"

using std::cout;
using std::cin;
using std::endl;

// ===============================================================================================
// =                                                                                             = 
// =                                           Transport                                         =
// =                                 ______________|_______________                              =
// =                                |                             |                              =
// =                         AirTransport                PassengerTransport                      =
// =                               |_____________________________|                               =
// =                                              |                                              =
// =                                          Boing747                                           =
// =                                                                                             = 
// ===============================================================================================

int main() {

  // ===============================================================================================
  // =                                           Transport                                         =
  // ===============================================================================================

  Transport transport1;
  transport1.setType("Bus");
  transport1.setIsActive(true);
  transport1.setCapacity(50);

  cout << "Details of Transport (transport1):\n";
  transport1.displayDetails();
  cout << endl;

  Transport transport2("Train", true, 200);
    
  cout << "Details of Transport (transport2):\n";
  transport2.displayDetails();
  cout << endl;



  // ===============================================================================================
  // =                                         AirTransport                                        =
  // ===============================================================================================

  AirTransport airTransport1;
  airTransport1.setType("Commercial Jet");
  airTransport1.setIsActive(true);
  airTransport1.setCapacity(200);
  airTransport1.setMaxAltitude(35000);
  airTransport1.setEngineType("Jet Engine");
  airTransport1.setHasAutoPilot(true);

  cout << "Details of AirTransport (airTransport1):\n";
  airTransport1.displayDetails();
  cout << endl;

  AirTransport airTransport2("Private Jet", true, 10, 45000, "Turbofan", false);
    
  cout << "Details of AirTransport (airTransport2):\n";
  airTransport2.displayDetails();
  cout << endl;



  // ===============================================================================================
  // =                                      PassengerTransport                                     =
  // ===============================================================================================

  PassengerTransport passengerTransport1;
  passengerTransport1.setType("Bus");
  passengerTransport1.setIsActive(true);
  passengerTransport1.setCapacity(50);
  passengerTransport1.setSeatCapacity(50);
  passengerTransport1.setIsLuxuryClass(false);

  cout << "Details of PassengerTransport (passengerTransport1):\n";
  passengerTransport1.displayDetails();
  cout << endl;

  PassengerTransport passengerTransport2("Train", true, 200, 100, true);
    
  cout << "Details of PassengerTransport (passengerTransport2):\n";
  passengerTransport2.displayDetails();
  cout << endl;



  // ===============================================================================================
  // =                                           Boing747                                          =
  // ===============================================================================================

  Boing747 boing;
  boing.setType("Commercial Jet");
  boing.setIsActive(true);
  boing.setCapacity(300);
  boing.setMaxAltitude(35000);
  boing.setEngineType("Jet Engine");
  boing.setHasAutoPilot(true);
  boing.setSeatCapacity(250);
  boing.setIsLuxuryClass(false);
  boing.setYearOfManufacture(2020);
  boing.setCountryOfOrigin("USA");

  cout << "Details of Boing747:\n";
  boing.displayDetails();
  cout << endl;

  return 0;
}