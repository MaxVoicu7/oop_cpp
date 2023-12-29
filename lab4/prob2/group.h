#include <iostream>
#include <cstring>
#include "student.h"

class Group {
  private:
    Student **students;
    int nrStudents;
    char *name;

  public:
    // constructors
    Group();
    Group(const Student **studentsValue, const int nrStudentsValue, const char *name);
    Group(const Group &other);

    // destructor
    ~Group();

    // setters
    void setName(const char *nameValue);

    // member functions
    void addStudent(const Student* newStudent);
    void deleteStudent(const Student* deletedStudent);
    float getAvgGrade() const;

    // friend functions
    friend std::ostream& operator<<(std::ostream& os, const Group& group);
};