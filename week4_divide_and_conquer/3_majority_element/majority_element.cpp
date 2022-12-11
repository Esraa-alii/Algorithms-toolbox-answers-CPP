/******************************************************************************
 *
 * File Name: APluseB.cpp
 *
 * Description: Answer for problem 3 in week 4 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long get_majority_element(vector<long> &vec, int left, int right) {
  // in case of right = left -> return left
	if (left == right) { return vec[left]; }
  //in case of right = left+1 
	if (left + 1 == right) {
    // left and right are not similar -> -1 
		if (vec[left] != vec[right]) return -1;
    // left and right are similar -> left
		else
			return vec[left];
	}
  //initialize the mid
	int mid = left + (right - left) / 2;
	int count_x = 0, count_y = 0;

	long x = get_majority_element(vec, left, mid);
	long y = get_majority_element(vec, mid + 1, right);

	for (int i = left; i <= right; i++) {
		if (x == vec.at(i)) {
			count_x++;
		} else if (y == vec.at(i)) {
			count_y++;
		}
	}

	int n = right - left + 1;

	if (count_x > count_y and count_x > n / 2) return x;
	if (count_x < count_y and count_y > n / 2) return y;

	return -1;
}

int main() {
	int n;
	std::cin >> n;
	vector<long> a(n);
	for (size_t i = 0; i < a.size(); ++i) { std::cin >> a[i]; }
	std::cout << (get_majority_element(a, 0, a.size() - 1) != -1) << '\n';
}