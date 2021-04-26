#include "perceptron.h"

using namespace std;

Perc::Perc(int aCountOfW, double aLearningRate) :
	W(0),
	input(0)
{
	for (int i = 0; i < aCountOfW; i++) {
		W.push_back((rand() % 1000 - 500) / 1000.);
	}
	mOffset = (rand() % 1000 - 500) / 1000.;
	learningRate = aLearningRate;
}

double Perc::process(vector<double> aInput) {
	input = aInput;
	summ = 0;
	for (int i = 0; i < W.size(); i++) {
		summ += W[i] * (aInput)[i];
	}
	summ += mOffset;
	out = sigmoid(summ);
	return out;
}

void Perc::changeWeights(double aAnswer) {
	double err = aAnswer - out;
	double nechto = err * dActivationFunction(summ);
	for (int i = 0; i < W.size(); i++) {
		W[i] += learningRate * nechto * (input)[i];
	}
	mOffset += learningRate * nechto;
}

double Perc::output() {
	return out;
}

double Perc::sigmoid(double x) {
	return 1. / (1. + exp(-x));
}

double Perc::dActivationFunction(double x) {
	return sigmoid(x) * (1. - sigmoid(x));
}

vector<double> Perc::ret_w() {
	return W;
}