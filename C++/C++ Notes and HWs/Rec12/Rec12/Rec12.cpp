#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int entry, Node*& headPtr) {
	headPtr = new Node(entry, headPtr);
}

void spliceInto(Node* headPtr, Node* spliceList){
	if (spliceList != NULL){
		if (headPtr->link == NULL){
			headPtr->link = spliceList;
		}
		else{
			Node* lastPtr = headPtr->link;
			headPtr->link = spliceList;
			Node* attach = spliceList;
			while (attach->link != NULL){
				attach = attach->link;
			}
			attach->link = lastPtr;
		}
	}
}

Node* findNode(int data, Node* headPtr){
	Node* temp = headPtr;
	while (temp){
		if (temp->data == data){
			return temp;
		}
		temp = temp->link;
	}
	return NULL;
}

void display(Node*& headPtr){
	Node* coutList = headPtr;
	while (coutList){
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;
}

Node* search(Node* head1, Node* head2){
	Node* temp = head1;
	Node* ptr = temp;
	while (temp){
		ptr = temp;
		temp = findNode(head2->data, temp);
		while (temp && head2 && temp->data == head2->data){
			temp = temp->link;
			head2 = head2->link;
		}
		if (head2 == NULL){
			return ptr->link;
		}
		if (temp == NULL){
			cout << "Failed to match";
			return NULL;
		}
	}
	return NULL;
}

int main(){
	cout << "Part One: " << endl;
	Node* listOne = NULL;
	Node* listTwo = NULL;
	listInsertHead(1, listOne);
	listInsertHead(9, listOne);
	listInsertHead(7, listOne);
	listInsertHead(5, listOne);

	listInsertHead(2, listTwo);
	listInsertHead(3, listTwo);
	listInsertHead(6, listTwo);

	cout << endl;
	cout << "L1: ";
	display(listOne);
	cout << "L2: ";
	display(listTwo);

	Node* temp = findNode(7, listOne);
	cout << "Target: ";
	display(temp);
	spliceInto(temp, listTwo);

	cout << "Spliced!" << endl;
	cout << "L1: "; 
	display(listOne);
	cout << "L2: ";
	display(listTwo);
	cout << "============\n";

	cout << "Part Two: " << endl;
	Node* listThree = NULL;
	Node* listFour = NULL;
	Node* listFive = NULL;
	Node* listSix = NULL;
	Node* listSeven = NULL;
	Node* listEight = NULL;
	Node* listNine = NULL;

	listInsertHead(6, listThree);
	listInsertHead(5, listThree);
	listInsertHead(4, listThree);
	listInsertHead(2, listThree);
	listInsertHead(3, listThree);
	listInsertHead(2, listThree);
	listInsertHead(3, listThree);
	listInsertHead(2, listThree);
	listInsertHead(1, listThree);

	listInsertHead(1, listFour);

	listInsertHead(9, listFive);
	listInsertHead(3, listFive);

	listInsertHead(3, listSix);
	listInsertHead(2, listSix);

	listInsertHead(6, listSeven);
	listInsertHead(5, listSeven);
	listInsertHead(4, listSeven);
	listInsertHead(2, listSeven);

	listInsertHead(4, listEight);
	listInsertHead(2, listEight);
	listInsertHead(3, listEight);
	listInsertHead(2, listEight);

	listInsertHead(7, listNine);
	listInsertHead(6, listNine);
	listInsertHead(5, listNine);

	cout << "\nTarget List: ";
	display(listThree);

	cout << "\nAttempt Match: ";
	display(listFour);
	Node* list4 = search(listThree, listFour);
	display(listThree);

	cout << "\nAttempt Match: ";
	display(listFive);
	Node* list5 = search(listThree, listFive);
	display(list5);

	cout << "\nAttempt Match: ";
	display(listSix);
	Node* list6 = search(listThree, listSix);
	display(list6);

	Node* list8 = NULL;
	list8 = search(listThree, listEight);

	cout << "\nAttempt Match: ";
	display(listSeven);
	Node* list7 = search(listThree, listSeven);
	display(list8);

	cout << "\nAttempt Match: ";
	display(listEight);
	display(list7);

	cout << "\nAttempt Match: ";
	display(listNine);
	Node* list9 = search(listThree, listNine);
	display(list9);

	system("pause");
}