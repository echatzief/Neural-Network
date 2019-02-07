#include "Matrix.h"
#include "NeuralNetwork.h"
#include <iostream>
using namespace std;
int main(){ 

   NeuralNetwork * brain = new NeuralNetwork(2,2,1);
   
   cout<<"Weight Hidden: "<<endl;
   brain->weightIH->printMatrix();
   cout<<endl;

   cout<<"Bias Hidden: "<<endl;
   brain->bias_H->printMatrix();
   cout<<endl;

   cout<<"Weight Output: "<<endl;
   brain->weightHO->printMatrix();
   cout<<endl;

   cout<<"Bias Output: "<<endl;
   brain->bias_O->printMatrix();
   cout<<endl;

   return 0;
}
