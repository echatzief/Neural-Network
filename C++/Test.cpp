#include "Matrix.h"
#include <iostream>

using namespace std;
int main(){

    Matrix *m = new Matrix(2,3);
    Matrix *k = new Matrix(2,3);
    int a =4;
    int l=1;
    
    k->randomize();
    k->printMatrix();

    double num =3;
    k=Matrix::map(Matrix::sigmoid,k);
    k->printMatrix();
    return 0;
}