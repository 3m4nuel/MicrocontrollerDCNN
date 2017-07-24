/*
 * ConvolutionalLayer.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYERS_CONVOLUTIONALLAYER_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYERS_CONVOLUTIONALLAYER_H_

#include "Layer.h"
#include "Filter.h"

class ConvolutionalLayer: public Layer {
public:
	ConvolutionalLayer();
	virtual ~ConvolutionalLayer();
	LayerValues process(LayerValues input);
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_LAYERS_CONVOLUTIONALLAYER_H_ */
