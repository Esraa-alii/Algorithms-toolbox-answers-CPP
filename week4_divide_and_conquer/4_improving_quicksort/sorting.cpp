/******************************************************************************
 *
 * File Name: sorting.cpp
 *
 * Description: Answer for problem 4 in week 4 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

using std::swap;
using std::vector;

int partition2(vector<int> &vec, int left, int right) {
	int x = vec[left];
	int j = left;
	for (int i = left + 1; i <= right; i++) {
		if (vec[i] <= x) {
			j++;
			swap(vec[i], vec[j]);
		}
	}
	swap(vec[left], vec[j]);
	return j;
}

std::pair<int, int> partition3(vector<int> &vec, int left, int right) {
	int x = vec[left];
	int j = left;
	int k = right;
	for (int i = left; i <= right; i++) {
		if (vec[i] < x) {
			swap(vec[i], vec[j]);
			j++;
		}
	}
	for (int i = right; i >= left; i--) {
		if (vec[i] > x) {
			swap(vec[i], vec[k]);
			k--;
		}
	}

	for (int i = j; i <= k; i++) { vec[i] = x; }

	return std::make_pair(j, k);
}

void randomized_quick_sort(vector<int> &vec, int left, int right) {
	if (left >= right) { return; }

	int k = left + rand() % (right - left + 1);
	swap(vec[left], vec[k]);
	auto m = partition3(vec, left, right);

	randomized_quick_sort(vec, left, m.first - 1);
	randomized_quick_sort(vec, m.second + 1, right);
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) { std::cin >> a[i]; }
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) { std::cout << a[i] << ' '; }
}