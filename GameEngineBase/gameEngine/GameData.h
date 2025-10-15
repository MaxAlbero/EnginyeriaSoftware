#pragma once
#include <math.h>
class GameData {
private:
	int numberOfFaces;
public:
	GameData() : numberOfFaces(3) {}
	GameData(int numberOfFaces) {
		SetNumberOfFaces(numberOfFaces);
	}
	int const GetNumberOfFaces() { return numberOfFaces; }
	void SetNumberOfFaces(int value) { 
		int temp = (int)fmax(3, value);
		numberOfFaces = temp;
		if (value < 3)
		{
			throw "Dice faces was set to three because the input was too small";
		}
	}
};