#ifndef Kisi_HPP
#define Kisi_HPP
#include <iostream>
#include <fstream>
#include <string>
#include "node.hpp"

using namespace std;

class Kisi
{
private:
    node *head;
    node *tail;
    bool empty();
    int stackBoyutu;

public:
    Kisi();
    bool elemanVarmi(string ad);
    void stackEkle(string ad, int yuk, int der);
    void display();
    void addNode(string ad, int yas, int boy, int yuk, int der);
    void kisiEkle(string ad, int yas, int boy);
};

#endif