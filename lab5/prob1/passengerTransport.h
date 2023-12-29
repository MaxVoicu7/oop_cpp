#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

class PassengerTransport {
  private:
    int seatNumber;            
    bool isInternational;      
    float luggageVolume;      

	public:
    // constructors
    PassengerTransport();
    PassengerTransport(const int seatNr, bool isInternationalValue, float luggageVolumeValue);

		// destructor
    ~PassengerTransport();

    // setters
    void setSeatNumber(int seatNr);
    void setIsInternational(bool isInternationalValue);
    void setLuggageVolume(float luggageVolumeValue);

    // friend functions
    friend ostream& operator<<(ostream& os, const PassengerTransport& transport);
    friend istream& operator>>(istream& is, PassengerTransport& transport);
};