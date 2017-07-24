/*
 * Camera.h
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#ifndef EMAN_CAMERA_CAMERA_H_
#define EMAN_CAMERA_CAMERA_H_

#include "Image.h"
#include <vector>

using namespace std;

class Camera {
private:
	std::vector<Image> test;
public:
	Camera();
	virtual ~Camera();
	virtual Image capture() = 0;
};

#endif /* CAMERA_CAMERA_H_ */
