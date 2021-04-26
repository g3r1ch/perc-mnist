#include "neyralNetwork.h"

Network::Network(std::vector<LayerType> aLayersType, int aInpNeuronsCol, int aNeyronsCount, int aMaxInpSize, double aLearningRate) {
	for (auto& i : aLayersType) {
		if (i == LayerType::NORM) {
			layers.emplace_back(new Norm(aMaxInpSize));
		}
		else if (i == LayerType::PERC) {
			layers.emplace_back(new PercLayer(aNeyronsCount, aInpNeuronsCol, aLearningRate));
		}
		else if (i == LayerType::OUTPUTLAYER) {
			layers.emplace_back(new OutputLayer(aNeyronsCount));
		}
	}
}

Network::~Network()
{
	for (auto& i : layers)
	{
		delete(i);
	}
}

double Network::process(vector<double> aInp) {
	for (auto& i : layers) {
		aInp = i->process(aInp);
	}
	return aInp[0];
}

void Network::correct(int ans) {
	vector<double> anss = { double(ans) };
	for (int i = layers.size()-1; i >= 0; i--) {
		anss = layers[i]->correct(anss);
	}
}

vector<double> Network::get_w(int aLayer, int aNeuron) {
	return layers[aLayer]->get_w(aNeuron, 0);
}
