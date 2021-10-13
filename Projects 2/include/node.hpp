#ifndef NODE_HPP
#define NODE_HPP
#include<iostream>
#include<fstream>
#include<string>
#include "Yigit.hpp"
using namespace std;

class node
{
public:
    int yas;
    int boy;
    string ad;
    node *next;
    Yigit *yigit;
    node();
};

#endif