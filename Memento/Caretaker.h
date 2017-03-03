#pragma once
#include <vector>
#include "Memento.h"

class Memento;

class Caretaker
{
public:
	Caretaker();
	~Caretaker();
	void addMemento(Memento memento);
	Memento getMemento(int index);

private:
	std::vector<Memento> savedArticles;
};

