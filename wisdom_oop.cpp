// ConsoleApplicationtimp1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Header.h"
using namespace std;
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command in_file out_file"
			<< endl;
		exit(1);
	}
	ifstream ifst(argv[1]); //ifstream ifst("in.txt");
	ofstream ofst(argv[2]); //ofstream ofst("out.txt");
	cout << "Start" << endl;
	container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;
	c.Out(ofst);
	ofst << "Only aphorisms: " << endl;
	c.OutAphorisms(ofst);
	c.Clear();
	ofst << "Empty container. " << endl;
	c.Out(ofst);
	cout << "Stop" << endl;
	return 0;
}
