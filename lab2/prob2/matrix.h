class Matrix {
  private:
    enum ErrorCode {
      NO_ERROR = 0,
      MEMORY_ALLOCATION_ERROR = 1,
      SIZE_INEQUALITY_ERROR = 2
    };

    int nrRows;
    int nrColumns;
    ErrorCode errorCode;
    int *data;

  public:
    // constructors
    Matrix();
    Matrix(const Matrix& other);
    Matrix(const int matrixSize);
    Matrix(const int rows, const int cols);

    // destructor
    ~Matrix();

    // setter functions
    void setElementValue(int, int, int);
    void setParameters(const int rows, const int cols, const ErrorCode errorCodeValue);
    void initializeMatrix();
    void initializeMatrixWithZero();

    // getter functions
    int getRowsNumber();
    int getColumnsNumber() const;
    int getElementValue(const int i, const int j);
    int getErrorCode();

    // check functions
    bool isSquareMatrix();

    // display functions
    void displayMatrix();
    void displayErrorCode();

    // friend functions that perform operation with one or two matrices
    friend bool areMatricesSameSize(Matrix &m1, Matrix &m2);
    friend void addTwoMatrices(Matrix &m1, Matrix &m2, Matrix &result);
    friend void subtractTwoMatrices(Matrix &m1, Matrix &m2, Matrix &result);
    friend void multiplyMatrixAndNumber(Matrix &m1, const int number, Matrix &result);
    friend void multiplyTwoMatrices(Matrix &m1, Matrix &m2, Matrix &result);
};