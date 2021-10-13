/**
* @file BST.cpp
* @description avl ağacı
* @course 1-B
* @assignment 2
* @date 24/08/2021
* @author Harun Aydemir - B191210308
*/
#include <iostream>
#include <fstream>
#include <string>
#include "BST.hpp"
#include "Kisi.hpp"
using namespace std;

void BST ::makeEmpty(nodeBST *t)
{
    if (t == NULL)
        return;
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
}

nodeBST *BST ::insert(string adi, int yasi, int x, nodeBST *t)
{
    if (t == NULL)
    {
        t = new nodeBST();
        t->ad = adi;
        t->yas = yasi;
        t->data = x;
        t->height = 0;
        t->left = t->right = NULL;
        t->kisi->kisiEkle(adi, yasi, x);
    }
    else if (x < t->data)
    {
        t->left = insert(adi, yasi, x, t->left);
        if (height(t->left) - height(t->right) == 2)
        {
            if (x < t->left->data)
                t = singleRightRotate(t);
            else
                t = doubleRightRotate(t);
        }
    }
    else if (x > t->data)
    {
        t->right = insert(adi, yasi, x, t->right);
        if (height(t->right) - height(t->left) == 2)
        {
            if (x > t->right->data)
                t = singleLeftRotate(t);
            else
                t = doubleLeftRotate(t);
        }
    }

    t->height = max(height(t->left), height(t->right)) + 1;
    return t;
}

nodeBST *BST ::singleRightRotate(nodeBST *&t)
{
    nodeBST *u = t->left;
    t->left = u->right;
    u->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    u->height = max(height(u->left), t->height) + 1;
    return u;
}

nodeBST *BST ::singleLeftRotate(nodeBST *&t)
{
    nodeBST *u = t->right;
    t->right = u->left;
    u->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    u->height = max(height(t->right), t->height) + 1;
    return u;
}
nodeBST *BST ::doubleLeftRotate(nodeBST *&t)
{
    t->right = singleRightRotate(t->right);
    return singleLeftRotate(t);
}

nodeBST *BST ::doubleRightRotate(nodeBST *&t)
{
    t->left = singleLeftRotate(t->left);
    return singleRightRotate(t);
}

int BST ::height(nodeBST *t)
{
    return (t == NULL ? -1 : t->height);
}

int BST ::getBalance(nodeBST *t)
{
    if (t == NULL)
        return 0;
    else
        return height(t->left) - height(t->right);
}

void BST ::levelOrder(nodeBST *t)
{
    if (t == NULL)
        return;
    cout << t->ad << " " << t->yas << " " << t->data << " ";
    levelOrder(t->left);
    levelOrder(t->right);
}
void BST ::yukseklik(nodeBST *t)
{
    if (t == NULL)
        return;
    cout << height(t) << " ";
    yukseklik(t->left);
    yukseklik(t->right);
}
int BST::Yukseklik(nodeBST *alt_Dugum) const
{
    if (alt_Dugum == NULL)
        return -1; // Ortada düğüm yoksa yükseklik anlamsızdır. Kodun çalışması adına -1 verilmektedir.
    return 1 + max(Yukseklik(alt_Dugum->left), Yukseklik(alt_Dugum->right));
}
int BST ::Yukseklik() const
{
    return Yukseklik(root);
}
void BST ::bilgileriGetir(nodeBST *t)
{
    if (t == NULL)
        return;
    t->kisi->stackEkle(t->ad,height(t), Yukseklik() - height(t));
    bilgileriGetir(t->left);
    bilgileriGetir(t->right);
}
void BST ::yazdir(nodeBST *t)
{
    if (t == NULL)
        return;
    t->kisi->display();
    cout << endl;
    yazdir(t->left);
    yazdir(t->right);
}

BST ::BST()
{
    root = NULL;
}
void BST ::yukseklikGetir()
{
    yukseklik(root);
}
void BST ::insert(string adi, int yasi, int x)
{

    root = insert(adi, yasi, x, root);
    bilgileriGetir(root);
}

void BST ::display()
{
    levelOrder(root);
    cout << endl;
}
void BST ::yaz()
{
    yazdir(root);
}
void BST::Seviye(nodeBST *alt_Dugum, int seviye)
{
    if (alt_Dugum == NULL)
        return;
    if (seviye == 0)
    {

        alt_Dugum->kisi->display();
        cout << endl;
    }
    else
    {
        Seviye(alt_Dugum->left, seviye - 1);
        Seviye(alt_Dugum->right, seviye - 1);
    }
}
void BST::yeniLevelOrder()
{
    int h = height(root);
    for (int level = 0; level <= h; level++)
    {
        Seviye(root, level);
    }
}
BST ::~BST()
{
    makeEmpty(root);
}