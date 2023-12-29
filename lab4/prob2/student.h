#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class Student {
  private:
    char *name;
    char *speciality;
    int studyYear;
    float avgGrade;

  public:
    // constructors
    Student();
    Student(const Student &other);
    Student(const char *nameValue, const char *specialityValue, const int studyYearValue, const float avgGradeValue);

    // destructor
    ~Student();

    // setters
    void setName(const char *nameValue);
    void setSpeciality(const char *specialityValue);
    void setStudyYear(const int yearValue);
    void setAvgGrade(const float gradeValue);

    // getters
    float getAvgGrade();

    // comparison operators
    bool operator==(const Student& second);
    bool operator!=(const Student& second);
    bool operator<=(const Student& second);
    bool operator>=(const Student& second);
    bool operator<(const Student& second);
    bool operator>(const Student& second);

    // friend operators
    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};