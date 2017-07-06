#include "Polynomial.h"
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

Polynomial::Polynomial(vector<int> nodeVec) {
	for (size_t i = nodeVec.size() - 1; i > 0; i--){
		Polynomial::listAddEnd(co, nodeVec[i]);
	}
	Polynomial::listAddEnd(co, nodeVec[0]);
	expo = listSize(co);
}

Polynomial::Polynomial(){
	expo = 0;
	co = nullptr;
}

void Polynomial::listDisplay(Node* headPtr) const {
	Node* p = headPtr;
	while (p != nullptr) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << endl;
}

int Polynomial::listSize(Node* headPtr) const {
	Node* p = headPtr;
	int count = 0;
	while (p != nullptr) {
		++count;
		p = p->next;
	}
	return count;
}

Polynomial::Node* Polynomial::listFindLast(Node* headPtr) {
	if (headPtr == nullptr) return nullptr;
	Node* p = headPtr;
	while (p->next != nullptr) {
		p = p->next;
	}
	return p;
}

void Polynomial::listAddEnd(Node*& headPtr, int data) {
	if (headPtr == nullptr) {
		headPtr = new Node(data);
	}
	else {
		Node* last = listFindLast(headPtr);
		last->next = new Node(data);
	}
}

void Polynomial::listAddHead(Node*& headPtr, int data) {
	headPtr = new Node(data, headPtr);
}

void Polynomial::listRemoveHead(Node*& headPtr) {
	if (headPtr != nullptr) {
		Node* oldptr = headPtr;
		headPtr = headPtr->next;
		delete oldptr;
	}
}

void Polynomial::listAdd(Node* prevPtr, int data) {
	prevPtr->next = new Node(data, prevPtr->next);
}

void Polynomial::listRemove(Node* prevPtr) {
	if (prevPtr->next == nullptr) return;
	Node* p = prevPtr->next->next;
	delete prevPtr->next;
	prevPtr->next = p;
}

void Polynomial::listClear(Node*& headPtr) {
	if (headPtr == nullptr) return;
	Node* curr = headPtr;
	Node* nextNode = headPtr->next;
	while (nextNode != nullptr) {
		delete curr;
		curr = nextNode;
		nextNode = nextNode->next;
	}
	delete curr;
	headPtr = nullptr;
}

Polynomial::Node* Polynomial::listDuplicate(Node* headPtr) {
	if (headPtr == nullptr) return nullptr;
	Node* curr = headPtr->next;
	Node* last = new Node(headPtr->data);
	Node* result = last;
	while (curr != nullptr) {
		last->next = new Node(curr->data);
		curr = curr->next;
		last = last->next;
	}
	return result;
}

void Polynomial::listDisplayReverse(Node* headPtr) const {
	int len = this->expo;
	if (headPtr == nullptr) return;
	listDisplayReverse(headPtr->next);
	cout << headPtr->data << "x^" << len << '+';
	len--;
}

Polynomial& Polynomial::operator=(const Polynomial& poly){
	if (this != &poly){
		Node* temp;
		while (co != nullptr){
			temp = co->next;
			delete co;
			co = temp;
		}
		expo = poly.expo;
		co = new Node(poly.co->data, poly.co->next);
		Node* temp1 = poly.co->next;
		Node* temp2 = co;
		while (temp1 != nullptr){
			temp2->next = new Node(temp1->data, temp1->next);
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
	}
	return *this;
}

Polynomial::Polynomial(const Polynomial& copy){
	expo = copy.expo;
	co = new Node(copy.co->data, copy.co->next);
	Node* temp1 = copy.co->next;
	Node* temp2 = co;
	while (temp1 != nullptr){
		temp2->next = new Node(temp1->data, temp1->next);
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
}

Polynomial::~Polynomial(){
	Node* temp;
	while (co != nullptr){
		temp = co->next;
		delete co;
		co = temp;
	}
	co = nullptr;
}

ostream& operator<<(ostream& os, const Polynomial& poly){
	stringstream stream;
	int length = 1;
	vector<string> coeff;
	string coefficient;
	if (poly.co == nullptr){
		os << "Polynomial is empty!!!";
		return os;
	}
	stream << poly.co->data;
	Polynomial::Node* temp = poly.co->next;
	while (temp != nullptr && length != poly.expo){
		stream << "+" << temp->data << "x^" << noshowpos << length;
		temp = temp->next;
		length++;
	}
	for (size_t i = 0; i < poly.expo; ++i){
		while (getline(stream, coefficient, '+')){
			coeff.push_back(coefficient);
		}
	}
	for (size_t i = coeff.size() - 1; i > 0; --i){
		os << coeff[i] << "+";
	}
	os << coeff[0];
	os << endl;
	return os;
}

Polynomial operator+(const Polynomial& left, const Polynomial& right){
	Polynomial result(left);
	return result += right;
}

Polynomial& Polynomial::operator+=(const Polynomial& add){
	if (expo >= add.expo){
		Node* tmp1 = co;
		Node* tmp2 = add.co;
		while (tmp2 != nullptr){
			tmp1->data += tmp2->data;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		return *this;
	}
	else{
		Polynomial temp(*this);
		*this = add;
		Node* tmp1 = co;
		Node* tmp2 = temp.co;
		while (tmp2 != nullptr){
			tmp1->data += tmp2->data;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		return *this;
	}
}

bool Polynomial::operator==(Polynomial equal){
	bool ret = true;
	if (expo != equal.expo){
		ret = false;
		return ret;
	}
	else{
		Node* tmp = co;
		Node* tmp2 = equal.co;
		while (tmp != nullptr){
			if (tmp->data != tmp2->data){
				ret = false;
				return ret;
			}
			else{
				tmp = tmp->next;
				tmp2 = tmp2->next;
				ret = true;
			}
		}
		return ret;
	}
	return ret;
}

bool Polynomial::operator!=(Polynomial equal){
	return !(this->operator==(equal));
}

int Polynomial::evaluate(int random){
	int result = co->data;
	Node* tmp = co->next;
	while (tmp != nullptr){
		result = result + (tmp->data * random);
		tmp = tmp->next;
	}
	return result;
}
