#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

struct Node{
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

class Sequence{
public:
	Sequence(): headptr(NULL), position(NULL) {}
	void reset(){
		position = headptr;
	}
	void add(int data){
		Node* temp = position;
		if (headptr == NULL && temp == NULL){
			//assign both to new if null
			headptr = new Node(data, headptr);
			position = headptr;
		}
		else{
			//if not null, go next on both and set to node that is created
			temp->link = new Node(data, temp->link);
			position = temp->link;
		}
	}
	int data() const {
		if (position != NULL){
			return position->data;
		}
	}
	void remove(){
		Node* temp1 = headptr;
		Node* temp2 = NULL;
		while (temp1->data != position->data){
			temp2 = temp1;
			temp1 = temp1->link;
		}
		temp2->link = position->link;
		delete temp1;
	}
	bool valid(){ 
		if (position != NULL){
			return true;
		}
		return false;
	}
	void next(){
		if (valid()){
			position = position->link;
		}
	}
	void display() const {
		Node* temp = headptr;
		while (temp != NULL){
			cout << temp->data << " ";
			temp = temp->link;
		}
		cout << endl;
	}
	void clear(){
		Node* temp = headptr;
		headptr = NULL;
		while (temp != NULL){
			Node* link = temp->link;
			delete temp;
			temp = link;
		}
	}
private:
	Node* headptr;
	Node* position;
};

int main() {
	Sequence s;
	for (int i = 0; i < 6; ++i) s.add(i);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 5; ++i) s.next();
	s.add(42);
	s.display();
	cout << "==========\n";
	s.reset();
	for (int i = 0; i < 2; ++i) s.next();
	s.remove();
	s.display();
	cout << "==========\n";
	s.clear();
	s.display();
	cout << "==========\n";
	system("pause");
}