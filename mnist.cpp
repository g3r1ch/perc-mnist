#include "mnist.h"


MnistReader::MnistReader(string testFileName, string labelFileName) :
	mTestsFile(testFileName, std::ios::binary),
	mLabelsFile(labelFileName, std::ios::binary)
{
	mTestFileName = testFileName;
	mLabelFileName = labelFileName;
	if (mTestsFile.is_open())
	{
		mTestsFile.read((char*)&magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);
		mTestsFile.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = reverseInt(number_of_images);
		mTestsFile.read((char*)&n_rows, sizeof(n_rows));
		n_rows = reverseInt(n_rows);
		mTestsFile.read((char*)&n_cols, sizeof(n_cols));
		n_cols = reverseInt(n_cols);
	}
	if (mLabelsFile.is_open())
	{
		mLabelsFile.read((char*)&magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);
		mLabelsFile.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = reverseInt(number_of_images);
	}
}

vector<double> MnistReader::matrix() {
	vector<double> res;

	unsigned char temp;

	for (int i = 0; i < n_rows; ++i)
	{
		for (int j = 0; j < n_cols; ++j)
		{
			mTestsFile.read((char*)&temp, sizeof(temp));
			res.emplace_back(temp);
		}
	}
	countOfReadImages++;
	return res;
}

int MnistReader::get_label() {
	unsigned char temp;
	mLabelsFile.read((char*)&temp, sizeof(temp));
	return temp;
}

int MnistReader::reverseInt(int i)
{
	unsigned char c1, c2, c3, c4;

	c1 = i & 255;
	c2 = (i >> 8) & 255;
	c3 = (i >> 16) & 255;
	c4 = (i >> 24) & 255;

	return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}

vector<double> MnistReader::mirror_matrix(vector<double> aInp, int aCountOfCols) {
	if (aCountOfCols == -1) {
		aCountOfCols = n_cols;
	}
	vector<double> res;
	for (int i = 0; i < aCountOfCols; i++) {
		for (int j = (aInp.size() / aCountOfCols) - 1; j >= 0; j--) {
			res.push_back(aInp[i * 28 + j]);
		}
	}
	return res;
}

bool MnistReader::is_end() {
	return countOfReadImages <= number_of_images;
}

int MnistReader::imgNumber(){
	return countOfReadImages;
}

void MnistReader::reopen() {
	mTestsFile.close();
	mLabelsFile.close();
	mTestsFile.open(mTestFileName, std::ios::binary);
	mLabelsFile.open(mLabelFileName, std::ios::binary);
	if (mTestsFile.is_open())
	{
		mTestsFile.read((char*)&magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);
		mTestsFile.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = reverseInt(number_of_images);
		mTestsFile.read((char*)&n_rows, sizeof(n_rows));
		n_rows = reverseInt(n_rows);
		mTestsFile.read((char*)&n_cols, sizeof(n_cols));
		n_cols = reverseInt(n_cols);
	}
	if (mLabelsFile.is_open())
	{
		mLabelsFile.read((char*)&magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);
		mLabelsFile.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = reverseInt(number_of_images);
	}
	countOfReadImages = 0;
}