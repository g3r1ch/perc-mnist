#ifndef TESTS_H
#define TESTS_H

#include <vector>
#include <iostream>

using namespace std;

class Test {
private:
	int firstNum = -1;
	int secondNum = 0;

	int firstNumMax;
	int secondNumMax;

	int cicleCount = 0;
	int maxCicleCount;
public:
	Test(int maxFirst, int maxSecond, int cicleCount);
	vector<double> generate();
	vector<double> get_generated(bool sum);
	bool is_end();
	void null_cicle();
	int get_cicle();
};

#endif // !TEST_H
