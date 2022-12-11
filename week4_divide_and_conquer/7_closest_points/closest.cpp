/******************************************************************************
 *
 * File Name: closest.cpp
 *
 * Description: Answer for problem 7 in week 4 (Algorithm toolbox coursera)
 *
 * Author: Esraa Ali
 *
 *******************************************************************************/

#include <math.h>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

//get the distance between 2 points 
//d=√((x2 – x1)² + (y2 – y1)²).
constexpr double distance(const pair<long long, long long>& vec1,
						  const pair<long long, long long>& vec2) {
	return sqrt((vec2.first - vec1.first) * (vec2.first - vec1.first) +
				(vec2.second - vec1.second) * (vec2.second - vec1.second));
}

double naive_minimal_distance(vector<pair<long long, long long>>& points) {
	double d = numeric_limits<double>::max();
	for (long long i = 0; i < points.size() - 1; i++) {
		for (long long j = i + 1; j < points.size(); j++) {
			d = min(d, distance(points[i], points[j]));
		}
	}
	return d;
}

bool less_than_on_x(pair<long long, long long>& vec1,
					pair<long long, long long>& vec2) {
	return (vec1.first == vec2.first) ? (vec1.second < vec2.second) : (vec1.first < vec2.first);
}

bool less_than_on_y(pair<long long, long long>& vec1,
					pair<long long, long long>& vec2) {
	return (vec1.second == vec2.second) ? (vec1.first < vec2.first) : (vec1.second < vec2.second);
}

void merge(vector<pair<long long, long long>>& points, long long low,
		   long long high) {
	if (low >= high) return;

	long long midPoint = low + (high - low) / 2;
	long long i = low, j = midPoint + 1;
	vector<pair<long long, long long>> vec;
	vec.reserve(high - low + 1);

	while (i <= midPoint and j <= high) {
		if (less_than_on_y(points[i], points[j])) {
			vec.emplace_back(points[i].first, points[i].second);
			i++;
		} else {
			vec.emplace_back(points[j].first, points[j].second);
			j++;
		}
	}
	while (i <= midPoint) {
		vec.emplace_back(points[i].first, points[i].second);
		i++;
	}
	while (j <= high) {
		vec.emplace_back(points[j].first, points[j].second);
		j++;
	}

	for (size_t counter = 0; counter < vec.size(); counter++) {
     points[low + counter] = vec.at(counter); 
     }
}

double minimal_distance(vector<pair<long long, long long>>& points,
						long long low, long long high) {
	if (low >= high) return numeric_limits<double>::max();
	if (high - low == 1) {
		if (not less_than_on_y(points[low], points[high])) {
			swap(points[low], points[high]);
		}
		return distance(points[low], points[high]);
	}

	long long mid = low + (high - low) / 2;
	auto mid_point = points.at(mid);  

	double Distance = min(minimal_distance(points, low, mid),
				   minimal_distance(points, mid + 1, high));

	vector<pair<long long, long long>> strip_points;

	merge(points, low, high);
	for (long long i = low; i <= high; i++) {
		if (abs(points[i].first - mid_point.first) <= Distance) {
			strip_points.emplace_back(points[i].first, points[i].second);
		}
	}

	for (long long i = 0; i < strip_points.size() - 1; i++) {
		for (long long j = i + 1; j < strip_points.size() and j - i < 8; j++) {
			Distance = min(Distance, distance(strip_points[i], strip_points[j]));
		}
	}
	return Distance;
}

int main() {
	size_t n;
	cin >> n;
	vector<pair<long long, long long>> points(n);
	long long x, y;
	for (size_t i = 0; i < n; i++) {
		cin >> x >> y;
		points[i] = make_pair(x, y);
	}
	sort(points.begin(), points.end(), &less_than_on_x);

	cout << fixed;
	cout << setprecision(9) << minimal_distance(points, 0, points.size() - 1)
		 << endl;
}