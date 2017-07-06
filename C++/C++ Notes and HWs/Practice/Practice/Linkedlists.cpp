#include <iostream>
#include <string>

using namespace std;
struct Node{
	Node* headPtr;
	int data;
};

void listAddHead(Node*& headPtr, int data){
	/*Create the new node for the data
	Node* p = new Node(data);
	Connect that node to the old head node
	p->next = headPtr;
	Make the new node become the head node
	headPtr = p;
*/
	headPtr = new Node(data, headPtr);
}
//int main(){
//	Node* list = nullPtr; //an empty list
//	list = new Node(17); // now the list contains a single node
//	list->next = new Node(42); //and now it has two!
//	cout << list->data << " " << list->next->data << endl;
//	listDisplay(list);
//	cout << listSize(list) << endl;
//
//	listAddEnd(list, 28);
//}