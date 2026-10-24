#include <iostream>
#include "func.hpp"
#include <cstdlib>
#include <ctime>

int main() {

	SetConsoleOutputCP(CP_UTF8);
	
	int max;
	int num;
	int request;
	int score;
	bool While;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	std::cin.exceptions(std::istream::failbit);

	while(true) {
		
		score = 0;
		While = true;
		
		try{
			std::cout << "До скольки число?" << std::endl;
			std::cin >> max;
			std::cout << "Угадай число" << std::endl;

			num = std::rand() % max + 1;

			while(While) {
				std::cin >> request;

				score++;

				if(num == request) {

					std::cout << "Угадал за " << score << " попыток" << std::endl;

					While = false;

				} else if(num > request) {

					std::cout << "Больше" << std::endl;

				} else {

					std::cout << "Меньше" << std::endl;
				}
			}
		} catch(const std::istream::failure& e) {
			func::setColor(4);

			std::cout << "Error";

			func::setColor(7);
			return 1;
		}
	}
	return 0;
}
