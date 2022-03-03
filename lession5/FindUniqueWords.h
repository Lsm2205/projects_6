#pragma once

#include <iostream>
#include <string>
#include <set>

template <typename T>
void findUniqueWords(T itBegin, T itEnd)
{
	std::set<std::string> words;
	std::string word = "";
	char truncationSymbol = ' ';
	for (T it = itBegin; it != itEnd; ++it)
	{
		if (*it != truncationSymbol) { word += *it; }
		else if (word != ""){ 
			words.insert(word);
			word = "";
		}
	}
	if (word != "") { words.insert(word); }
	for (auto it = words.begin(); it != words.end(); ++it)
	{
		std::cout << *it << " ";
	}
}
