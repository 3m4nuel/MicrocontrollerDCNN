/*
 * NeuralNetwork.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(){};

NeuralNetwork::NeuralNetwork(int nodeArray[], int numLayers, double eta = 0.1, double theta = 0.0, bool debug = false) {
	trace("NeuralNetwork::NeuralNetwork\n");

	_numLayers = numLayers;
	_output = (int*) calloc(nodeArray[_numLayers-1], sizeof(int));

	// allocate structs & initialize network

	int i, j;

	_net.Layer = (LAYER**) calloc(_numLayers, sizeof(LAYER*));

	for (i=0; i < _numLayers; i++) {
		// 2D array of the network's layers
		//_output[i] = 0;
		_net.Layer[i] = (LAYER*) malloc(sizeof(LAYER));
		_net.Layer[i]->Units = nodeArray[i];
		_net.Layer[i]->Output = (int*) calloc(nodeArray[i], sizeof(int));

		// 2D array of weights for each pair of nodes between layers
		_net.Layer[i]->Weight = (VAL**) calloc(nodeArray[i]+1, sizeof(VAL*));

		if (i!=0) {
			for (j=0; j<nodeArray[i]; j++) {
				// init array for incoming connections to node j of layer i
				_net.Layer[i]->Weight[j] = (VAL*) calloc(nodeArray[i-1], sizeof(VAL));
			}
		}
	}

	_net.InputLayer = _net.Layer[0];
	_net.OutputLayer = _net.Layer[_numLayers-1];
	_net.Eta = eta;		// learning rate
	_net.Theta = theta;	// threshold
}

/********* UTILITIES *********/

//just for testing alternative ways of storing the values... (for now is the same: DOUBLE)
VAL NeuralNetwork::doubleToVal(double dValue) {
	return (VAL) dValue;
}

double NeuralNetwork::randomEqualDouble(double Low, double High) {
	return ((double) rand() / RAND_MAX) * (High-Low) + Low;
}

void NeuralNetwork::printNet(){
	/*
	if (_debug) {
		int l,i,j;

		//Serial.print("weights of layer 0 test: ");
		//Serial.println(_net.Layer[0]->Weight[0][0], DEC);

		for (l=1; l<_numLayers; l++) {
			Serial.print("Layer[");
			Serial.print(l, DEC);
			Serial.println("]:");
			Serial.print("\t");
			for (i=0; i<_net.Layer[l]->Units; i++) {
				Serial.print(i,DEC);
				Serial.print("\t");
			}
			Serial.println();
			for (i=0; i<_net.Layer[l]->Units; i++) {
				// cycle through units of current layer
				//Serial.print("  Unit ");
				Serial.print(i,DEC);
				Serial.print(":\t");
				for (j=0; j<_net.Layer[l-1]->Units; j++) {
					// cycle through units of "leftmost" layer
					Serial.print(_net.Layer[l]->Weight[i][j], 3);
					trace("\t");
				}
				trace("\n");
			}
			trace("\n");
		}
		trace("\n");
	}*/
}

// free memory check
// from: http://forum.pololu.com/viewtopic.php?f=10&t=989#p4218
int NeuralNetwork::get_free_memory(){
	int free_memory;
	if((int)__brkval == 0)
		free_memory = ((int)&free_memory) - ((int)&__bss_end);
	else
		free_memory = ((int)&free_memory) - ((int)__brkval);

	return free_memory;
}

/********* PRIVATE *********/

void NeuralNetwork::randomizeWeights() {
	int l,i,j;
	double temp;

	for (l=1; l<_numLayers; l++) {
		for (i=0; i<_net.Layer[l]->Units; i++) {
			for (j=0; j<_net.Layer[l-1]->Units; j++) {
				_net.Layer[l]->Weight[i][j] = doubleToVal(randomEqualDouble(-0.5, 0.5));
			}
		}
	}
}

void NeuralNetwork::setInput(int inputs[]){
	int i;
	for (i=0; i<_net.InputLayer->Units; i++) {
		_net.InputLayer->Output[i] = inputs[i];
	}
}

int* NeuralNetwork::getOutput(){

	return _output;

}

int NeuralNetwork::signThreshold(double sum){
	if (sum >= _net.Theta) {
		return 1;
	} else {
		return -1;
	}
}

double NeuralNetwork::weightedSum(int l, int node){
	// calculates input activation for a particular neuron
	int i;
	double currentWeight, sum = 0.0;

	for (i=0; i<_net.Layer[l-1]->Units; i++) {
		currentWeight = _net.Layer[l]->Weight[node][i];
		sum += currentWeight * _net.Layer[l-1]->Output[i];
	}

	return sum;
}

void NeuralNetwork::adjustWeights(int trainArray[]){
	int l,i,j;
	int in,out, error;
	int activation;	// for each "rightmost" node
	double delta;

	for (l=1; l<_numLayers; l++) {
		// cycle through each pair of nodes
		for (i=0; i<_net.Layer[l]->Units; i++) {
			// "rightmost" layer
			// calculate current activation of this output node
			activation = signThreshold(weightedSum(l,i));
			out = trainArray[i];	// correct activation
			error = out - activation;	// -2, 2, or 0

			for (j=0; j<_net.Layer[l-1]->Units; j++) {
				// "leftmost" layer

				in = _net.Layer[l-1]->Output[j];

				delta = _net.Eta * in * error;
				_net.Layer[l]->Weight[i][j] += delta;
			}
		}
	}
}

void NeuralNetwork::simulateNetwork(){
	/*****
	 Calculate activations of each output node
	 *****/
	int l,j;

	for (l=_numLayers-1; l>0; l--) {
		// step backwards through layers
		// TODO: this will only work for _numLayers = 2!
		for (j=0; j < _net.Layer[l]->Units; j++) {
			_output[j] = signThreshold(weightedSum(1, j));
		}
	}
}

/********* PUBLIC *********/

void NeuralNetwork::train(int inputArray[], int trainArray[]) {
	trace("NeuralNetwork::train\n");

	setInput(inputArray);
	adjustWeights(trainArray);

}

int* NeuralNetwork::simulate(int inputArray[]) {
	// introduce an input stimulus, simulate the network,
	// and return an output array
	trace("NeuralNetwork::simulate\n");
	setInput(inputArray);
	simulateNetwork();

	return _output;
}

void NeuralNetwork::trace(char *message) {
	/*if(_debug){
		Serial.print(message);
	}*/
}
