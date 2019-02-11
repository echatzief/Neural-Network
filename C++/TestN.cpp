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
   
   double * test= new double[2];
   test[0]=0;
   test[1]=1;

   double *ress = brain->feedForward(test,2);

   for(int i=0;i<1;i++){
      cout<<"Element "<<i<<" : "<<ress[i]<<endl;
   }

   return 0;
}
