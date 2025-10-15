#include <iostream>
#include <vector>

int main(){
	std::vector<int*> intVector;
	int* ptr = new int(2);
	intVector.push_back(ptr);

	std::cout << *intVector.begin();
	std::cout << **intVector.begin();
	std::cout << intVector.at(0);
	std::cout << *intVector.at(0);
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;
}