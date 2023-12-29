#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class AirTransport {
  private:
    bool isPassangerAircraft;
    int fuelCapacity;
    string registrationNumber;
    float weight;

  public:
    // constructors
    AirTransport();
    AirTransport(const bool isForPassangers, const int fuelCapacityValue, const string regNumberValue, const float weightValue);
    
    // destructor 
    ~AirTransport();

    // setters
    void setIsPassengerAircraft(const bool isForPassengers);
    void setFuelCapacity(const int fuelCapacityValue);
    void setRegistrationNumber(const string& regNumberValue);
    void setWeight(const float weightValue);

    // Friend functions for >> and <<
    friend ostream& operator<<(ostream& os, const AirTransport& plane);
    friend istream& operator>>(istream& is, AirTransport& plane);
};