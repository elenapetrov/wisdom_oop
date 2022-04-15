#include "Header.h"
void saying::InData(ifstream& ifst) {
	ifst >> text;
	ifst >> country;
}
void saying::Out(ofstream& ofst) {
	ofst << "Text: " << text << endl;
	ofst << "It is a saying. Country: " << country << endl;
}
int saying::CountSymbols() {
	string symbols = ".,!?;";
	int cnt = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (symbols.find(text[i]) < symbols.length())cnt++;
	}
	return cnt;
}

void aphorism::InData(ifstream& ifst) {
	ifst >> text;
	ifst >> author;
}
void aphorism::Out(ofstream& ofst) {
	ofst << "Text: " << text << endl;
	ofst << "It is an aphorism. Author: " << author << endl;
}
int aphorism::CountSymbols() {
	string symbols = ".,!?;";
	int cnt = 0;
	for (int i = 0; i < text.length(); i++)
	{
		if (symbols.find(text[i]) < symbols.length())cnt++;
	}
	return cnt;
}
wisdom* wisdom::In(ifstream& ifst) {
	wisdom* sh;
	int k;
	ifst >> k;
	switch (k) {
	case 1:
		sh = new aphorism;
		break;
	case 2:
		sh = new saying;
		break;
	default:
		return 0;
	}
	sh->InData(ifst);
	return sh;
}

Node::Node(wisdom* newthought)
{
	thought = newthought;
	next = NULL;
	prev = NULL;
}
container::container()
{
	current = NULL;
	head = NULL;
	size = 0;
}
void container::Clear() {
	current = NULL;
	head = NULL;
	size = 0;
}

void container::In(ifstream& ifst) {
	while (!ifst.eof())
	{
		Node* newNode;
		newNode = new Node((wisdom::In(ifst)));
		if (head == NULL)
		{
			head = newNode;
			head->next = newNode;
			head->prev = newNode;
			size = 1;
		}
		else
		{
			current = head;

			while (current->next != head)
			{
				current = current->next;
			}
			current->next = newNode;
			current->next->prev = current;
			current = current->next;
			current->next = head;
			head->prev = current;

			size++;
		}
	}
}
void container::Out(ofstream& ofst) {
	ofst << "Container contents " << size
		<< " elements." << endl;
	int i = 1;
	if (head == NULL)
	{
		return;
	}
	current = head;
	do
	{
		ofst << i << ": ";
		current->thought->Out(ofst);
		ofst << "Count of punctuation marks: " << current->thought->CountSymbols() << endl;
		current = current->next;
		i++;
	} while (current != head);
}