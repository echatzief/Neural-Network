#ifndef matrix 
#define matrix


class Matrix{
    public:
        int rows;
        int cols;
        double **data;
    public:
        Matrix();
        Matrix(int rows,int cols);
        void add(double n); //Add n to every element in the matrix
        void add(Matrix *m); //Add elementwise two matrixes
        static Matrix * substract(Matrix *a,Matrix *b); //Substract two matrixes elementwise
        void randomize(); //Generate random values
        void printMatrix();
        void multiply(Matrix *m); //Multiply two matrixes elementwise
        void multiply(double n); //Multiply a matrix with number(Scaler)
        static Matrix * multiply(Matrix *a,Matrix *b); //Normal multiplication between two matrixes
        static Matrix * transpose(Matrix *a); //Transpose a matrix
        static double sigmoid(double n);
        static double dsigmoid(double n);
        void map(double (*func)(double));
        static Matrix * map(double (*func)(double),Matrix *a);
	    static Matrix * fromArray(double *array,int length);
	    static double * toArray(Matrix * m);
};

#endif
