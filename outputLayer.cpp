#include "outputLayer.h"

using namespace std;

OutputLayer::OutputLayer(int aConnectionsCount) {
	connectionsCount = aConnectionsCount;
}

vector<double> OutputLayer::process(const vector <double> aInp) {
	for (int i = 0; i < aInp.size(); i++) {
		if (aInp[i] > 0.85)
			return { i * 1. };
	}
	return { -1 * 1. };
}

double OutputLayer::activationFunction(double aS)
{
	return 1. / (1. + exp(-aS));
}

vector <double> OutputLayer::correct(const vector<double> aInp) {
	vector<double> result(connectionsCount);
	result[aInp[0]] = 1;
	return result;
}

int OutputLayer::size() const {
	return connectionsCount;
}