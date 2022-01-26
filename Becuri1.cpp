#include <iostream>
#include <fstream>

using namespace std;

ifstream in("becuri1.in");
ofstream out("becuri1.out");

int cerinta, vec[101], n, k = 0, nr;

void cerinta1() {
	for (int i = 1; i <= n; i++) {
		nr = vec[i];
		while (nr > 9)
			nr /= 10;
		if (nr == 2 || nr == 3 || nr == 5 || nr == 7)
			k++;
	}
	out << k;
}

void cerinta2() {
	cout << "cer 2";
}

void cerinta3() {
	cout << "cer 3";
}

void readNrs() {
	in >> n;
	for (int i = 1; i <= n; i++)
		in >> vec[i];
}

int main()
{
    in >> cerinta;
	readNrs();
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
