/******************************************************************************
 *
 * File Name: gcd.cpp
 *
 * Description: Answer for problem 3 in week 2 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/

#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}
int gcd_optimaize(long long x, long long y) {
    long long a = std::max(x, y);
    long long b = std::min(x, y);
    if (b == 0)
        return a;
    else
        return gcd_optimaize(b, a % b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_optimaize(a, b) << std::endl;
  return 0;
}
