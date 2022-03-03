#pragma once

#include <iostream>
#include <vector>

template <typename TContainer, typename TValue = typename TContainer::value_type>
void insertSorted(TContainer& inputContainer, TValue inputValue)
{
	TValue thisValue, nextValue;
	for (auto it = inputContainer.begin(); it != inputContainer.end();)
	{
		thisValue = *it;
		++it;
		if (it == inputContainer.end()) 
		{ 
			inputContainer.push_back(inputValue);
			return;
		}
		nextValue = *it;
		if (thisValue < inputValue && inputValue <= nextValue) 
		{ 
			inputContainer.insert(it, inputValue); 
			return;
		}
		else if (inputValue < thisValue)
		{
			inputContainer.insert(inputContainer.begin(), inputValue);
			return;
		}
	}
}


template <typename TContainer>
void print(const TContainer& input) noexcept
{
	std::cout << std::endl;
	for (auto it : input) { std::cout << it << " "; }
}
