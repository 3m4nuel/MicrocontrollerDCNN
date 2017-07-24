/*
 * ImageProcessor.h
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_IMAGEPROCESSOR_H_
#define EMAN_IMGPROC_IMAGEPROCESSOR_H_

#include "Image.h"

class ImageProcessor {
public:
	ImageProcessor();
	virtual ~ImageProcessor();
	virtual Image process(Image img) = 0;
};

#endif /* IMGPROC_IMAGEPROCESSOR_H_ */
