#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>


struct rab {
    std::string NameCPU, ModelMat, NameGPU, NameHDD;
    double SizeHDD, QuantityRam, SizeRam, GSizeRam;
  //  double Z, P;
};

//13 4600 2 2 0
//0.5 * Z * (T/D)
//0.5 * 4600 * 2 / 13

int inData();
int outData();
int inFile();
int outFile();