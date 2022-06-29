#include "bib.h"
using namespace std;

rab R[10];
int list = 0;



int inData() {
	cout << "Введіть кількість записів, що необхідно зробити\n>> ";
	cin >> list;
	for (int i = 0; i < list; i++) {
		cout << i + 1 << "й запис:\n";
		cout << "Тип процесора = "; cin >> R[i].NameCPU;
		cout << "Модель системної плати = "; cin >> R[i].ModelMat;
		cout << "Тип дискретної відео карти ( при відсутності – «NONAME»)"; cin >> R[i].NameGPU;
		cout << "Тип HDD = "; cin >> R[i].NameHDD;
		cout << "Ємність HDD ( у Гб) =  "; cin >> R[i].SizeHDD;
		cout << "Кількість планок ОП = "; cin >> R[i].QuantityRam;
		cout << "Ємність однієї планки ОП( у Гб) = "; cin >> R[i].SizeRam;
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
	if (!list) { cout << "Таблиця пуста, спочатку заповніть її.\n"; return -1; }
	for (int i = 0; i < list; i++) {
		cout << '\n' << i + 1 << "й запис:\n";
		cout << "\nТип процесора = " << R[i].NameCPU;
		cout << "\nМодель системної плати; = " << R[i].ModelMat;
		cout << "\nТип дискретної відео карти = " << R[i].NameGPU;
		cout << "\nТип HDD; = " << R[i].NameHDD;
		cout << "\nЄмність HDD ( у Гб) =  " << R[i].SizeHDD;
		cout << "\nКількість планок ОП = " << R[i].QuantityRam;
		cout << "\nЄмність однієї планки ОП( у Гб). = " << R[i].SizeRam;
		cout << "\nЗагалом ємність ОП = " << R[i].GSizeRam;
	}
	return 0;
}

int inFile() {
	if(!list) { cout << "Таблиця пуста, спочатку заповніть її.\n"; return -1; }
	string filename;
	cout << "Введіть ім'я файлу\n>> "; cin >> filename;
	ofstream file(filename, ios_base::app);
	if (!file) {
		cout << "Файл не відкрився.\n";
		return 0;
	}
	for (int i = 0; i < list; i++) {
		file << R[i].NameCPU << " " << R[i].ModelMat << " " << R[i].NameGPU << " " << R[i].NameHDD << " " << R[i].SizeHDD << " " << R[i].QuantityRam << " " << R[i].GSizeRam;
	}
	cout << "Дані записані.\n";
	file.close();
	return 0;
}

int outFile() {
	string filename;
	cout << "Введіть ім'я файлу\n>> "; cin >> filename;
	ifstream file(filename);
	if (!file) {
		cout << "Файл не відкрився.\n";
		return 0;
	}
	int i = 0;
	while (1) {
		file >> R[i].NameCPU >> R[i].ModelMat >> R[i].NameGPU >> R[i].NameHDD >> R[i].SizeHDD >> R[i].QuantityRam >> R[i].GSizeRam;
		i++;
		if (file.tellg() == -1) { list = i; break; }
	}
	cout << "Файл прочитан (" << list << " записів).";
	file.close();
	return 0;
}
