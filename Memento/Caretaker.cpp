#include "Caretaker.h"
#include <iostream>
#include <vector>

Caretaker::Caretaker()
{
}


Caretaker::~Caretaker()
{
}

void Caretaker::addMemento(Memento memento)
{
	savedArticles.push_back(memento);
}

Memento Caretaker::getMemento(int index)
{
	std::cout << "Retrieving memento at index: " << index << std::endl;
	return this->savedArticles[index];
}
