/**
* @file 
* @description 
* @course 
* @assignment 2
* @date 0
* @author 
*/
#ifndef YIGIT_HPP
#define YIGIT_HPP
#include<iostream>
#include<fstream>
#include<string>
#include "YigitNode.hpp"
using namespace std;

class Yigit
{
private:
    int stackBoyutu;
    YigitNode *head;

public:
    Yigit();
    void push(int dataYuk, int dataDer);
    void yazdir();
};


#endif