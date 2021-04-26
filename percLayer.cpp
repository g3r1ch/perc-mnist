#include "percLayer.h"

PercLayer::PercLayer(int aCountOfNeyrons, int aCountOfInputs, double aLearningRate) :
	neyro(aCountOfNeyrons, Perc(aCountOfInputs))
{}

vector <double> PercLayer::process(const vector <double> aInp) {
	vector <double> res;
	for (auto& i : neyro) {
		res.push_back(i.process(aInp));
	}
	return res;
}

vector<double> PercLayer::correct(const vector <double> aInp) {
	for (int i = 0; i < neyro.size(); i++)
	{
		neyro[i].changeWeights(aInp[i]);
	}
	return{};
}

int PercLayer::size() const {
	return neyro.size();
}

vector<double> PercLayer::get_w(int num_of_perc, bool flag) {
	vector<double> out;
	if (num_of_perc < 0) {
		out = { -1 };
		return out;
	}else if (flag) {
		for (int i = 0; i < neyro.size(); i++) {
			out.push_back(neyro[i].ret_w()[num_of_perc]);
		}
	}
	else {
		out = neyro[num_of_perc].ret_w();
	}
	return out;
}