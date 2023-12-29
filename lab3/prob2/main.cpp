#include <iostream>
#include <string>
#include <limits>
#include "myString.h"

using std::cout;
using std::endl;

int main() {
  String str1, str2;
  char tempStr[1024];
  int choice;
  bool done = false;

  do {
    cout << "\n============== String Class Menu ================" << endl << endl;
    cout << "1. Create / Modify first string" << endl;
    cout << "2. Create / Modify second string" << endl;
    cout << "3. Show string 1" << endl;
    cout << "4. Show string 2" << endl;
    cout << "5. Add something to string 1" << endl;
    cout << "6. Add something to string 2" << endl;
    cout << "7. Compare string 1 and string 2 using ==" << endl;
    cout << "8. Compare string 1 and string 2 using !=" << endl;
    cout << "9. Add string 1 and string 2" << endl;
    cout << "10. Display first element of string 1" << endl;
    cout << "11. Compare strings using <" << endl;
    cout << "12. Compare strings using >" << endl;
    cout << "13. Compare a string with a char *" << endl;
    cout << "14. Leave" << endl << endl;
    cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
      case 1:
        std::cout << "Enter first string: ";
        std::cin >> str1;
        break;

      case 2:
        std::cout << "Enter second string: ";
        std::cin >> str2;
        break;

      case 3:
        std::cout << "String 1: " << str1 << endl;
        break;

      case 4:
        std::cout << "String 2: " << str2 << endl;
        break;

      case 5:
        std::cout << "Add to string 1: ";
        std::cin.getline(tempStr, 1024);
        str1 += tempStr;
        break;

      case 6: {
        std::cout << "Add to string 2: ";
        String temp;
        std::cin >> temp;
        str2 += temp;
        break;
      }

      case 7:
        std::cout << "String 1 and String 2 are " << (str1 == str2 ? "equal" : "not equal") << endl;
        break;

      case 8:
        std::cout << "String 1 and String 2 are " << (str1 != str2 ? "not equal" : "equal") << endl;
        break;

      case 9: {
        String str3 = str1 + str2;
        std::cout << "Result of addition: " << str3 << endl;
        break;
      }

      case 10:
        if (str1.getLength() > 0) 
          cout << "First element of string 1: " << str1[0] << endl;
        else 
          cout << "String 1 is empty" << endl;
        
        break;

      case 11:
        cout << "String 1 is " << (str1 < str2 ? "less than" : "not less than") << " String 2" << endl;
        break;

      case 12:
        cout << "String 1 is " << (str1 > str2 ? "greater than" : "not greater than") << " String 2" << endl;
        break;

      case 13:
        cout << "Enter a string to compare with String 1: ";
        std::cin >> tempStr;
        cout << "String 1 is " << (str1 == tempStr ? "equal to" : "not equal to") << " the C-style string" << endl;
        break;

      case 14:
        done = true;
        break;

      default:
        std::cout << "Invalid choice. Please try again" << endl;
        break;
      }
    } while (!done);

  return 0;
}