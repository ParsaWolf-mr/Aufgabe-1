#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>

double Determinat(std::vector<std::vector<double>>& myVector);
void print(const double& T, const std::vector<std::vector<double>>& vec);


int main(int argc, char* argv[]) {
	double t;
	std::vector <std::vector<double>>D2Vec;
	

	if (argc == 1){
		std::cerr << "this ist argument\n";
		return EXIT_FAILURE;
	}
	auto text = argv[1];

	std::ifstream File(text);


	if (File.fail()) {
		std::cerr << "thie isn' t such file in this dirctory\n";
		return 0;
	}
	if (File.is_open()) {
		for (unsigned int i = 0; i < 3; i++) {
			std::vector<double>temp;

			for (unsigned int j = 0; j < 3; j++) {
				File >> t;
				temp.push_back(t);
			}
			D2Vec.push_back(temp);
		}
	}
	double sum = Determinat(D2Vec);
	print(sum, D2Vec);

	return 0; 
}

double Determinat(std::vector<std::vector<double>>& myVector)
{
	double sum = 0, p;
	int x, y;
	x = 1;
	y = 2;
	for (unsigned int i = 0; i <= 2; i++) {


		if (i == 2) y = 1;
		for (i = 0; i <= 2; i++) {

			p = pow(-1, i);
			sum = sum + (myVector[0][i] * (myVector[1][x] * myVector[2][y] - myVector[2][x] * myVector[1][y])) * p;
			x = 0;
		}
	}
	return sum;
}

void print(const double & T, const std::vector<std::vector<double>>& vec) {
	
	for (int i =1 ;  i<= 3; i++){

		if (i == 2) {
			std::cout << "det[";
		}
		else {
			std::cout << "   [";
		}
		for (int j = 1; j <= 3; j++) {
		
			std::cout <<vec[i-1][j-1] ;
			if (j<= 2)
				std::cout << ",";
		}
	
		if (i == 2) {
			std::cout << "]= " << T << std::endl;
		}
		else {
			std::cout << "]\n";
		}


	}
}