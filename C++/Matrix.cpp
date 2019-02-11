#include "Matrix.h"
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
int random (int low, int high) {
    if (low > high) return high;
    return low + (std::rand() % (high - low + 1));
}

Matrix::Matrix(){
    this->rows=0;
    this->cols=0;
    this->data=NULL;
};
Matrix::Matrix(int rows,int cols){
    this->rows=rows;
    this->cols=cols;
    
this->data = new double*[this->rows];
    
    //Memory allocate for the array
    for(int i=0;i<this->rows;i++){
        this->data[i]=new double[this->cols];
    }

    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
             this->data[i][j]=0;
        }
    }
};

//Add n to every element in the matrix
void Matrix::add(double n){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            this->data[i][j]+=n;
        }
    }
}

//Add elementwise two matrixes
void Matrix::add(Matrix *m){
    if(this->rows == m->rows && this->cols==m->cols){
        for(int i=0;i<this->rows;i++){
            for(int j=0;j<this->cols;j++){
                this->data[i][j]+=m->data[i][j];
            }
        }
    }
    else{
        cout<<"Dimensions doesn't match"<<endl; 
    }
}

//Substract two matrixes elementwise
Matrix * Matrix::substract(Matrix *a,Matrix *b){
    if(a->rows == b->rows && a->cols==b->cols){
        Matrix * result = new Matrix(a->rows,a->cols);
        for(int i=0;i<a->rows;i++){
            for(int j=0;j<a->cols;j++){
                result->data[i][j]=a->data[i][j]-b->data[i][j]; 
            }
        }
        return result;
    }
    else{
        cout<<"Dimensions doesn't match"<<endl; 
    }
    return NULL;
}
//Generate random values
void Matrix::randomize(){
     
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            this->data[i][j]=random(-1,1); //Randomize number between -1,0,1
        }
    }
}
void Matrix::printMatrix(){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            cout<<this->data[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Multiply two matrixes elementwise
void Matrix::multiply(Matrix *m){
    if(this->rows ==m->rows && this->cols==m->cols){
        for(int i=0;i<this->rows;i++){
            for(int j=0;j<this->cols;j++){
                this->data[i][j]*=m->data[i][j];
            }
        }
    }
    else{
        cout<<"Dimensions doesn't match"<<endl; 
    }
}
//Multiply a matrix with number(Scaler)
void Matrix::multiply(double n){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            this->data[i][j]*=n;
        }
    }
}

//Normal multiplication between two matrixes
Matrix * Matrix::multiply(Matrix *a,Matrix *b){
    if(a->cols!=b->rows){
        cout<<"Columns of A must match rows of B."<<endl;
        return NULL;
    }
    Matrix *result = new Matrix(a->rows,b->cols);

    for(int i=0;i<result->rows;i++){
        for(int j=0;j<result->cols;j++){
            double sum =0;

            for(int k=0;k<a->cols;k++){
                sum+=a->data[i][k]*b->data[k][j];
            }
            result->data[i][j]=sum;
        }
    }
    return result; 
}

//Transpose a matrix
Matrix * Matrix::transpose(Matrix *a){
    Matrix *result = new Matrix(a->cols,a->rows);

    for(int i=0;i<a->cols;i++){
        for(int j=0;j<a->rows;j++){
            result->data[i][j]=a->data[j][i];
        }
    }
    return result;
}
double Matrix::sigmoid(double n){
    return 1/(1+exp(-n));
}
double Matrix::dsigmoid(double y){
    return y*(1-y);
}
void Matrix::map(double (*func)(double)){
    for(int i=0;i<this->rows;i++){
        for(int j=0;j<this->cols;j++){
            this->data[i][j]=func(this->data[i][j]);
        }
    }
}
Matrix * Matrix::map(double (*func)(double),Matrix *a){
    Matrix *m = new Matrix(a->rows,a->cols);

    for(int i=0;i<m->rows;i++){
        for(int j=0;j<m->cols;j++){
            m->data[i][j]=func(a->data[i][j]);
        }
    }
    return m;
}
Matrix * Matrix::fromArray(int *array,int length){
   
    Matrix *newArr = new Matrix(length,1);
    int k=0;
    for(int i=0;i<newArr->rows;i++){
        for(int j=0;j<newArr->cols;j++){
	    newArr->data[i][j]=array[k];
	    k++;
	}
    }
    return newArr;
}
int * Matrix::toArray(Matrix *m){

}
