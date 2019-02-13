#ifndef NN
#define NN

#include "Matrix.h"

class NeuralNetwork{
    public:
        int input_nodes;
		int hidden_nodes;
		int output_nodes;
		double lr;
        Matrix * weightIH;
		Matrix * weightHO;
		Matrix * bias_H;
		Matrix * bias_O;

    public:
		NeuralNetwork();
		NeuralNetwork(int inN,int hidN,int outN);
		double * feedForward(double *array);
		void train(double *array,double *answers);
};


#endif
