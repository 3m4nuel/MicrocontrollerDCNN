/*
 * PoolingLayer.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYERS_POOLINGLAYER_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYERS_POOLINGLAYER_H_

#include "Layer.h"

class PoolingLayer: public Layer {
public:
	PoolingLayer();
	virtual ~PoolingLayer();
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_LAYERS_POOLINGLAYER_H_ */
