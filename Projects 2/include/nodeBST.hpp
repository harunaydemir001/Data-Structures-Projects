#ifndef nodeBST_HPP
#define nodeBST_HPP
#include<iostream>
#include<fstream>
#include<string>
#include "Kisi.hpp"

using namespace std;

class nodeBST
{
public:
    int data;
    nodeBST *left;
    nodeBST *right;
    int height;
    string ad;
    int yas;
    Kisi *kisi;
    nodeBST();
};

#endif