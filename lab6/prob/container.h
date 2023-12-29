#ifndef CONTAINER_H
#define CONTAINER_H

class Container {
  public:
    // functions to be overwritten
    virtual void insert(int value) = 0;
    virtual int extract() = 0;    
    virtual void display() = 0;  

    // destructor 
    virtual ~Container() {}
};

#endif