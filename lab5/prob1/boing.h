#include <string>
#include <iostream>
#include "AirTransport.h"
#include "PassengerTransport.h"

using std::string;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

class Boing747 : public AirTransport, public PassengerTransport {
  private:
    bool isInOperation;
    string airlineCompany;

  public:
    // constructors
    Boing747();
    Boing747(bool isForPassengers, int fuelCapacity, const string& regNumber, float weight, int seatNr, 
             bool isInternational, float luggageVolume, bool inOperation, const string& company);

    // destructor
    ~Boing747();

    // setters
    void setIsInOperation(bool inOperation);
    void setAirlineCompany(const string& company);

    // friend functions for >> and <<
    friend ostream& operator<<(ostream& os, const Boing747& boing);
    friend istream& operator>>(istream& is, Boing747& boing);
};