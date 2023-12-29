#include "student.h"

// ================ constructors and destructor ====================

// default constructor
Student::Student() : name{nullptr}, speciality{nullptr}, studyYear{1}, avgGrade{} {}

// parameterized constructor
Student::Student(const char *nameValue, const char *specialityValue, const int studyYearValue, const float avgGradeValue)
  : studyYear{studyYearValue}, avgGrade{avgGradeValue}, name{nullptr}, speciality{nullptr} {
    setName(nameValue);
    setSpeciality(specialityValue);
}

// copy constructor
Student::Student(const Student &other) : studyYear{other.studyYear}, avgGrade{other.avgGrade}, name{nullptr}, speciality{nullptr} {
  setName(other.name);
  setSpeciality(other.speciality);
}

// destructor
Student::~Student() {
  delete [] name;
  delete [] speciality;
}



// =========================== setters ============================ 

// set the value for study Year
void Student::setStudyYear(const int yearValue) {
  if (yearValue > 0 && yearValue < 5) 
    studyYear = yearValue;
  else {
    studyYear = 1;
    cout << "INVALID STUDY YEAR VALUE" << endl;
  }
}

// set the value for average Grade
void Student::setAvgGrade(const float gradeValue) {
  if (gradeValue >= 0.0 && gradeValue <= 10.0) 
    avgGrade = gradeValue;
  else {
    avgGrade = 0.0;
    cout << "INVALID AVERAGE GRADE VALUE" << endl;
  }
}

// set the value for name 
void Student::setName(const char *nameValue) {
  if (nameValue) {
    char *newName = new char[strlen(nameValue) + 1];
    strcpy(newName, nameValue);

    if (name) 
      delete [] name;

    name = newName;
  }
  else if (name) {
    delete [] name;
    name = nullptr;
  }
}

// set the value for speciality
void Student::setSpeciality(const char *specialityValue) {
  if (specialityValue) {
    char *newSpeciality = new char[strlen(specialityValue) + 1];
    strcpy(newSpeciality, specialityValue);
    
    if (speciality) 
      delete [] speciality;

    speciality = newSpeciality;
  }
  else if (speciality) {
    delete [] speciality;
    speciality = nullptr;
  }
}




// =========================== setters ============================

float Student::getAvgGrade() {
  return avgGrade;
}



// ================== operators =======================

// << overload
std::ostream& operator<<(std::ostream& os, const Student &student) {
  os << "Name: " << (student.name ? student.name : "N/A") << endl;
  os << "Speciality: " << (student.speciality ? student.speciality : "N/A") << endl;
  os << "Study Year: " << student.studyYear << endl;
  os << "Average Grade: " << student.avgGrade << endl;
  return os;
}

// >> overload
std::istream& operator>>(std::istream& is, Student& student) {
  char buffer[100];
  char tempChar;

  cout << "Enter name: ";
  is.getline(buffer, 100);
  student.setName(buffer);

  cout << "Enter speciality: ";
  is.getline(buffer, 100);
  student.setSpeciality(buffer);

  cout << "Enter study year: ";
  is >> student.studyYear;
  is.get(tempChar);

  cout << "Enter average grade: ";
  is >> student.avgGrade;
  is.get(tempChar);

  return is;
}

// == overload
bool Student::operator==(const Student &second) {
  if (studyYear != second.studyYear) return false;
    
  return avgGrade == second.avgGrade;
}

// != overload
bool Student::operator!=(const Student &second) {
  if (studyYear != second.studyYear) return false;
    
  return avgGrade != second.avgGrade;
}

// <= overload
bool Student::operator<=(const Student &second) {
  if (studyYear != second.studyYear) return false;
    
  return avgGrade <= second.avgGrade;
}

// >= overload
bool Student::operator>=(const Student &second) {
  if (studyYear != second.studyYear) return false;
    
  return avgGrade >= second.avgGrade;
}

// < overload
bool Student::operator<(const Student &second) {
  if (studyYear != second.studyYear) return false;
    
  return avgGrade < second.avgGrade;
}

// > overload
bool Student::operator>(const Student &second) {
  if (studyYear != second.studyYear) return false;
    
  return avgGrade > second.avgGrade;
}