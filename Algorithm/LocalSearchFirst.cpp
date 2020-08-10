#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#define NQUEENS 8
#define number_neighbor 15

using namespace std;

namespace localsearch{

	vector<int> initial_solution() {
		vector<int> solution;
		solution.resize(NQUEENS);
		for (auto &element : solution) {
			element = rand() % NQUEENS + 1;
		}
		return solution;
	}

	int cost(const std::vector<int> &solution_vector) {
		int h = 0;
		//sum column
		for (size_t i = 0; i < solution_vector.size(); i++) {
			for (size_t j = i + 1; j < solution_vector.size(); j++) {
				if (solution_vector[i] == solution_vector[j]) {
					h++;
					break;
				}
			}
		}
		//sum diagonal
		for (size_t i = 0; i < solution_vector.size(); i++) {
			for (size_t j = i + 1; j < solution_vector.size(); j++) {
				if ((solution_vector[i] - (i + 1))
						== (solution_vector[j] - (j + 1))) {
					h++;
					break;
				}
			}
		}
		//sum inverse diagonal
		for (size_t i = 0; i < solution_vector.size(); i++) {
			for (size_t j = i + 1; j < solution_vector.size(); j++) {
				if ((solution_vector[i] + (i + 1))
						== (solution_vector[j] + (j + 1))) {
					h++;
					break;
				}
			}
		}
		return h;
	}

	vector<int> neighbour(std::vector<int> solution_vector) {
		int64_t i = rand() % solution_vector.size() + 1;
		int64_t mov = (rand() % solution_vector.size() + 1);
		solution_vector[i - 1] = mov;

		return solution_vector;
	}

	void print_solution(const std::vector<int> &solution_vector) {
		for (int i = 0; i < solution_vector.size(); i++) {
			for (int j = 0; j < solution_vector.size(); j++) {
				if (j == solution_vector[i] - 1) {
					std::cout << " Q ";
				} else {
					std::cout << " _ ";
				}
			}
			std::cout << "\n";
		}

		std::cout << "\nSolucion: ";
		for (int x : solution_vector) {
			std::cout << x << " ";
		}
		std::cout << "\nCost:" << cost(solution_vector) << std::endl;
	}

	inline bool search_repeat(const std::vector<int> &prob_neighbor, const std::vector<std::vector<int>> &neighborhood) {
		return find(neighborhood.begin(), neighborhood.end(), prob_neighbor) != neighborhood.end();
	}
}


int main() {
	vector<int> current_solution = localsearch::initial_solution();
	vector<int> neighbor_solution;
	vector<vector<int>> neighborhood;
	int i = 0;
	do {
		while (localsearch::search_repeat(neighbor_solution = localsearch::neighbour(current_solution), neighborhood)) {}
		neighborhood.push_back(neighbor_solution);
		if (localsearch::cost(neighbor_solution) < localsearch::cost(current_solution)) {
			current_solution = neighbor_solution;
			i = 0;
			neighborhood.clear();
		} else {
			i++;
		}
	} while (i < number_neighbor);
	localsearch::print_solution(current_solution);
	//system("pause");
	return 0;
}
