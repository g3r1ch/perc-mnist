#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "percLayer.h"
#include "norm.h"
#include "outputLayer.h"
#include "layer.h"


class Network {
private:
	vector<Layer*> layers;
public:
	enum LayerType { NORM, PERC, OUTPUTLAYER };
	Network(std::vector<LayerType> aLayersType, int aInpNeuronsCol, int aNeyronsCount, int aMaxInpSize = 250, double aLerningRate = 0.3);//TODO: aColOfLayers
	~Network();
	double process(vector<double> aInp);
	void correct(int ans);
	vector<double> get_w(int aLayer, int aNeuron);
};


#endif