#include <mutex>
#include <iostream>
#include <set>

#pragma once

namespace Homework {

	typedef std::basic_ostream<char, std::char_traits<char>> CoutType;
	typedef CoutType& (StandardEndLine)(CoutType&);

	class pcout {
	private:
		std::mutex* mtx;
	public:
		pcout(std::mutex* m);
		~pcout();

		pcout& operator<<(int val);
		pcout& operator<<(std::string val);
		pcout& operator<<(StandardEndLine manip);
	};


	void startOwner(std::multiset<int>& items, std::mutex* m);
	void startThief(std::multiset<int>& items, std::mutex* m);
	void showThings(std::multiset<int>& items);
}
