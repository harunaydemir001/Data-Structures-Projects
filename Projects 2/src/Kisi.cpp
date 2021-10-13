/**
* @file Kisi.cpp
* @description Kisi sinifi
* @course 1-B
* @assignment 2
* @date 24/08/2021
* @author Harun Aydemir - B191210308
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Kisi.hpp"
using namespace std;

bool Kisi ::empty()
{
    return head == NULL;
}
Kisi ::Kisi()
{
    stackBoyutu = 0;
    head = NULL;
    tail = NULL;
}
void Kisi ::kisiEkle(string ad, int yas, int boy)
{
    node *temp = new node();
    temp->ad = ad;
    temp->yas = yas;
    temp->boy = boy;
    temp->next = NULL;
    
    if (this->empty())
    {
        head = temp;
        tail = temp;
        temp = NULL;
        stackBoyutu++;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        stackBoyutu++;
    }
}
bool Kisi ::elemanVarmi(string ad)
{
    node *temp = head;
    for (int i = 0; i < stackBoyutu; i++)
    {
        if (ad == temp->ad)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
void Kisi ::stackEkle(string ad, int yuk, int der)
{
    node *temp = head;
    for (int i = 0; i < stackBoyutu; i++)
    {
        if (ad == temp->ad)
        {
            temp->yigit->push(yuk, der);
        }
        temp = temp->next;
    }
}
void Kisi ::display()
{
    node *temp = new node();
    temp = head;
    while (temp != NULL)
    {
        std::cout << temp->ad << " " << temp->yas << " " << temp->boy;
        temp->yigit->yazdir();
        cout << " ";
        temp = temp->next;
    }
}

void Kisi ::addNode(string ad, int yas, int boy, int yuk, int der)
{
    node *temp = new node();
    temp->ad = ad;
    temp->yas = yas;
    temp->boy = boy;
    temp->next = NULL;
    temp->yigit->push(yuk, der);
    if (this->empty())
    {
        head = temp;
        tail = temp;
        temp = NULL;
        stackBoyutu++;
    }
    else
    {
        tail->next = temp;
        tail = temp;
        stackBoyutu++;
    }
}