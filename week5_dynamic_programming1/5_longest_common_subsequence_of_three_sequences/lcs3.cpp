/******************************************************************************
 *
 * File Name: lcs3.cpp
 *
 * Description: Answer for problem 5 in week 5 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

int lcs3(vector<int> &vec1, vector<int> &vec2, vector<int> &vec3)
{
  int seq[vec1.size() + 1][vec2.size() + 1][vec3.size() + 1];
  for (size_t i = 0; i <= vec1.size(); i++)
  {
    for (size_t j = 0; j <= vec2.size(); j++)
    {
      for (size_t k = 0; k <= vec3.size(); k++)
      {
        seq[i][j][k] = 0;
      }
    }
  }
  for (int i = 1; i <= vec1.size(); i++)
  {
    for (int j = 1; j <= vec2.size(); j++)
    {
      for (int k = 1; k <= vec3.size(); k++)
      {
        if (vec1[i - 1] == vec2[j - 1] and vec2[j - 1] == vec3[k - 1])
        {
          seq[i][j][k] = 1 + seq[i - 1][j - 1][k - 1];
        }
        else
        {
          seq[i][j][k] =
              max(seq[i][j][k - 1],
                  max(seq[i][j - 1][k],
                      max(seq[i - 1][j][k],
                          max(seq[i][j - 1][k - 1],
                              max(seq[i - 1][j][k - 1],
                                  max(seq[i - 1][j - 1][k],
                                      seq[i - 1][j - 1][k - 1]))))));
        }
      }
    }
  }
  return seq[vec1.size()][vec2.size()][vec3.size()];
}

int main()
{
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++)
  {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++)
  {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++)
  {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}