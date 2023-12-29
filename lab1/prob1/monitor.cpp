#include <string>
#include <cstring>
#include <iostream>
#include <vector>

#include "monitor.h"

// SETARE VALORI INITIALE PENTRU O VARIABILA DE TIP MONITOR
void initializareMonitor(monitor *m) {
  if (!isValidMonitor(m)) return;

  // utilizare block try-cacth pentru gestionare erori
  try {
    // alocare memorie
    m->firmaProducatoare = new char[strlen("Firma necunoscuta") + 1];
  } catch (std::bad_alloc& ba) {
    // daca memoria nu a fost alocata, e afisata eroarea si e parasit programul
    std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    exit(MemoryAllocationError);
  }

  // setare campuri cu valori initiale
  strcpy(m->firmaProducatoare, "Firma necunoscuta");
  strcpy(m->model, "Model necunoscut");
  m->display = "Display necunoscut";
  m->rez.pxOrizontala = 0;
  m->rez.pxVerticala = 0;
  m->dimensiune = 0;
  m->nrCulori = 0;
}

// FUNCTIE CE VERIFICA DACA POINTERUL LA MONITOR E VALID
bool isValidMonitor(monitor *m) {
  if (m == NULL) {
    std::cerr << "The monitor pointer is NULL.\n";
    return false;
  }
  return true;
}

// SETARE VALOARE COMPANIE PRODUCATOARE PENTRU MONITOR
void setareCompProd(monitor *m, const char *companie) {
  if (!isValidMonitor(m)) return;

  if (m->firmaProducatoare != NULL) {
    delete [] m->firmaProducatoare;
  }

  try {
    m->firmaProducatoare = new char[strlen(companie) + 1];
  } catch (std::bad_alloc& ba) {
    std::cerr << "bad_alloc caught: " << ba.what() << '\n';
    exit(MemoryAllocationError);
  }

  strcpy(m->firmaProducatoare, companie);
}

// SETERE VALOARE MODEL MONITOR
void setareModel(monitor *m, const char *model) {
  if (!isValidMonitor(m)) return;

  // componenta e definita in string ca char[50]
  if (strlen(model) > 49) {
    std::cout << "Denumire model prea lunga. Limita: 49 caractere" << std::endl;
    return;
  }

  strcpy(m->model, model);
}

// SETARE VALOARE DISPLAY MONITOR
void setareDisplay(monitor *m, const std::string &display) {
  if (!isValidMonitor(m)) return;

  m->display = display;
}

// SETARE REZOLUTIE MONITOR
void setareRezolutie(monitor *m, const int rezOrizontala, const int rezVerticala) {
  if (!isValidMonitor(m)) return;

  m->rez.pxOrizontala = rezOrizontala;
  m->rez.pxVerticala = rezVerticala;
}

// SETARE DIMENSIUNE MONITOR
void setareDimensiune(monitor *m, const float dimensiune) {
  if (!isValidMonitor(m)) return;

  m->dimensiune = dimensiune;
}

// SETARE NUMAR CULORI MONITOR
void setareNrCulori(monitor *m, const int nrCulori) {
  if (!isValidMonitor(m)) return;

  m->nrCulori = nrCulori;
}

// AFISARE CARACTERISTICI UN MONITOR
void afisareCaracteristiciMonitor(monitor *m) {
  if (!isValidMonitor(m)) return;

  std::cout << "Companie producatoare: " << m->firmaProducatoare << std::endl;
  std::cout << "Model: " << m->model << std::endl;
  std::cout << "Dimensiune: " << m->dimensiune << " inch" << std::endl;
  std::cout << "Display: " << m->display << std::endl;
  std::cout << "Rezolutie: " << m->rez.pxOrizontala << " x " << m->rez.pxVerticala << std::endl; 
  std::cout << "Numar culori: " << m->nrCulori << std::endl << std::endl;
  std::cout << "=======================================" << std::endl;
}

// AFISARE CARACTERISTICI TOATE MONITOARELE
void afisareCaracteristiciToateMonitoarele(std::vector<monitor>& monitoare) {
  if (monitoare.empty()) {
    std::cout << "Nu sunt monitoare disponibile" << std::endl;
    return;
  }

  for (int i = 0; i < monitoare.size(); ++i) {
    std::cout << std::endl << "Monitor " << i + 1 << std::endl;
    afisareCaracteristiciMonitor(&monitoare[i]);
  }
}

template <typename T>
void comparareAfisare(T valoare1, T valoare2) {
  int rezultatComparatie = comparareValori(valoare1, valoare2);

  if (!rezultatComparatie)
    std::cout << "1: " << valoare1 << " = " << "2: " << valoare2 << std::endl;
  else if (rezultatComparatie == 1)
    std::cout << "1: " << valoare1 << " > " << "2: " << valoare2 << std::endl;
  else
    std::cout << "1: " << valoare1 << " < " << "2: " << valoare2 << std::endl;
}

