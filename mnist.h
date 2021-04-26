#ifndef MNIST_H
#define MNIST_H

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MnistReader {
private:
	std::ifstream mTestsFile, mLabelsFile;
	int reverseInt(int i);
	int magic_number = 0;
	int number_of_images = 0;
	int n_rows = 0;
	int n_cols = 0;
	int countOfReadImages = 0;
	string mTestFileName, mLabelFileName;
public:
	MnistReader(string testFileName, string labelFileName);
	vector<double> matrix();
	int get_label();
	vector<double> mirror_matrix(vector<double> aInp, int aCountOfCols = -1);
	bool is_end();
	int imgNumber();
	void reopen();
};

#endif // !MNIST_H