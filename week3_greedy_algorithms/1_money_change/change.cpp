/******************************************************************************
 *
 * File Name: change.cpp
 *
 * Description: Answer for problem 1 in week 3 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/

#include <iostream>

int get_change(int m) {
int n = m / 10;
	m %= 10;
	n += m / 5;
	m %= 5;
	n += m;
	return n;
}  


int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
