#include "Matrix.h"
#include <iostream>
#include <ctime>
using namespace std;
int main(){

    std::srand(std::time(nullptr));
    Matrix *k = new Matrix(2,3);
    Matrix *m1 = new Matrix(2,2);
    Matrix *m2 = new Matrix(2,2);
   	 
    //Transpose
    cout<<"Transpose"<<endl;
    k->randomize();
    k->printMatrix();
    cout<<endl;
    k=Matrix::transpose(k);
    k->printMatrix();
    
    //Multiply
    cout<<"Multiply(a,b)"<<endl;
    m1->randomize();
    m1->printMatrix();
    cout<<endl;
    m2->randomize();
    m2->printMatrix();
    cout<<endl;
    Matrix *res = Matrix::multiply(m1,m2);
    res->printMatrix();
    
    //Multiply
    cout<<"Multiply n"<<endl;
    Matrix * a1 = new Matrix(2,2);
    Matrix * a2 = new Matrix(2,2);
    Matrix * a3 = new Matrix(2,2);

    a1->randomize();
    a1->printMatrix();
    cout<<endl;

    a2->randomize();
    a2->printMatrix();
    cout<<endl;

    a3->randomize();
    a3->printMatrix();
    cout<<endl;

    a3->multiply(2);
    a1->multiply(a2);

    a3->printMatrix();
    cout<<endl;

    a1->printMatrix();

    //Substract
    cout <<"Sustract(a,b)"<<endl;
    Matrix *s1 = new Matrix(2,2);
    Matrix *s2 = new Matrix(2,2);

    s1->randomize();
    s1->printMatrix();
    cout<<endl;

    s2->randomize();
    s2->printMatrix();
    cout<<endl;

    Matrix *sub = Matrix::substract(s1,s2);
    sub->printMatrix();
    cout<<endl;

    //Add
    cout<<"Add "<<endl;
    Matrix *b1 = new Matrix(2,2);
    Matrix *b2 = new Matrix(2,2);
    Matrix *b3 = new Matrix(2,2);
 
    b1->randomize();
    b1->printMatrix();
    cout<<endl;

    b2->randomize();
    b2->printMatrix();
    cout<<endl;

    b3->randomize();
    b3->printMatrix();
    cout<<endl;

    b1->add(2);
    b1->printMatrix();
    cout<<endl;

    b2->add(b3);
    b2->printMatrix();
    cout<<endl;
    
    cout<<"Map"<<endl;
    Matrix *k1 = new Matrix(2,2);
    Matrix *k2 = new Matrix(2,2);

    k1->randomize();
    k1->printMatrix();
    cout<<endl;

    k2->randomize();
    k2->printMatrix();
    cout<<endl;

    k1->map(Matrix::sigmoid);
    k1->printMatrix();
    cout<<endl;

    Matrix *ress = Matrix::map(Matrix::sigmoid,k2);
    ress->printMatrix();
    cout<<endl;

    return 0;
}