// FUNCTIE CE COMPARA 2 MONITOARE DUPA REZOLUTIE, DIMENSIUNE SI NUMARUL DE CULORI
void comparareMonitoare(monitor m, monitor n) {
  std::cout << std::endl << "Comparare monitoare" << std::endl << std::endl;
  std::cout << "Monitor 1: " << m.firmaProducatoare << " " << m.model << std::endl;
  std::cout << "Monitor 2: " << n.firmaProducatoare << " " << n.model << std::endl << std::endl;

  std::cout << "Rezolutie" << std::endl;

  if (comparareValori(m.rez.pxOrizontala * m.rez.pxVerticala, n.rez.pxOrizontala * n.rez.pxVerticala) == 0) 
    std::cout << "1: " << m.rez.pxOrizontala << " x " << m.rez.pxVerticala << " = " << "2: " << n.rez.pxOrizontala << " x " << n.rez.pxVerticala << std::endl;
  else if (comparareValori(m.rez.pxOrizontala * m.rez.pxVerticala, n.rez.pxOrizontala * n.rez.pxVerticala) == 1)
    std::cout << "1: " << m.rez.pxOrizontala << " x " << m.rez.pxVerticala << " > " << "2: " << n.rez.pxOrizontala << " x " << n.rez.pxVerticala << std::endl;
  else 
    std::cout << "1: " << m.rez.pxOrizontala << " x " << m.rez.pxVerticala << " < " << "2: " << n.rez.pxOrizontala << " x " << n.rez.pxVerticala << std::endl;

  std::cout << std::endl << "Dimensiune" << std::endl;
  comparareAfisare(m.dimensiune, n.dimensiune);

  std::cout << std::endl << "Numar culori" << std::endl;
  comparareAfisare(m.nrCulori, n.nrCulori);

  std::cout << std::endl << "=======================================" << std::endl;
}

// FUNCTIE CE ELIBEREAZA MEMORIA ALOCATA ANTERIOR
void eliberareMemorie(monitor *m) {
  if (!isValidMonitor(m)) return;

  if (m->firmaProducatoare != NULL) 
    delete [] m->firmaProducatoare;

  m->firmaProducatoare = NULL;
}



// FUNCTIE CE COMPARA 2 VARIABILE 
template <typename T>
int comparareValori(const T a, const T b) {
  if (a == b) return 0;
  else if (a > b) return 1;
  else return -1;
}

// FUNCTIE CE CITESTE O STRUCTURA
void citireStructura(monitor *m) {
  if (!isValidMonitor(m)) return;

  std::cin.clear();
  while (std::cin.get() != '\n');

  std::cout << std::endl << "Citire caracteristici monitor" << std::endl << std::endl;

  setareCompProd(m, citireString("Introduceti compania producatoare: ").c_str());
  setareModel(m, citireString("Introduceti model: ").c_str());
  setareDisplay(m, citireString("Introduceti tip display: ").c_str());
  setareDimensiune(m, citireFloat("Introduceti dimensiunea: "));
  setareRezolutie(m, citireInt("Introduceti nr de px pe orizontala: "), citireInt("Introduceti nr de px pe verticala: "));
  setareNrCulori(m, citireInt("Introduceti numarul de culori: "));

  std::cout << std::endl << "=======================================" << std::endl;
}

// FUNCTIE CE PERMITE CITIREA UNUI STRING DIN CONSOLA
std::string citireString(const std::string &mesaj) {
  std::string sir;
  std::cout << mesaj;
  std::getline(std::cin, sir);
  return sir;
}

// FUNCTIE CE PERMITE CITIREA UNUI FLOAT DIN CONSOLA
float citireFloat(const std::string &mesaj) {
  float valoare;
  std::cout << mesaj;
  std::cin >> valoare;
  return valoare;
}

// FUNCTIE CE PERMITE CITIREA UNUI INT DIN CONSOLA
int citireInt(const std::string &mesaj) {
  int valoare;
  std::cout << mesaj;
  std::cin >> valoare;
  return valoare;
}

// FUNCTIE CE STERGE ULTIMUL MONITOR DIN VECTOR
void stergereMonitor(std::vector<monitor>& monitoare) {
  if (!monitoare.empty()) {
    eliberareMemorie(&monitoare[monitoare.size() - 1]);
    monitoare.pop_back();
    return;
  }

  std::cout << "Nu sunt monitoare disponibile" << std::endl;
}

// FUNCTIE CE PERMITE SELECTAREA UNUI MONITOR
int selectareMonitor(std::vector<monitor>& monitoare) {
  if (monitoare.empty()) {
    std::cout << "Nu sunt monitoare disponibile" << std::endl;
    exit(VectorSizeError);
  }

  std::cout << std::endl << "Selectati unul din monitoarele disponibile" << std::endl << std::endl;

  for (int i = 0; i < monitoare.size(); ++i) {
    std::cout << "Monitor " << i + 1 << ": " << monitoare[i].firmaProducatoare << " " <<monitoare[i].model << std::endl;
  }

  std::cout << std::endl;

  return citireInt("Monitor selectat: ");
}

// FUNCTIE CE REALIZEAZA CAUTAREA MONITORULUI DUPA O ANUMITA COMPANIE
int cautareDupaCompanie(std::vector<monitor>& monitoare, const std::string &companie) {
  for (int i = 0; i < monitoare.size(); ++i) {
    if (monitoare[i].firmaProducatoare == companie) return i;
  }

  return -1;
}

// FUNCTIE CE REALIZEAZA CAUTAREA MONITORULUI DUPA UN ANUMIT MODEL
int cautareDupaModel(std::vector<monitor>& monitoare, const std::string &model) {
  for (int i = 0; i < monitoare.size(); ++i) {
    if (monitoare[i].model == model) return i;
  }

  return -1;
}