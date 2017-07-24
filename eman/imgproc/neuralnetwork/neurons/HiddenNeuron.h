/*
 * HiddenNeuron.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYERS_HIDDENNEURON_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYERS_HIDDENNEURON_H_

#include "Neuron.h"

class HiddenNeuron: public Neuron {
public:
	HiddenNeuron(float weight) : Neuron(weight) {};
	virtual ~HiddenNeuron();
	float process(float inputs[]);
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_LAYERS_HIDDENNEURON_H_ */
