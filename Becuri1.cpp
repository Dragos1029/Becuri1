#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream in("becuri1.in");
ofstream out("becuri1.out");

int cerinta, vec[101], n, k = 0, nr, maxK, maxNr = 0, maxNrPos, temp, nrCif[101], kTemp, maxBec[101], maxBecI = 0;

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
			if (nr == 2 || nr == 3 || nr == 5 || nr == 7) {
				k++;
				maxBec[i]++;
				if(maxBec[i] > maxBecI)
					maxBecI = maxBec[i];
			}
		}
	}
	return k;
}

void cerinta2() {
	maxK = cerinta1();
	for (int i = 1; i < nrCif[maxNrPos]; i++) {
		rotateCif();
		k = cerinta1();
		if (k > maxK)
			maxK = k;
	}
	out << maxK;
}

void cerinta3() {
	cerinta1();
	for (int i = 1; i < nrCif[maxNrPos]; i++) {
		rotateCif();
		cerinta1();
	}
	if (maxBecI > 0) {
		for (int i = 1; i <= n; i++)
			if (maxBec[i] == maxBecI)
				out << i << " ";
	}
	else out << "-1";
}

void readNrs() {
	in >> n;
	for (int i = 1; i <= n; i++) {
		in >> vec[i];
		maxBec[i] = 0;
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
		break;
	}
}
