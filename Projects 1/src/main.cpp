#include <iostream>
#include "linkedList.cpp"
/**
* @linkedList.cpp
* @main
* @Zorunlu 1/B
* @1
* @10.08.2021
* @Harun Aydemir linkedList.cpp
*/
using namespace::std;

int main(int argc, char** argv) {
	Node* head1= NULL;
	Node* head2= NULL;
	ReadFile(&head1,&head2);
	int maxSize = listSize(head1);
	for(int i=0;i<maxSize;i++){
		switch(checknextlevel(head1,head2,i)){
			case 0:
				reverseList(&head1);
				break;
			case 1:
				reverseList(&head2);
				break;
			case 2:
				Node* list1 = head1;
				Node* list2 = head2;
				for(int j=0;j<i;j++){
					list1=list1->next;
					list2=list2->next;
				}
				int tmpVal = list1->value;
			 	list1->value=list2->value;
			 	list2->value=tmpVal;
				break;
		}
	}
	cout<<"Sayi 1:";
    printList(head1);
    cout<<endl<<"Sayi 2:";
    printList(head2);
	return 0;
}
