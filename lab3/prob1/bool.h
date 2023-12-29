#ifndef BOOL_H
#define BOOL_H

class Bool {
  private:
    bool value;

  public:
    // constructors
    Bool();
    Bool(const Bool& object);
    explicit Bool(bool boolValue);
    explicit Bool(int number);

    // destructor
    ~Bool();

    // getters
    bool getValue() const;

    // display to console
    void displayValue() const;

    // operators
    Bool operator+ (const Bool &secondValue) const;
    Bool operator+ (const int secondValue) const;

    Bool operator* (const Bool &secondValue) const;
    Bool operator* (const int secondValue) const;

    Bool operator^ (const Bool &secondValue) const;
    Bool operator^ (const int secondValue) const;

    // friend functions
    friend Bool operator+(const int firstValue, const Bool &secondValue);
    friend Bool operator*(const int firstValue, const Bool &secondValue);
    friend Bool operator^(const int firstValue, const Bool &secondValue);

    friend Bool operator== (const Bool &firstValue, const Bool &secondValue);
    friend Bool operator== (const Bool &firstValue, const int secondValue);
    friend Bool operator== (const int firstValue, const Bool &secondValue);

    friend Bool operator!= (const Bool &firstValue, const Bool &secondValue);
    friend Bool operator!= (const Bool &firstValue, const int secondValue);
    friend Bool operator!= (const int firstValue, const Bool &secondValue);
};

#endif