#include <iostream>
#include <fstream>
#include <map>

int getDelay(std::map<int, int> M)
{
	int delay = 0;

	while (1) {
		bool found = true;

		for (const auto& x : M)
			if ((x.first + delay) % (2 * x.second - 2) == 0) {
				found = false;
				break;
			}

		if (found == true)
			return delay;

		++ delay;
	}
}

int main()
{
	std::ifstream fin("data.in");
	std::map<int, int> M;
	int layer, depth;

	while(fin >> layer) {
		std::string junk;

		fin >> junk;
		fin >> depth;

		M[layer] = depth;
	}

	fin.close();

	int severity = 0;

	for (const auto& x : M)
		if (x.first % (2 * x.second - 2) == 0)
			severity += x.first * x.second;

	std::cout << "The answer for task1 is: " << severity << "\n";
	std::cout << "The answer for task2 is: " << getDelay(M) << "\n";

	return 0;
}