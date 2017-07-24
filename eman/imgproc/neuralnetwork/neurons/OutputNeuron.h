/*
 * OutputNeuron.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYERS_OUTPUTNEURON_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYERS_OUTPUTNEURON_H_

#include "Neuron.h"

class OutputNeuron: public Neuron {
public:
	OutputNeuron(float weight) : Neuron(weight) {};
	virtual ~OutputNeuron();
	float process(float inputs[]);
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_LAYERS_OUTPUTNEURON_H_ */
