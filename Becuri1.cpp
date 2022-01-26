#include <iostream>
#include <fstream>

using namespace std;

ifstream in("becuri1.in");
ofstream out("becuri1.out");

int cerinta, vec[101];

void cerinta1() {
	cout << "cer 1";
}

void cerinta2() {
	cout << "cer 2";
}

void cerinta3() {
	cout << "cer 3";
}

int main()
{
    in >> cerinta;
	switch (cerinta)
	{
	case 1:
		cerinta1();
		break;
	case 2:
		cerinta2();
		break;
	case 3:
		cerinta3();
		break;
	default:
		break;
	}
}
