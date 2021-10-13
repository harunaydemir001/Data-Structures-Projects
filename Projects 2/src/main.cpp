/**
* @file main.cpp
* @description main
* @course 1-B
* @assignment 2
* @date 24/08/2021
* @author Harun Aydemir - B191210308
*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BST.hpp"
using namespace std;
int main()
{
    BST *Agac = new BST();
	string adiSoyad,satir,boy,yas;
	ifstream readFile("Deneme.txt");
	while (getline(readFile, satir)) {
		stringstream ss(satir);
		getline(ss, adiSoyad, '#');
		getline(ss, yas, '#');
		getline(ss, boy, '#');
		Agac->insert(adiSoyad, stoi(yas), stoi(boy));
	}
	readFile.close();
	Agac->yeniLevelOrder();
	delete Agac;
	return 0;
}