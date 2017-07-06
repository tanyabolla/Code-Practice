#include <iostream>
#include <string>
#include <cstdlib>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
	Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
	int data;
	Node* link;
};

void listInsertHead(int data, Node*& headPtr){
	headPtr = new Node(data, headPtr);
}

struct TNode {
	TNode(int data = 0, TNode *left = NULL, TNode *right = NULL)
		: data(data), left(left), right(right) {}
	int data;
	TNode *left, *right;
};

void displayBinary(int n){
	if (n < 2) {
		cout << n;
	}
	else {
		displayBinary(n / 2);
		cout << n % 2;
	}
}

Node* add(Node*& listOne, Node*& listTwo){
	if (listOne->link == NULL){ //since both lists are the same size, need to only check for one
		return new Node(listOne->data + listTwo->data);
	}
	else{
		return new Node(listOne->data + listTwo->data, add(listOne->link, listTwo->link));
	}
}

int max(TNode* root) {
	int maximum;
	int maxLeft;
	int maxRight;
	if (!root){
		return INT_MIN;
	}
	else{
		maxLeft = max(root->left);
		maxRight = max(root->right);
	}
	if (root->data > maxLeft){
		maximum = root->data;
	}
	else{
		maximum = maxLeft;
	}
	if (root->data > maxRight){
		if (maximum < root->data){
			maximum = root->data;
		}
	}
	else if (root->data > maxRight){
		maximum = maxRight;
	}
	return maximum;
}

int sum(char* aString){
	if (aString[0] == '\0'){
		return 0;
	}
	else{
		return int(aString[0]) + sum(aString + 1);
	}
}

int binarySearch(char searchfor, char a[], int left, int right) {
	int mid = (left + right) / 2;
	if (left > right) {
		cout << "Character not in array. Error" << endl;
		return -1;
	}
	else if (searchfor == a[mid]) {
		return mid;
	}
	else if (searchfor > a[mid]) {
		return binarySearch(searchfor, a, mid + 1, right);
	}
	else {
		return binarySearch(searchfor, a, left, mid - 1);
	}
}

void fi(int n) {
	if (n > 1) {
		cout << 'a';
		fi(n / 2);
		cout << 'b';
		fi(n / 2);
	}
	cout << 'c';
}

int main(){
	cout << "1.========\n";
	displayBinary(7);
	cout << endl;

	cout << "\n2.========\n";
	Node* listOne = NULL;
	Node* listTwo = NULL;
	listInsertHead(1, listOne);
	listInsertHead(9, listOne);
	listInsertHead(7, listOne);
	listInsertHead(5, listOne);
	listInsertHead(3, listTwo);
	listInsertHead(2, listTwo);
	listInsertHead(6, listTwo);
	listInsertHead(5, listTwo);
	Node* listThree = add(listOne, listTwo);
	Node* coutList = listThree;
	while (coutList){
		cout << coutList->data << ' ';
		coutList = coutList->link;
	}
	cout << endl;

	cout << "\n3.========\n";
	TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
	cout << max(&f) << endl;

	cout << "\n4.========\n";
	char aString[12] = "I am Tanya";
	cout << sum(aString) << endl;

	cout << "\n5.========\n";
	char str[20] = "Bessie is a cow";
	sort(str, str + sizeof(str));
	cout << binarySearch('c', str, 0, sizeof(str)) << endl;

	cout << "\n6.========\n";
	fi(4);
	cout << endl;

	system("pause");
}