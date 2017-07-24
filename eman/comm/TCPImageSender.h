/*
 * TCPImageSender.h
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#ifndef EMAN_COMM_TCPIMAGESENDER_H_
#define EMAN_COMM_TCPIMAGESENDER_H_

#include "ImageSender.h"

class TCPImageSender: public ImageSender {
public:
	TCPImageSender();
	virtual ~TCPImageSender();
	SendResponse *send(Image img);
};

#endif /* EMAN_COMM_TCPIMAGESENDER_H_ */
