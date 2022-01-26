#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream in("becuri1.in");
ofstream out("becuri1.out");

int cerinta, vec[101], n, k = 0, nr, maxK, maxNr = 0, maxNrPos, temp, nrCif[101], kTemp;

void rotateCif() {
	for (int i = 1; i <= n; i++) {
		temp = vec[i];
		if (temp != 0) {
			k = 0;
			while (temp > 0)
			{
				temp /= 10;
				k++;
			}
			if (k != nrCif[i])
				vec[i] = vec[i] * 10;
			else {
				kTemp = int(pow(10.0, nrCif[i] - 1));
				vec[i] = vec[i] % int(pow(10.0, nrCif[i] - 1)) * 10 + vec[i] / kTemp;
				cout << vec[i] << "\n";
			}
		}
	}
}

int cerinta1() {
	k = 0;
	for (int i = 1; i <= n; i++) {
		nr = vec[i];
		temp = nr;
		kTemp = 0;
		while (temp > 0) {
			temp /= 10;
			kTemp++;
		}
		if (kTemp == nrCif[i]) {
			while (nr > 9)
				nr /= 10;
			if (nr == 2 || nr == 3 || nr == 5 || nr == 7)
				k++;
		}
	}
	return k;
}

void cerinta2() {
	maxK = cerinta1();
	do
	{
		rotateCif();
		k = cerinta1();
		if (k > maxK)
			maxK = k;
	} while (maxNr != vec[maxNrPos]);
	out << maxK;
}

void cerinta3() {
	cout << "cer 3";
}

void readNrs() {
	in >> n;
	for (int i = 1; i <= n; i++) {
		in >> vec[i];
		if (vec[i] > maxNr) {
			maxNr = vec[i];
			maxNrPos = i;
		}
		temp = vec[i];
		nrCif[i] = 0;
		while (temp > 0) {
			temp /= 10;
			nrCif[i]++;
		}
	}
}

void defaultC() {
	/*for (int i = 1; i <= n; i++)
		cout << vec[i] << " " << nrCif[i] << "\n";
	rotateCif();
	for (int i = 1; i <= n; i++)
		cout << vec[i] << " " << nrCif[i] << "\n";
	rotateCif();
	for (int i = 1; i <= n; i++)
		cout << vec[i] << " " << nrCif[i] << "\n";*/
	for (int i = 0; i <= 10; i++)
		cout << int(pow(10.0, i)) << "\n";
}

int main()
{
    in >> cerinta;
	readNrs();
	switch (cerinta)
	{
	case 1:
		out << cerinta1();
		break;
	case 2:
		cerinta2();
		break;
	case 3:
		cerinta3();
		break;
	default:
		defaultC();
		break;
	}
}
