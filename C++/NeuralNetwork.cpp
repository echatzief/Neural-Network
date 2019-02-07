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
