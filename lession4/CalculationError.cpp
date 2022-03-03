#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

double countError(const std::vector<double>& input)
{
	double sum = std::accumulate(input.begin(), input.end(), 0.f, [](double currentSum, double const& value) {return currentSum + pow((value - (int)value), 2); });
	return sum;
}
