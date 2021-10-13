/**
* @file Yigit.cpp
* @description Yigit sinifi
* @course 1-B
* @assignment 2
* @date 24/08/2021
* @author Harun Aydemir - B191210308
*/
#include<iostream>
#include<fstream>
#include<string>
#include "Node.hpp"
#include "Yigit.hpp"
#include "YigitNode.hpp"
using namespace std;

	Yigit :: Yigit()
    {
        stackBoyutu = 0;
        head = NULL;
    }
    void Yigit :: push(int dataYuk, int dataDer)
    {
        YigitNode *yeni = new YigitNode();
        yeni->yukseklik = dataYuk;
        yeni->derinlik = dataDer;
        yeni->sonraki = head;
        head = yeni;
        stackBoyutu++;
    }
    void Yigit :: yazdir()
    {
        YigitNode *ustTutan = head;
        cout << "Y"
             << "(";
        for (int i = 1; i <= stackBoyutu; i++)
        {
            cout << ustTutan->yukseklik;
            if (i == stackBoyutu)
                continue;
            cout << ",";
            ustTutan = ustTutan->sonraki;
        }
        cout << "),D(";
        ustTutan = head;
        for (int i = 1; i <= stackBoyutu; i++)
        {
            cout << ustTutan->derinlik;
            if (i == stackBoyutu)
                continue;
            cout << ",";
            ustTutan = ustTutan->sonraki;
        }
        cout << ") ";
    }