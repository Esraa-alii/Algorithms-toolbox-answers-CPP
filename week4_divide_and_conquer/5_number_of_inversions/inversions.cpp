/******************************************************************************
 *
 * File Name: inversions.cpp
 *
 * Description: Answer for problem 5 in week 4 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/
#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right)
{
	long long number_of_inversions = 0;
	if (right <= left + 1)
		return number_of_inversions;
	size_t average = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, average);
	number_of_inversions += get_number_of_inversions(a, b, average, right);
	size_t x = left, y = average, z = left;
	while (x < average and y < right)
	{
		if (a[x] > a[y])
		{
			number_of_inversions += right - y;
			b[z] = a[x];
			x++;
		}
		else
		{
			b[z] = a[y];
			y++;
		}
		z++;
	}
	while (x < average)
	{
		b[z] = a[x];
		z++;
		x++;
	}
	while (y < right)
	{
		b[z] = a[y];
		z++;
		y++;
	}
	std::copy(b.begin() + left, b.begin() + right, a.begin() + left);
	return number_of_inversions;
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
	vector<int> b(a.size());
	std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}