/*
 * ImageSender.h
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#ifndef EMAN_COMM_IMAGESENDER_H_
#define EMAN_COMM_IMAGESENDER_H_

#include "SendResponse.h"
#include "Image.h"

class ImageSender {
public:
	ImageSender();
	virtual ~ImageSender();
	virtual SendResponse *send(Image img) = 0;
};

#endif /* EMAN_COMM_IMAGESENDER_H_ */
