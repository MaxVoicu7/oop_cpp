struct charVector {
  char *data;
  int size;
};

void initializeVector(charVector &v, const int size);
void resizeVector(charVector &v, const int newSize);

void freeMemory(charVector &v);

void readVectorElements(charVector &v, const int start, const int end);

void displayVector(const charVector v, const std::string &message, const int displayOption);

void copyElements(charVector &oldVector, char *newVector, const int size);

bool isInitialized(const charVector &v);

long long int multiplyNegativeElements(const charVector &v);
void multiplyTwoVectors(const charVector &a, const charVector &b);

void changeElementByPosition(charVector &v);
void changeElementByValue(charVector &v);