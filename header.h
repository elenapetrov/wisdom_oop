#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class wisdom {
public:
	string text; // текст
	int rate;
	// иденитфикация, порождение и ввод фигуры из потока
	static wisdom* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ввод
	virtual void Out(ofstream& ofst) = 0; // вывод
	int CountSymbols();
	bool Compare(wisdom& p);
	virtual void OutAphorisms(ofstream& ofst) = 0;
};
class Node {
public:
	wisdom* thought;
	Node* next;
	Node* prev;
	Node(wisdom* newfigure);
	//~Node() {}
};
// афоризм
class aphorism : public wisdom {
	string author; // автор
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void OutAphorisms(ofstream& ofst);
	aphorism() {} // создание без инициализации.
};
// пословица
class saying : public wisdom {
	string country; // страна
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void OutAphorisms(ofstream& ofst);
	saying() {} // создание без инициализации.
};
class riddle : public wisdom {
	string answer; // ответ
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void OutAphorisms(ofstream& ofst);
	riddle() {} // создание без инициализации.
};
class container {
public:
	Node* current;
	int size;
	Node* head;

	void In(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	void OutCountOfSymbols(ofstream& ofst);
	void OutAphorisms(ofstream& ofst);
	void Clear(); // очистка контейнера от фигур
	void Sort();
	container(); // инициализация контейнера
	~container() { Clear(); } // утилизация контейнера
};