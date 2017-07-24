/*
 * Neuron.h
 *
 *  Created on: Jul 23, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_LAYERS_NEURON_H_
#define EMAN_IMGPROC_NEURALNETWORK_LAYERS_NEURON_H_

class Neuron {
private:
	float weight; // Random at first
protected:
	void setWeight();
public:
	Neuron(float weight);
	virtual ~Neuron();
	virtual float process(float inputs[]) = 0;
	float getWeight() { return this->weight; };
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_LAYERS_NEURON_H_ */
