#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include "linkedList.h"
/**
* @linkedList.cpp
* @linkedList
* @Zorunlu 1/B
* @1
* @10.08.2021
* @Harun Aydemir linkedList.cpp
*/
using namespace::std;
void addNode(Node** head_reference, int _value)
{
    Node* new_node = new Node();
    new_node->value = _value;
    new_node->prev = NULL;
    new_node->next = (*head_reference);
    if((*head_reference) != NULL)
    {
    	(*head_reference)->prev = new_node ;
	}
    (*head_reference) = new_node;
}
void printList(Node *node)
{
	Node* temp = node;
    while(temp != NULL)
    {
        cout << temp->value;
        temp = temp->next;
    }
}
void reverseList(Node **head_reference)
{
    Node *temp = NULL;
    Node *curr = *head_reference;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;            
        curr = curr->prev;
    }
    if(temp != NULL ){
    	 *head_reference = temp->prev;
	}
}
void tokenize(std::string const &str, std::vector<std::string> &outvec)
{
	stringstream sstream(str);
	string tmp;
	while(getline(sstream, tmp, '#'))
    {
        outvec.push_back(tmp);
    }
}
void ReadFile(Node** list1,Node** list2){
	string line;
	ifstream file("./bin/Sayilar.txt");
	if(file.is_open()){
		getline(file,line);
		file.close();
		stringstream ss(line);
		vector<string> vec;
		tokenize(line,vec);
		string n1 = vec[0];
		string n2 = vec[1];
		int len=3;
	    int numCount = n1.length() / len;
	    int number;
	    for (int i = 0; i < numCount; i++)
	    {
	         number=atoi(n1.substr(i * len, len).c_str());
	         if(number<100){
	         	number+=100;
			 }
	         addNode(list1,number);
	         number=atoi(n2.substr(i * len, len).c_str());
	         if(number<100){
	         	number+=100;
			 }
	         addNode(list2,number);
	    }
	    reverseList(list1);
	    reverseList(list2);
	}
	else{
		cout<<"Cannot open file.";
	}
	
}
int checknextlevel(Node* list1,Node *list2,int level)
{
	int cur=0;
	while(cur<level){
		list1=list1->next;
		list2=list2->next;
		cur++;
	}
	if(list1->value>list2->value){
		 return 0;
	}
	else if(list1->value==list2->value){
		return 1;
	}
   else{
	 	return 2;
   }
}
int listSize(Node* headNode){
	int counter=0;
	while(headNode!=NULL){
		headNode=headNode->next;
		counter++;
	}
	return counter;
}
