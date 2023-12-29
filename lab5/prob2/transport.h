#include <iostream>
#include <string>

#ifndef TRANSPORT_H
#define TRANSPORT_H

using std::string;
using std::cout;
using std::endl;

class Transport {
  private:
    string type;
    bool isActive;
    int capacity;    

  public:
    // constructors
    Transport();
    Transport(const string& typeValue, const bool isActiveValue, const int capacityValue);

    // destructor
    virtual ~Transport();

    // setters
    void setType(const string& typeValue);
    void setIsActive(const bool isActiveValue);
    void setCapacity(const int capacityValue);

    // methods
    void updateCapacity(int change);
    void activate();
    void deactivate();

    // display function
    void displayDetails() const;
};

#endif