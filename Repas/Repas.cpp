#include "GameObject.h"
#include <string>
#include <map>

#include <cassert>
#include <iostream>

std::vector<GameObject> gameObjects;

//Function Prototype
void SaveMap(std::map<std::string, int> m, std::string fileName);
void RecoverMap(std::map<std::string, int>& m, std::string fileName);

int main()
{
    SaveObjects(gameObjects, "objects.data");
    gameObjects.clear();
    RecoverObjects(gameObjects, "objects.data");

    std::map<std::string, int> myMap;

    try
    {
        SaveMap(myMap, "saveFile.dat");
    }
    catch (std::exception e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

void SaveMap(std::map<std::string, int> m, std::string fileName) {
    std::ofstream output;
    output.open(fileName, std::ios::binary | std::ios::out | std::ios::trunc);

    if (!output.is_open()) {
        throw std::exception("Could not open the file");
    }

    /* //assert
    //ASSERT stops the code IF expression = false
    assert(output.is_open());


    //DIY assert
    if (output.is_open())
    {
        std::cout << "Could not open file for writing" << std::endl;
        abort(); //Es l'equivalent a fer un assert(false);
    }
    */

    /*int* ptr = nullptr;
    assert(ptr);*/

    //Am I storing something dynamic?
    //IF YES -> Store size first
    size_t mapSize = m.size();
    output.write(reinterpret_cast<char*>(&mapSize), sizeof(size_t));

    //Is the memory of the value that I want to save sequential?
        //IF YES -> file.write
        //IF NO -> Iterate or transform into sequential memory
    for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); it++) {
        //Store KEY
        size_t stringSize = it->first.size();
        output.write(reinterpret_cast<char*>(&mapSize), sizeof(size_t));
        output.write(it->first.c_str(),stringSize);
        //Store VALUE
        output.write(reinterpret_cast<char*>(&it->second), sizeof(int));
    }
}
void RecoverMap(std::map<std::string, int>& m, std::string fileName) {
    std::ifstream input;
    input.open(fileName, std::ios::binary | std::ios::in);
    if(!input.is_open()) {
        throw std::exception("Could not open the file");
    }

    //read the map size
    size_t mapSize;
    input.read(reinterpret_cast<char*>(&mapSize), sizeof(size_t));
    //resize
    m.clear();
    for (int i = 0; i < mapSize; i++) {
        std::string key;
        int value;

        size_t stringSize;
        input.read(reinterpret_cast<char*>(&stringSize), sizeof(size_t));

        //Load a String
        char* temp = new char[stringSize + 1]; //necesito todo el size de string + 1 para el '\0'
        input.read(temp, stringSize);
        temp[stringSize] = '\0';
        key = temp; //un string que recibe un puntero a char y hace sus operaciones internas
        delete[] temp;

        input.read(reinterpret_cast<char*>(&value), sizeof(int));

        m.emplace(key, value);
    }
    //Add positions
        //Read KEY
            //Read string size
            //Read string
        //Read value
            //Rad int
}
