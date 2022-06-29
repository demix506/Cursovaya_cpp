#include "bib.h"
using namespace std;

rab R[10];
int list = 0;



int inData() {
	cout << "������ ������� ������, �� ��������� �������\n>> ";
	cin >> list;
	for (int i = 0; i < list; i++) {
		cout << i + 1 << "� �����:\n";
		cout << "��� ��������� = "; cin >> R[i].NameCPU;
		cout << "������ �������� ����� = "; cin >> R[i].ModelMat;
		cout << "��� ��������� ���� ����� ( ��� ��������� � �NONAME�)"; cin >> R[i].NameGPU;
		cout << "��� HDD = "; cin >> R[i].NameHDD;
		cout << "������ HDD ( � ��) =  "; cin >> R[i].SizeHDD;
		cout << "ʳ������ ������ �� = "; cin >> R[i].QuantityRam;
		cout << "������ ���� ������ ��( � ��) = "; cin >> R[i].SizeRam;
		double A = R[i].SizeRam, B = R[i].QuantityRam;
		_asm {
			fld A
			fmul B
			fstp A
			fwait
		};

		R[i].GSizeRam = A;
	}
		
		


	return 0;
}

	int outData() {
	if (!list) { cout << "������� �����, �������� �������� ��.\n"; return -1; }
	for (int i = 0; i < list; i++) {
		cout << '\n' << i + 1 << "� �����:\n";
		cout << "\n��� ��������� = " << R[i].NameCPU;
		cout << "\n������ �������� �����; = " << R[i].ModelMat;
		cout << "\n��� ��������� ���� ����� = " << R[i].NameGPU;
		cout << "\n��� HDD; = " << R[i].NameHDD;
		cout << "\n������ HDD ( � ��) =  " << R[i].SizeHDD;
		cout << "\nʳ������ ������ �� = " << R[i].QuantityRam;
		cout << "\n������ ���� ������ ��( � ��). = " << R[i].SizeRam;
		cout << "\n������� ������ �� = " << R[i].GSizeRam;
	}
	return 0;
}

int inFile() {
	if(!list) { cout << "������� �����, �������� �������� ��.\n"; return -1; }
	string filename;
	cout << "������ ��'� �����\n>> "; cin >> filename;
	ofstream file(filename, ios_base::app);
	if (!file) {
		cout << "���� �� ��������.\n";
		return 0;
	}
	for (int i = 0; i < list; i++) {
		file << R[i].NameCPU << " " << R[i].ModelMat << " " << R[i].NameGPU << " " << R[i].NameHDD << " " << R[i].SizeHDD << " " << R[i].QuantityRam << " " << R[i].GSizeRam;
	}
	cout << "��� �������.\n";
	file.close();
	return 0;
}

int outFile() {
	string filename;
	cout << "������ ��'� �����\n>> "; cin >> filename;
	ifstream file(filename);
	if (!file) {
		cout << "���� �� ��������.\n";
		return 0;
	}
	int i = 0;
	while (1) {
		file >> R[i].NameCPU >> R[i].ModelMat >> R[i].NameGPU >> R[i].NameHDD >> R[i].SizeHDD >> R[i].QuantityRam >> R[i].GSizeRam;
		i++;
		if (file.tellg() == -1) { list = i; break; }
	}
	cout << "���� �������� (" << list << " ������).";
	file.close();
	return 0;
}
