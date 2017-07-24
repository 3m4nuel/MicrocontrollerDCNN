/*
 * NeuralNetwork.h
 *
 *  Created on: Jul 20, 2017
 *      Author: emman
 */

#ifndef EMAN_IMGPROC_NEURALNETWORK_NEURALNETWORK_H_
#define EMAN_IMGPROC_NEURALNETWORK_NEURALNETWORK_H_

#include <stdlib.h>
#include <string.h>
#include <math.h>

//#include "Serial.h"

// used for get_free_memory()
extern int __bss_end;
extern void *__brkval;

typedef double VAL;		// no idea why this has to go here

class NeuralNetwork
{
	public:
		// methods
		NeuralNetwork();
		NeuralNetwork(int nodeArray[], int numLayers, double eta, double theta, bool debug);
		void	train(int inputArray[], int trainArray[]);
		void	printNet();
		int*	getOutput();
		void	randomizeWeights();
		int*	simulate(int inputArray[]);

		// properties

	private:
		typedef struct {			   /* A LAYER OF A NET:			   */
			int			Units;	   /* - number of units in this layer	 */
			int*		Output;		// 1 or -1
			VAL**		Weight;	  /* - connection weights to ith unit	*/
		} LAYER;

		typedef struct {			   /* A NET:					  */
			LAYER**		Layer;	   /* - layers of this net			*/
			LAYER*		InputLayer;    /* - input layer				 */
			LAYER*		OutputLayer;   /* - output layer				*/
			double	    Eta;	     /* - learning rate			     */
			double		Theta;
		} NET;

		// class methods
		void	setInput(int inputs[]);
		void	adjustWeights(int trainArray[]);
		int		signThreshold(double sum);
		double	weightedSum(int layer, int node);
		void	simulateNetwork();

		// utility methods
		void trace(char *message);
		VAL doubleToVal(double dValue);
		double randomEqualDouble(double Low, double High);
		int get_free_memory();

		// properties
		int			_numLayers;
		NET			_net;
		int*		_output;
};

#endif /* EMAN_IMGPROC_NEURALNETWORK_NEURALNETWORK_H_ */
