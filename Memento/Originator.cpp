#include "Originator.h"

const std::string Originator::MSG_ORIGIN_ORIGINATOR = "From Originator: ";

Originator::Originator()
{
}


Originator::~Originator()
{
}

void Originator::set(std::string newArticle)
{
	this->_article = newArticle;
	std::cout << MSG_ORIGIN_ORIGINATOR << "Current version of Article\n" << "[" << _article << "]" << std::endl;
}

Memento* Originator::storeInMemento()
{
	std::cout << MSG_ORIGIN_ORIGINATOR << "Saving to Memento." << std::endl;
	return new Memento(this->_article);
}

std::string Originator::restoreFromMemento(Memento memento)
{
	this->_article = memento.getSavedArticle();
	std::cout << MSG_ORIGIN_ORIGINATOR << "Previous Article saved in Memento\n" << "[" << _article << "]" << std::endl;
	return this->_article;
}
