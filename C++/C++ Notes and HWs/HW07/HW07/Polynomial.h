#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <sstream>

class Polynomial{
public:
	//Constructors
	Polynomial(std::vector<int> nodeVec);
	Polynomial();

	//Output operator
	friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly);

	//Structure node
	struct Node{
		Node(int data = 0, Node* next = nullptr) : data(data), next(next) {};
		int data;
		Node* next;
	};
	Polynomial& operator+=(const Polynomial& add);

	//Linked Lists
	int listSize(Node* headPtr) const;
	void listDisplay(Node* headPtr) const;
	Node* listFindLast(Node* headPtr);
	void listAddEnd(Node*& headPtr, int data);
	void listAddHead(Node*& headPtr, int data);
	void listRemoveHead(Node*& headPtr);
	void listAdd(Node* priorPtr, int data);
	void listRemove(Node* prevPtr);
	void listClear(Node*& headPtr);
	Node* listDuplicate(Node* headPtr);
	void listDisplayReverse(Node* headPtr) const;

	//Copy control
	Polynomial(const Polynomial& copy);
	Polynomial& operator=(const Polynomial& poly);
	~Polynomial();

	//Equality operator
	void doNothing(Polynomial temp);
	bool operator==(Polynomial equal);
	bool operator!=(Polynomial equal);

	int evaluate(int random);

private:
	int expo; //for exponent
	Node* co; //for coefficicent
};
//Arithmetic operator
Polynomial operator+(const Polynomial& left, const Polynomial& right);
#endif