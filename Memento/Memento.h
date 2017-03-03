#pragma once
#include <string>

class Memento
{
public:
	Memento(std::string article) {
		this->_article = article;
	}
	std::string getSavedArticle();
	~Memento();
private:
	std::string _article;
};

