#include <iostream>
#include <array>
#include <chrono>

#define Max 10

void coutArray(std::array<double, Max>& arr);

struct Timer {
		
	std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() {
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer() {
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << "Timer took " << ms << "ms \n";
	}
};


int main() {
	std::array<double, Max>arr{0};
	for (int i = 0; i < Max; i++)
		arr[i] = i * 0.34567;

	coutArray(arr);
	return 0;
}

void coutArray(std::array<double, Max>& arr) {
	Timer timer;
	for (int i = 1; i <= Max; i++) {
		std::cout << arr[i - 1]<< "\t";
		if (i % 4 == 0)
			std::cout << "\n";
	}
	std::cout << std::endl;
}