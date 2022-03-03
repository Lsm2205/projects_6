#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include "SortLines.h"
#include "FindUniqueWords.h"

int main()
{
  //1
	std::cout << "String (random access iterator): ";
	std::string test = "aaaa bbbbbbbb aaa aaaa bbbb aa ccccc ccccc cccccc";
	findUniqueWords(test.begin(), test.end());
	std::cout << "\nVector (const random access iterator): ";
	const std::vector<char> test2 = { 'c', 'c', 'c', ' ', 'a', 'a', 'a', ' ', 'c', 'c', 'c' };
	findUniqueWords(test2.begin(), test2.end());
	std::cout << "\nList (bidirectional iterator): ";
	std::list <char> test3 = { 'c', 'c', 'c', ' ', 'a', 'a', 'a', ' ', 'c', 'c', 'c' };
	findUniqueWords(test3.begin(), test3.end());
	std::cout << "\nForward list (forward iterator): ";
	std::forward_list<char> test4 = { 'c', 'c', 'c', ' ', 'a', 'a', 'a', ' ', 'c', 'c', 'c' };
	findUniqueWords(test4.begin(), test4.end());
	std::cout << "\n\nTask 2:\n";
  //2
	SortLines();

}
