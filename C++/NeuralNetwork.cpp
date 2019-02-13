#include "NeuralNetwork.h"
#include "Matrix.h"
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
NeuralNetwork::NeuralNetwork(){
    this->input_nodes=-1;
    this->hidden_nodes=-1;
    this->output_nodes=-1;
    this->weightIH=NULL;
    this->weightHO=NULL;
    this->bias_H=NULL;
    this->bias_O=NULL;
};
NeuralNetwork::NeuralNetwork(int inN,int hidN,int outN){
	
	//Fix the limit of each layer
	this->input_nodes=inN;
	this->hidden_nodes=hidN;
	this->output_nodes=outN;
	this->lr = 0.1;

	//Allocate memory for the weights
	this->weightIH= new Matrix(this->hidden_nodes,this->input_nodes);
	this->weightHO= new Matrix(this->output_nodes,this->hidden_nodes);

	//Allocate memory for the bias
	this->bias_H=new Matrix(this->hidden_nodes,1);
	this->bias_O=new Matrix(this->output_nodes,1);

	//Randomize the weights
	srand(time(NULL));
	
	this->bias_H->randomize();
	this->bias_O->randomize();
	this->weightIH->randomize();
	this->weightHO->randomize();
};
double * NeuralNetwork::feedForward(double *array){
	
	//Turn array to matrix
	Matrix * input =Matrix::fromArray(array,this->input_nodes);

	//Hidden layer
	Matrix *hidden = Matrix::multiply(this->weightIH,input);
	hidden->add(this->bias_H);
	hidden->map(Matrix::sigmoid);

	//Output layer
	Matrix *output= Matrix::multiply(this->weightHO,hidden);
	output->add(this->bias_O);
	output->map(Matrix::sigmoid);

	//Return the output in array 
	return Matrix::toArray(output);
};
void NeuralNetwork::train(double *array,double *answers){
	
	//Turn array to matrix
	Matrix * input = Matrix::fromArray(array,this->input_nodes);
	Matrix * targets = Matrix::fromArray(answers,this->output_nodes);

	//--------------------------- Feed Forward Algorithm -----------------------------//

	//Hidden layer
	Matrix *hidden = Matrix::multiply(this->weightIH,input);
	hidden->add(this->bias_H);
	hidden->map(Matrix::sigmoid);

	//Output layer
	Matrix *output= Matrix::multiply(this->weightHO,hidden);
	output->add(this->bias_O);
	output->map(Matrix::sigmoid);

	//--------------------------- Backpropagation and weight fixing -----------------------------//

	//Find the errors with backpropagation
	Matrix *outputError = Matrix::substract(targets,output);
	Matrix *hiddenError = Matrix::multiply(Matrix::transpose(this->weightHO),outputError);

	//---------------------------- Hidden Layer ---------------------------------------//
	//Calculate hidden weights and bias
	Matrix * gradientOut= Matrix::map(Matrix::dsigmoid,output);
	gradientOut->multiply(outputError);
	gradientOut->multiply(this->lr);

	Matrix *deltaOutput = Matrix::multiply(gradientOut,Matrix::transpose(hidden));

	//Change bias
	this->bias_O->add(gradientOut);

	//Change weight
	this->weightHO->add(deltaOutput);

	//---------------------------- Input Layer ---------------------------------------//

	Matrix * gradientI= Matrix::map(Matrix::dsigmoid,hidden);
	gradientI->multiply(hiddenError);
	gradientI->multiply(this->lr);
	
	Matrix *deltaHidden = Matrix::multiply(gradientI,Matrix::transpose(input));

	//Change bias
	this->bias_H->add(gradientI);

	//Change weight
	this->weightIH->add(deltaHidden);

}