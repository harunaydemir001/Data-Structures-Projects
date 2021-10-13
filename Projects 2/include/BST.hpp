#ifndef BST_HPP
#define BST_HPP
#include<iostream>
#include<fstream>
#include<string>
#include "nodeBST.hpp"

using namespace std;

class BST
{
    int agacYuksekligi;
    nodeBST *root;
    void makeEmpty(nodeBST *t);

    nodeBST *insert(string adi, int yasi, int x, nodeBST *t);
    nodeBST *singleRightRotate(nodeBST *&t);
    nodeBST *singleLeftRotate(nodeBST *&t);
    nodeBST *doubleLeftRotate(nodeBST *&t);
    nodeBST *doubleRightRotate(nodeBST *&t);
    int height(nodeBST *t);
    int getBalance(nodeBST *t);
    void levelOrder(nodeBST *t);
    void yukseklik(nodeBST *t);
    void bilgileriGetir(nodeBST *t);
    void yazdir(nodeBST *t);
    void Seviye(nodeBST *, int );
    int Yukseklik(nodeBST *)const;
    int Yukseklik()const;
public:
    BST();
    void yukseklikGetir();
    void yeniLevelOrder();
    void insert(string adi, int yasi, int x);
    void display();
    void yaz();
    ~BST();
};

#endif