/*
 * CNNImageProcessor.h
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_CNNIMAGEPROCESSOR_H_
#define EMAN_IMGPROC_NEURALNETWORK_CNNIMAGEPROCESSOR_H_

#include "ImageProcessor.h"

class CNNImageProcessor : public ImageProcessor {
public:
	CNNImageProcessor();
	virtual ~CNNImageProcessor();
	Image process(Image img);
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_CNNIMAGEPROCESSOR_H_ */
