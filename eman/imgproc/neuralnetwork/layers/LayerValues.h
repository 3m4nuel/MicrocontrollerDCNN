/*
 * LayerInput.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYERS_LAYERVALUES_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYERS_LAYERVALUES_H_

#include <vector>

#include "Neuron.h"

class LayerValues {
private:
	//Neuron *neurons[];
public:
	LayerValues(Neuron *neurons[]);
	virtual ~LayerValues();
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_LAYERS_LAYERVALUES_H_ */
