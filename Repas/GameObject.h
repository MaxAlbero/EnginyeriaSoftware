#pragma once
#include <vector>
#include <fstream>

struct GameObject {
	char type;
	int x;
	int y;
};

//variable global dins d'un header
//EXTERN
extern std::vector<GameObject> gameObjects;

void SaveObjects(std::vector<GameObject> o, std::string fileName) {
	std::ofstream output;
	output.open(fileName, std::ios::binary | std::ios::out | std::ios::trunc);
	if (!output.is_open())
	{
		return;
	}

	//1.Get the size of the vector
	int size = o.size();
	//2.Store the vector size inside the file
	output.write(reinterpret_cast<char*>(&size), sizeof(int)); //sizeof(size_t)
	//3.Store the entire vector using std::vector<GameObject>.data;
	output.write(reinterpret_cast<char*>(o.data()), sizeof(GameObject) * size);
}

void RecoverObjects(std::vector<GameObject>& o, std::string fileName) {
	std::ifstream input;
	input.open(fileName, std::ios::binary | std::ios::in);
	if (input.is_open())
	{
		return;
	}

	int size;
	input.read(reinterpret_cast<char*>(&size), sizeof(int));

	o.resize(size);
	input.read(reinterpret_cast<char*>(o.data()), sizeof(GameObject) * size);
}