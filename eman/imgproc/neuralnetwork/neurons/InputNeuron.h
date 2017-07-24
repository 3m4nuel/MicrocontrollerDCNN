/*
 * InputNeuron.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYERS_INPUTNEURON_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYERS_INPUTNEURON_H_

#include "Neuron.h"

class InputNeuron: public Neuron {
public:
	InputNeuron(float weight) : Neuron(weight) {};
	virtual ~InputNeuron();
	float process(float inputs[]);
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_LAYERS_INPUTNEURON_H_ */
