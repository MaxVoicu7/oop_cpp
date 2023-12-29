#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include "monitor.h"

int main() {
  std::vector<monitor> monitoare;
  monitor newMonitor;
  int monitorSelectat, monitorSelectat2;
  int optiune;
  int rezultat;
  
  do{
    std::cout << std::endl;
    std::cout << "Selectati una din optiuni: " << std::endl;
    std::cout << "\t1. Adaugati un monitor" << std::endl;
    std::cout << "\t2. Modificati rezolutia unui monitor" << std::endl;
    std::cout << "\t3. Modificati dimensiunea unui monitor" << std::endl;
    std::cout << "\t4. Comparati doua monitoare" << std::endl;
    std::cout << "\t5. Cautati monitor dupa compania producatoare" << std::endl;
    std::cout << "\t6. Cautati monitor dupa model" << std::endl;
    std::cout << "\t7. Eliminati ultimul monitor" << std::endl;
    std::cout << "\t8. Afisati lista monitoarelor" << std::endl;
    std::cout << "\t9. Parasire program" << std::endl;

    std::cout << std::endl << "Optiune selectata: ";
    std::cin >> optiune;

    std::cout << std::endl << "=======================================" << std::endl;

    switch (optiune) {
      case 1:
        // se creaza o variabila de tip monitor, dupa se introduce in vector
        initializareMonitor(&newMonitor);
        citireStructura(&newMonitor);
        monitoare.push_back(newMonitor);
        break;

      case 2:
        // se selecteaza un monitor pentru a modifica rezolutia acestuia
        monitorSelectat = selectareMonitor(monitoare);
        std::cout << std::endl;
        setareRezolutie(&monitoare[monitorSelectat - 1], citireInt("Introduceti nr de px pe orizontala: "), citireInt("Introduceti nr de px pe verticala: "));
        std::cout << std::endl << "=======================================" << std::endl;
        break;

      case 3: 
        // se selecteaza un monitor pentru a modifica dimensiunea acestuia
        monitorSelectat = selectareMonitor(monitoare);
        std::cout << std::endl;
        setareDimensiune(&monitoare[monitorSelectat - 1], citireFloat("Introduceti dimensiunea: "));
        std::cout << std::endl << "=======================================" << std::endl;
        break;

      case 4:
        // compararea a 2 monitoare selectate
        monitorSelectat = selectareMonitor(monitoare);
        monitorSelectat2 = selectareMonitor(monitoare);
        comparareMonitoare(monitoare[monitorSelectat - 1], monitoare[monitorSelectat2 - 1]);
        break;

      case 5:
        // cautare monitor dupa companie
        std::cout << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');

        rezultat = cautareDupaCompanie(monitoare, citireString("Introduceti compania cautata: "));
        std::cout << std::endl;

        if ( rezultat == -1 )
          std::cout << "Nu a fost gasit monitor de la aceasta firma" << std::endl;
        else 
          afisareCaracteristiciMonitor(&monitoare[rezultat]);
        break;

      case 6: 
        // cautare monitor dupa model
        std::cout << std::endl;
        std::cin.clear();
        while (std::cin.get() != '\n');

        rezultat = cautareDupaModel(monitoare, citireString("Introduceti modelul cautat: "));
        std::cout << std::endl;
        
        if ( rezultat == -1 )
          std::cout << "Nu a fost gasit monitor de la acest model" << std::endl;
        else 
          afisareCaracteristiciMonitor(&monitoare[rezultat]);
        break;

      case 7:
        stergereMonitor(monitoare);
        break;

      case 8: 
        afisareCaracteristiciToateMonitoarele(monitoare);
        break;

      case 9:
        for(int i = 0; i < monitoare.size(); i++)   
          eliberareMemorie(&monitoare[i]);
        break;

      default: 
        std::cout << "Optiunea selectata nu e disponibila" << std::endl;
        break;
    }

  } while (optiune != 9);

  return 0;
}