#pragma once
#include <string>
#include <iostream>
#include "Memento.h"
#include "Caretaker.h"
#include "Originator.h"

using namespace std;

void init();
int displayMenu();
void viewCurrentArticle();
void addNewArticle();
void undoLatestArticleChange();

int numberOfArticleChanges = 0;

Originator originator;
Caretaker caretaker;

int main(){

	init();

	displayMenu();

	return 0;
}

void init() {
	string initialArticle = "This is the first article.";
	originator.set(initialArticle);
	Memento* initialMemento = originator.storeInMemento();
	caretaker.addMemento(*initialMemento);
}

int displayMenu() {
	int option = 0;
	while (option != 4) {
		cout << "Menu: " << endl;
		cout << "1.- View current article." << endl;
		cout << "2.- Add new article." << endl;
		cout << "3.- Undo latest article change." << endl;
		cout << "4.- Exit" << endl;
		cout << "\n Please enter an option: ";
		cin >> option;
		cout << "\n";

		switch (option) {
		case 1:
			viewCurrentArticle();
			break;
		case 2:
			addNewArticle();
			break;
		case 3:
			undoLatestArticleChange();
			break;
		case 4:
			return 0;			
		default:
			displayMenu();
			break;
		}
	}
}

void viewCurrentArticle() {
	Memento newMemento = caretaker.getMemento(numberOfArticleChanges);
	cout << "Current article: " << newMemento.getSavedArticle() << endl;
}

void addNewArticle() {
	// TODO Modify so if it adds new changes between existing history it will override.
	cout << "\nType a new article: " << endl;

	string newArticle;
	cin.ignore();
	getline(cin, newArticle);

	cout << "Adding changes to the main article..." << endl;


	originator.set(newArticle);
	Memento* newMemento = originator.storeInMemento();

	caretaker.addMemento(*newMemento);
	numberOfArticleChanges++;

	cout << "Changes saved." << endl;
}

void undoLatestArticleChange() {
	if (numberOfArticleChanges > 0) {
		Memento previousMemento = caretaker.getMemento(numberOfArticleChanges--);
		cout << "Current article: " << originator.restoreFromMemento(previousMemento) << endl;
	}
	else {
		cout << "No previous article changes found." << endl;
	}
}