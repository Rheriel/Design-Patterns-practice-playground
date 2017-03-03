#pragma once
#include <string>
#include <iostream>
#include "Memento.h"

class Originator
{
public:
	Originator();
	~Originator();
	void set(std::string newArticle);
	Memento* storeInMemento();
	std::string restoreFromMemento(Memento memento);
protected:
	static const std::string MSG_ORIGIN_ORIGINATOR;
private:
	std::string _article;
};

