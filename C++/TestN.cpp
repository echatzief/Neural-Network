#include "Matrix.h"
#include "NeuralNetwork.h"
#include <iostream>
using namespace std;

/*
   We create the inputs,targets and train our neural networn in
   order to implement XOR Gate.
*/
int main(){ 

   NeuralNetwork * brain = new NeuralNetwork(2,30,1);
   
   double ** inputs = new double*[4];
   double * targets = new double[4];

   for(int i=0;i<4;i++){
      inputs[i]=new double[2];
   }

   //We prepare the inputs,targets
   inputs[0][0]=0;
   inputs[0][1]=0;
   targets[0]=0;

   inputs[1][0]=1;
   inputs[1][1]=1;
   targets[1]=0;

   inputs[2][0]=0;
   inputs[2][1]=1;
   targets[2]=1;

   inputs[3][0]=1;
   inputs[3][1]=0;
   targets[3]=1;


   //Train the network 
   for(int i=0;i<100000;i++){
        
      for(int j=0;j<4;j++){
         brain->train(inputs[j],&targets[j]);
      }
   }

   //Test the neural 
   double *res1=brain->feedForward(inputs[0]);
   double *res2=brain->feedForward(inputs[1]);
   double *res3=brain->feedForward(inputs[2]);
   double *res4=brain->feedForward(inputs[3]);

   
   cout<<"Output from tests: "<<endl;
   for(int i=0;i<brain->output_nodes;i++){
      cout<<res1[i]<<endl;
   }
   cout<<endl;
   for(int i=0;i<brain->output_nodes;i++){
      cout<<res2[i]<<endl;
   }
   cout<<endl;
   for(int i=0;i<brain->output_nodes;i++){
      cout<<res3[i]<<endl;
   }
   cout<<endl;
   for(int i=0;i<brain->output_nodes;i++){
      cout<<res4[i]<<endl;
   }
   cout<<endl;
   return 0;
}
