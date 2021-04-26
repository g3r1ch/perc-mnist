#include "tests.h"

Test::Test(int maxFirst, int maxSecond, int maxCicleCount) :
	firstNumMax(maxFirst),
	secondNumMax(maxSecond),
	maxCicleCount(maxCicleCount)
{}

vector<double> Test::generate() {
	firstNum++;
	if (firstNum > firstNumMax) {
		firstNum = 0;
		secondNum++;
		if (secondNum > secondNumMax) {
			secondNum = 0;
			cicleCount++;
		}
	}
	return { firstNum * 1.,secondNum * 1. };
}

vector<double> Test::get_generated(bool sum) {
	if (sum)
		return { double(firstNum + secondNum) };
	else
		return { double(firstNum) ,double(secondNum) };
}

bool Test::is_end() {
	return cicleCount >= maxCicleCount;
}

void Test::null_cicle() {
	cicleCount = 0;
}

int Test::get_cicle() {
	return cicleCount;
}