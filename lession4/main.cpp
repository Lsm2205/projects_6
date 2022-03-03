#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "InsertSorted.h"
#include "CalculationError.h"

int main()
{
	int testValue = 11;
	std::vector < double > arr = { 2.2, 4.8, 5.3, 8.1, 10.0, 12.5, 31.2 };
	std::list<int> list = { 2, 4, 5, 8, 10, 12, 31 };

	std::cout << "Test value = " << testValue << std::endl;
	std::cout << "\nList:";
	print(list);
	insertSorted(list, testValue);
	print(list);
	std::cout << "\nVector:";
	print(arr);
	insertSorted(arr, testValue);
	print(arr);

  //2
	int size = 100;
	std::vector<double> analog(size);
	randomFill(analog);
	std::cout << "\n\nAnalog vector:";
	print(analog);
	std::vector<int> digital(size);
	std::copy(analog.begin(), analog.end(), digital.begin());
	std::cout << "\nDigital vector:";
	print(digital);
	std::cout << "\n\nError value: " << countError(analog);
}
