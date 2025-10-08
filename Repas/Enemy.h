#pragma once
#include <vector>
#include <list>
#include <string>
#include <fstream>

struct Weapon {
	char name[10];
	int power;
};

struct Enemy {
	char id;
	int x;
	float y;
	std::vector<Weapon> weapons;
};

extern std::list<Enemy> enemies;

void SaveEnemies(std::list<Enemy> e, std::string fileName) {
		//CopyPaste d'obrir l'arxiu
	std::ofstream output;
	output.open(fileName, std::ios::binary | std::ios::out | std::ios::trunc);
	if (!output.is_open())
	{
		return;
	}

	//1.Get the size of the vector
	int size = e.size();
	//2.Store the vector size inside the file
	output.write(reinterpret_cast<char*>(&size), sizeof(int)); //sizeof(size_t)

	for (std::list<Enemy>::iterator it = e.begin(); it != e.end(); it ++)
	{
		output.write(&it->id, sizeof(char));
		output.write(reinterpret_cast<char*>(&it->x), sizeof(int));
		output.write(reinterpret_cast<char*>(&it->y), sizeof(float));

		//*it es un punter cap a un enemy en la llista
		output.write(reinterpret_cast<char*>(&(*it)), 
			sizeof(char) + sizeof(int) + sizeof(float));

		//1 Get the size
		//2 Write the size
		//3 Write the vector
		int size = it->weapons.size();
		output.write(reinterpret_cast<char*>(&size), sizeof(int));
		output.write(reinterpret_cast<char*>(it->weapons.data()), sizeof(Weapon) * size);
	}
}

void RecoverEnemies(std::list<Enemy>& e, std::string fileName) {

}