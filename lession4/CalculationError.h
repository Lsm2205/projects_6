#pragma once
#include <algorithm>
#include <random>

template <typename T>
void randomFill(std::vector<T>& vec)
{
	T lower_bound = 0;
	T upper_bound = 99;
	std::random_device rd;
	std::mt19937_64 gen(rd());
	std::uniform_real_distribution<T> dis(lower_bound, upper_bound);
	auto rand = [&]() { return dis(gen); };
	std::generate(vec.begin(), vec.end(), rand);
}

double countError(const std::vector<double>& input);
