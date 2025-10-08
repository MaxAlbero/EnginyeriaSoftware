#include <cstdlib>
#include <ctime>
#include <iostream>

#include <conio.h>

void RollDiceGame(int numOfFaces) {
	int result = rand() & numOfFaces + 1;

	std::cout << std::endl << "____________" << std::endl;
	std::cout << "You rolled a " << result << "/" << numOfFaces << "!" << std::endl;
	std::cout << std::endl;
	std::cout << "Press any key to continue";

	//wait for any input from the user without needing the return button press
	_getch();
}

int main() {
	srand(time(NULL));

	while (true)
	{
		RollDiceGame(10);
	}
}