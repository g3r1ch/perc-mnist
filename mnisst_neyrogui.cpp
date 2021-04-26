#include <vector>
#include <iostream>
#include <ctime>
#include "perceptron.h"
#include "Layer.h"
#include "norm.h"
#include "outputLayer.h"
#include "gui.h"
#include <cmath>
#include "windows.h"
#include "tests.h"
#include "neyralNetwork.h"
#include "mnist.h"

using namespace std;

int main() {
	MnistReader testMNIST(string(""),string(""));
	MnistReader trainMNIST(string(""), string"));
	Gui gui(800, 600, "mnist");
	Network net({ Network::LayerType::NORM, Network::LayerType::PERC,Network::LayerType::OUTPUTLAYER }, 784, 10, 255);
	bool print = 0;
	int nowShowingNeuron = 0;
	int end = 0;
	cout << "Press:" << endl << " 1.R, to print information while learning" << endl << " 2.Q, to escape learning/testing" << endl << " 3.P, to enjoy pause" << endl << " 4.N, to see visualisation of next weights" << endl;
	while (gui.isOpen()) {
		if (end == 2) {
			cout << "Goodbye, all tests reached..." << endl;
			return 0;
		}
		string in;
		cout << "Type l(to learn) or t(to test):";
		cin >> in;
		int corr = 0;
		if (in[0] == 'l') {
			corr = 0;
			trainMNIST.reopen();
			while (trainMNIST.is_end()) {
				double res = net.process(trainMNIST.matrix());
				gui.matrix_from_double_vec(net.get_w(1, nowShowingNeuron), 28, 28);
				gui.render();
				Gui::EventType ev = gui.evnt();
				if (ev == Gui::EventType::CLOSE) {
					return 0;
				}
				else if (ev == Gui::EventType::PAUSE) {
					cout << "___________PAUSE___________" << endl;
					ev = Gui::EventType::NON;
					while (ev != Gui::EventType::PAUSE) {
						ev = gui.evnt();
						Sleep(1);
					}
					ev = Gui::EventType::NON;
					cout << "___________!PAUSE___________" << endl;
				}
				else if (ev == Gui::EventType::PRINT) {
					print = !print;
				}
				else if (ev == Gui::EventType::RET) {
					cout << "Breaking..."<<endl;
					break;
				}
				else if (ev == Gui::EventType::NEXT) {
					nowShowingNeuron++;
					if (nowShowingNeuron > 9) {
						nowShowingNeuron = 0;
					}
				}
				int ans = trainMNIST.get_label();
				net.correct(ans);
				if (ans == int(res))
					corr++;
				if (print)
					cout << "#" << trainMNIST.imgNumber() << " ans: " << ans << " res: " << int(res) << " corr: " << ((ans == int(res)) ? "YES" : "NO ") << " correct: " << corr << " incorrect: " << trainMNIST.imgNumber() - corr << " err: " << 100 - (corr * 1.) / ((trainMNIST.imgNumber() * 1.) / 100) << " neuron: " << nowShowingNeuron << endl;
			}
			//end++;
		}
		else if (in[0] == 't') {
			corr = 0;
			testMNIST.reopen();
			while (testMNIST.is_end()) {
				double res = net.process(testMNIST.matrix());
				gui.matrix_from_double_vec(net.get_w(1, nowShowingNeuron), 28, 28);
				gui.render();
				Gui::EventType ev = gui.evnt();
				if (ev == Gui::EventType::CLOSE) {
					return 0;
				}
				else if (ev == Gui::EventType::PAUSE) {
					cout << "___________PAUSE___________" << endl;
					ev = Gui::EventType::NON;
					while (ev != Gui::EventType::PAUSE) {
						ev = gui.evnt();
						Sleep(1);
					}
					ev = Gui::EventType::NON;
					cout << "___________!PAUSE___________" << endl;
				}
				else if (ev == Gui::EventType::PRINT) {
					print = !print;
				}
				else if (ev == Gui::EventType::RET) {
					cout << "Breaking..." << endl;
					break;
				}
				else if (ev == Gui::EventType::NEXT) {
					nowShowingNeuron++;
					if (nowShowingNeuron > 9) {
						nowShowingNeuron = 0;
					}
				}
				int ans = testMNIST.get_label();
				net.correct(ans);
				if (ans == int(res))
					corr++;
				if (print)
					cout << "#" << testMNIST.imgNumber() << " ans: " << ans << " res: " << int(res) << " corr: " << ((ans == int(res)) ? "YES" : "NO ") << " correct: " << corr << " incorrect: " << testMNIST.imgNumber() - corr << " err: " << (corr * 1.) / ((testMNIST.imgNumber() * 1.) / 100) << " neuron: " << nowShowingNeuron << endl;
			}
			//end++;
		}
		else {
			if (end == 0) {
				cout << "Incorrect input" << endl;
			}
			else {
				cout << "Just repeate it, please:" << endl;
			}
		}
	}

	return 0;
}