/******************************************************************************
 *
 * File Name: fibonacci_huge.cpp
 *
 * Description: Answer for problem 5 in week 2 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/

#include <iostream>

/*
function name        : pisano_period
function describtion : get the pisano period 
input                : m -> mod : f % m
return               : period -> pisona period after calculation  
*/
long pisano_period(long m)
{
    long previous = 0;
    long current = 1;
    long period = 0;
    for(int counter = 0; counter < m * m; counter++)
    {
        long temp = 0;
        temp = current;
        current = (previous + current) % m;
        previous = temp;
 
        if (previous == 0 && current == 1)
            period = counter+1;
    }
    return period;
}

/*
function name        : get_fibonacci_huge_optimize
function describtion : get specific fib num moduls specific num
input                : m -> mod , n-> nth of fib  : f(n) % m
return               : the result of the mod operation  
*/

long get_fibonacci_huge_optimize(long n, long m)
{
    long pisanoPeriod = pisano_period(m);
 
    n = n % pisanoPeriod;
    long prev = 0;
    long curr = 1;
    if (n == 0) 
        return 0;
    else if (n == 1) 
        return 1;
 
    for(int i = 0; i < n - 1; i++)
    {
        long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;
}
 
int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_optimize(n, m) << '\n';
    return 0;
    }