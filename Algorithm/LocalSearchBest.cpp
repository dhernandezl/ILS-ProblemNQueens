/*
 * LocalSearchSet.cpp
 *
 *  Created on: 28 jul. 2020
 *      Author: DHL-SIS-ING
 */


#include "LocalSearchBest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <time.h>
#include <map>
#include <set>

#define NREINAS 16
#define t_neighbor 1
#define s_neighbor 15
using namespace std;
vector<vector<int>> neighbour_sys;
vector<vector<int>> neighborhood;

struct comp
{
	template<typename T>
	bool operator()(const T& l, const T& r) const
	{
		if (l.second != r.second)
			return l.second < r.second;

		return l.first < r.first;
	}
};

inline bool searchrepet(vector<int> q, const vector<vector<int>>& s) {
	return find(s.begin(), s.end(), q) != s.end();
}

void print_vector(vector<int> s) {
	for (int x : s) { printf("%d ", x); }
	printf("\n");
}

vector<int> initial_solution() {
	vector<int> solution;
	int queens = 0;
	srand(time(NULL));
	for (size_t i = 0; i < NREINAS; i++)
	{
		solution.push_back(rand() % NREINAS + 1);
	}
	return solution;
}

int cost(vector<int> queens_sol) {
	int h = 0;
	vector<int> aux_sol;
	//sum column
	for (size_t i = 0; i < NREINAS; i++)
	{
		for (size_t j = i + 1; j < NREINAS; j++)
		{
			if (queens_sol[i] == queens_sol[j])
			{
				h++;
				break;
			}
		}
	}
	//sum diagonal
	for (size_t i = 0; i < NREINAS; i++)
	{
		aux_sol.push_back(queens_sol[i] - (i + 1));
	}
	for (size_t i = 0; i < NREINAS; i++)
	{
		for (size_t j = i + 1; j < NREINAS; j++)
		{
			if (aux_sol[i] == aux_sol[j])
			{
				h++;
				break;
			}
		}
	}
	aux_sol.clear();
	//sum inverse diagonal
	for (size_t i = 0; i < NREINAS; i++)
	{
		aux_sol.push_back(queens_sol[i] + (i + 1));
	}
	for (size_t i = 0; i < NREINAS; i++)
	{
		for (size_t j = i + 1; j < NREINAS; j++)
		{
			if (aux_sol[i] == aux_sol[j])
			{
				h++;
				break;
			}
		}
	}

	return h;
}

void print_solution(vector<int> s) {
	char table[NREINAS][NREINAS] = {};
	for (size_t i = 0; i < NREINAS; i++)
	{
		table[i][s[i] - 1] = 'Q';
	}
	for (size_t i = 0; i < NREINAS; i++)
	{
		for (size_t j = 0; j < NREINAS; j++)
		{
			if (table[i][j] != 'Q')
			{
				printf(" _ ");
			}
			else { printf(" %c ", table[i][j]); }
		}
		printf("\n");
	}
	printf("\nSolucion: ");
	for (int x : s)
	{
		printf("%d ", x);
	}
	printf("\nCosto: ");
	printf("%d ", cost(s));
	printf("\n");
}

map<vector<int>, int> set_neighbour(vector<int> init_sol, int num_neig) {
	vector<vector<int>> set;
	vector<int> aux_init_sol;
	int j = 0;
	while (j < num_neig) {
		aux_init_sol = init_sol;
		srand(time(NULL));
		int i = rand() % NREINAS + 1;
		srand(time(NULL));
		int mov = (rand() % NREINAS + 1) - i;
		mov = (mov < 0) ? mov *= -1 : mov;
		mov = (mov == 0) ? mov = 1 : mov;
		aux_init_sol[i - 1] = mov;
		if (!searchrepet(aux_init_sol, set))
		{
			set.push_back(aux_init_sol);
			//print_vector(aux_init_sol);
			j++;
		}
	}
	map<vector<int>, int> set_f;
	for (int i = 0; i < set.size(); i++)
	{
		set_f[set[i]] = cost(set[i]);
	}
	return set_f;
}

vector<int> best_neighbour(map<vector<int>, int> n_sys){
	set<std::pair<vector<int>,int>, comp> set(n_sys.begin(), n_sys.end());
	for (auto const &pair: set) {
		return pair.first;
	}
}

int main() {
	vector<int> s = initial_solution();
	vector<int> ns;
	printf("\nSolucion inicial: ");
	print_vector(s);
	printf("h: %d", cost(s));
	printf("\n");
	map<vector<int>, int> n_s;
	int i = 0;
	do {
		n_s = set_neighbour(s, s_neighbor);
		ns = best_neighbour(n_s);
		if(cost(s) > cost(ns)){
			s = ns;
			print_vector(s);
			printf("h: %d", cost(s));
			printf("\n");
		}else{ i++; }
	} while (i < t_neighbor);
	printf("\n");
	print_solution(s);
	//system("pause");
	return 0;
}
