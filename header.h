#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class wisdom {
public:
	// иденитфикация, порождение и ввод фигуры из потока
	static wisdom* In(ifstream& ifst);
	virtual void InData(ifstream& ifst) = 0; // ввод
	virtual void Out(ofstream& ofst) = 0; // вывод
	virtual int CountSymbols() = 0;
	bool Compare(wisdom& p);
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
	string text; // текст
	string author; // автор
	int rate;
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	int CountSymbols();
	aphorism() {} // создание без инициализации.
};
// пословица
class saying : public wisdom {
	string text; // текст
	string country; // страна
	int rate;
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
	int CountSymbols();
	saying() {} // создание без инициализации.
};
class riddle : public wisdom {
	string text; // текст
	string answer; // ответ
	int rate;
public:
	// переопределяем интерфейс класса
	void InData(ifstream& ifst); // ввод
	void Out(ofstream& ofst); // вывод
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
	void Clear(); // очистка контейнера от фигур
	void Sort();
	container(); // инициализация контейнера
	~container() { Clear(); } // утилизация контейнера
};