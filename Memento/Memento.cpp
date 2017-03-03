#include "Memento.h"

#include <string>
#include <iostream>

std::string Memento::getSavedArticle()
{
	return this->_article;
}

Memento::~Memento()
{
}
