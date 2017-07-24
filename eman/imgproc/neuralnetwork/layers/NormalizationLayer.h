/*
 * NormalizationLayer.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYERS_NORMALIZATIONLAYER_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYERS_NORMALIZATIONLAYER_H_

#include "Layer.h"

class NormalizationLayer : public Layer {
public:
	NormalizationLayer();
	virtual ~NormalizationLayer();
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_LAYERS_NORMALIZATIONLAYER_H_ */
