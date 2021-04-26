#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <iostream>	

using namespace std;

class Perc {
private:
	double sigmoid(double x);
	double dActivationFunction(double x);

	double summ;
	double out;
	vector <double> W;
	vector <double> input;
	double learningRate;
	double mOffset;

public:
	Perc(int aCountOfW, double aLearningRate = 0.3);
	double process(vector<double> aInput);
	void changeWeights(double aAnswer);
	double output();
	vector<double> ret_w();
};
#endif // !Perceptron