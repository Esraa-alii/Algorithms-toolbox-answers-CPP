/******************************************************************************
 *
 * File Name: binary_search.cpp
 *
 * Description: Answer for problem 1 in week 4 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/
#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>

using std::vector;

int binary_search(const vector<int> &vec, size_t left, size_t right, int x)
{
  // validation condition
  if (left < 0 or right > vec.size() or left > right)
    return -1;
  // initialize the mid
  size_t mid = left + (right - left) / 2;
  if (vec.at(mid) == x)
  {
    return mid;
  } // in case of mid -> bigger than x
  else if (vec.at(mid) > x)
  {
    // recursion but with the new right will be mid-1
    return binary_search(vec, left, mid - 1, x);
  }
  // in case of mid -> smaller than x
  else
  {
    // recursion but with the new left will be mid+1
    return binary_search(vec, mid + 1, right, x);
  }
}
// function to loop on the vector to find x
int linear_search(const vector<int> &a, int x)
{
  for (size_t i = 0; i < a.size(); ++i)
  {
    if (a[i] == x)
      return i;
  }
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i)
  {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i)
  {
    std::cout << binary_search(a, 0, a.size() - 1, b[i]) << ' ';
  }
}