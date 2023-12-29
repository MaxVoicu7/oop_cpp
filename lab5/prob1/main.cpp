#include <iostream>
#include "boing.h"

using std::cout;
using std::cin;
using std::endl;

// ===============================================================================================
// =                                                                                             = 
// =                         AirTransport                PassengerTransport                      =
// =                               |_____________________________|                               =
// =                                              |                                              =
// =                                          Boing747                                           =
// =                                                                                             = 
// ===============================================================================================

int main() {
  
  // ===============================================================================================
  // =                                         AirTransport                                        =
  // ===============================================================================================

  AirTransport transport1a;
  cout << "Initial state of transport1:\n" << transport1a << endl;

  transport1a.setIsPassengerAircraft(true);
  transport1a.setFuelCapacity(5000);
  transport1a.setRegistrationNumber("ABC12345");
  transport1a.setWeight(10000.5);

  cout << "Updated state of transport1:\n" << transport1a << endl;

  AirTransport transport2a(true, 4500, "XYZ67890", 9500.0);
  cout << "State of transport2:\n" << transport2a << endl;

  AirTransport transport3a;
  cout << "Enter details for a new air transport:\n";
  cin >> transport3a;
  cout << "State of newly entered transport:\n" << transport3a << endl;



  // ===============================================================================================
  // =                                      PassengerTransport                                     =
  // ===============================================================================================

  PassengerTransport transport1b;
  cout << "Initial state of transport1:\n" << transport1b << endl;

  transport1b.setSeatNumber(120);
  transport1b.setIsInternational(true);
  transport1b.setLuggageVolume(30.5);

  cout << "Updated state of transport1:\n" << transport1b << endl;

  PassengerTransport transport2b(200, false, 50.0);
  cout << "State of transport2:\n" << transport2b << endl;

  PassengerTransport transport3b;
  cout << "Enter details for a new passenger transport:\n";
  cin >> transport3b;
  cout << "State of newly entered transport:\n" << transport3b << endl;



  // ===============================================================================================
  // =                                           Boing747                                          =
  // ===============================================================================================

  Boing747 boing1;
  cout << "Initial state of Boing747 (boing1):\n" << boing1 << endl;

  boing1.setIsPassengerAircraft(true);
  boing1.setFuelCapacity(10000);
  boing1.setRegistrationNumber("BOING123");
  boing1.setWeight(50000.0);
  boing1.setSeatNumber(300);
  boing1.setIsInternational(true);
  boing1.setLuggageVolume(2000.0);
  boing1.setIsInOperation(true);
  boing1.setAirlineCompany("Boing Airlines");

  cout << "Updated state of Boing747 (boing1):\n" << boing1 << endl;

  Boing747 boing2(true, 9500, "XYZ999", 45000.0, 250, false, 1500.0, false, "Global Air");
  cout << "State of Boing747 (boing2):\n" << boing2 << endl;

  Boing747 boing3;
  cout << "Enter details for a new Boing747:\n";
  cin >> boing3;
  cout << "State of newly entered Boing747 (boing3):\n" << boing3 << endl;

  return 0;
}