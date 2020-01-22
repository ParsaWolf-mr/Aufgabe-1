#include <iostream>
#include <vector>
#include <string>
#include <fstream>

void textInVector(const std::vector<std::string>& vec, const std::string& name);


int main(int argc, char* argv[]) {
	std::vector <std::string>vec;

	if (argc == 1) {
		std::cerr << "kein element voehanden\n";
		return 0;
	}
	for (size_t i = 1; i <argc; i++)
	{
		vec.push_back(argv[i]);
	}
	textInVector(vec, "Data.txt");

	return 0;
}


void textInVector(const std::vector<std::string>& vec, const std::string& name) {
	std::ofstream File;
	File.open(name);
	if (File.is_open()) {

		File << "Programmname = " << vec[0] << std::endl;
		File << "Argumente =" << vec.size()-1 << std::endl;
		File << "Argument_1 = " << vec[1] << std::endl;
		File << "Argument_2 = " << vec[2] << std::endl;
		File << "Argument_3 = " << vec[3] << std::endl;
	}
}