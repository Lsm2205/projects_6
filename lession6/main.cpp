#include <mutex>
#include <iostream>
#include <iterator>
#include <thread>
#include <chrono>
#include "Homework.h"

namespace Homework {

	pcout::pcout(std::mutex* m) {
		mtx = m;
		mtx->lock();
	}
	pcout::~pcout() {
		mtx->unlock();
	}

	pcout& pcout::operator<<(int val) {
		std::cout << val;
		return *this;
	}
	pcout& pcout::operator<<(std::string val) {
		std::cout << val;
		return *this;
	}
	pcout& pcout::operator<<(StandardEndLine manip) {
		manip(std::cout);
		return *this;
	}


	using namespace std::chrono_literals;
	void startOwner(std::multiset<int>& things, std::mutex* m) {
		std::this_thread::sleep_for(500ms);
		std::cout << "Owner spawned" << std::endl;

		int randThing;
		bool isBring;
		while (true) {
			isBring = (rand() % 100) < 33;
			if (isBring) {
				m->lock();
				randThing = rand() % 50000;
				things.insert(randThing);
				m->unlock();

				std::cout << "Владелец принес вещь " << randThing << std::endl;
				showThings(things);
			}
			std::this_thread::sleep_for(900ms);
		}
	}
	void startThief(std::multiset<int>& things, std::mutex* m) {
		std::this_thread::sleep_for(2s);
		std::cout << "Вор" << std::endl;

		bool isSteal;
		while (true) {
			isSteal = (rand() % 100) < 20;
			if (isSteal) {
				m->lock();
				int stolen = *(things.end());
				things.erase(things.size() - 1);
				m->unlock();

				std::cout << "Вор украл вещь " << stolen << std::endl;
				showThings(things);
			}
			std::this_thread::sleep_for(2900ms);
		}
	}
	void showThings(std::multiset<int>& things) {
		std::cout << "Вещи: ";
		copy(things.begin(), things.end(), std::ostream_iterator<double>{std::cout, " "});
		std::cout << std::endl;
	}
}
