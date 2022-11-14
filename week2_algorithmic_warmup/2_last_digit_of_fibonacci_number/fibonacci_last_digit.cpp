/******************************************************************************
 *
 * File Name: fibonacci_last_digit.cpp
 *
 * Description: Answer for problem 2 in week 2 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/

#include <iostream>

int get_fibonacci_last_digit_optimaized(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_optimaized(n);
    std::cout << c << '\n';
    }
