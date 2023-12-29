#include <string>

const int MemoryAllocationError = -1;
const int VectorSizeError = -2;

struct rezolutie {
  int pxOrizontala;
  int pxVerticala;
};

struct monitor {
  char *firmaProducatoare;
  char model[50];
  std::string display;
  rezolutie rez;
  float dimensiune;
  int nrCulori;
};

// functii pentru realizarea operatiilor de baza cu monitoareale
void initializareMonitor(monitor *m);
bool isValidMonitor(monitor *m);
void eliberareMemorie(monitor *m);
void stergereMonitor(std::vector<monitor>& monitoare);

// functii pentru afisare monitoare / monitor
void afisareCaracteristiciMonitor(monitor *m);
void afisareCaracteristiciToateMonitoarele(std::vector<monitor>& monitoare);
int selectareMonitor(std::vector<monitor>& monitoare);

// functii pentru cautarea monitoarelor dupa anumite criterii
int cautareDupaCompanie(std::vector<monitor>& monitoare, const std::string &companie);
int cautareDupaModel(std::vector<monitor>& monitoare, const std::string &model);

// functii pentru setare parametri monitor
void setareCompProd(monitor *m, const char *companie);
void setareModel(monitor *m, const char *model);
void setareDisplay(monitor *m, const std::string &display);
void setareRezolutie(monitor *m, const int rezOrizontala, const int rezVerticala);
void setareDimensiune(monitor *m, const float dimensiune);
void setareNrCulori(monitor *m, const int nrCulori);

// functii pentru citirea datelor din consola
void citireStructura(monitor *m);
std::string citireString(const std::string &mesaj);
float citireFloat(const std::string &mesaj);
int citireInt(const std::string &mesaj);

// functii pentru comparare valori / monitoare
template <typename T>
int comparareValori(const T a, const T b);
template <typename T>
void comparareAfisare(T valoare1, T valoare2);
void comparareMonitoare(monitor m, monitor n);