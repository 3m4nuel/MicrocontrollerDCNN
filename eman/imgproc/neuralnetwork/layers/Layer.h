/*
 * NeuralNetworkLayer.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYER_NEURALNETWORKLAYER_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYER_NEURALNETWORKLAYER_H_

#include "LayerValues.h"

class Layer {
public:
	Layer();
	virtual ~Layer();
	//virtual LayerValues process(LayerValues input) = 0;

};

#endif /* EMAN_IMGPROC_NEURALNETWORK_NEURALNETWORKLAYER_H_ */
