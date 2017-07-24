/*
 * TCPImageSender.cpp
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#include "TCPImageSender.h"

TCPImageSender::TCPImageSender() {
	// TODO Auto-generated constructor stub

}

TCPImageSender::~TCPImageSender() {
	// TODO Auto-generated destructor stub
}

SendResponse *TCPImageSender::send(Image img) {
	return new SendResponse;
}
