/*
 * ArduCamera.h
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#ifndef EMAN_CAMERA_ARDUCAMERA_H_
#define EMAN_CAMERA_ARDUCAMERA_H_

#include "Camera.h"

class ArduCamera: public Camera {
public:
	ArduCamera();
	virtual ~ArduCamera();
	Image capture();
};

#endif /* EMAN_CAMERA_ARDUCAMERA_H_ */
