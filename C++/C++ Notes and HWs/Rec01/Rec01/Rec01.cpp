#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream ifs("jabberwocky.txt");
	if (!ifs){
		cerr << "File doesn't exist! Try again!";
		exit(1);
	}
	int counter = 0;
	string word;
	while (ifs >> word){
		cout << word << endl;
		counter++;
	}
	ifs.close();
	ifs.open("jabberwocky.txt");
	int counter2 = 0;
	string line;
	while(getline(ifs, line)){
		cout << line << endl;
		counter2++;
	}
	cout << "There are " << counter << " words!" << endl;
	cout << "There are " << counter2 << " lines!" << endl;
	ifs.close();
	ifs.open("jabberwocky.txt");
	int counter3 = 0;
	char c;
	while (ifs >> c){
		counter3++;
	}
	ifs.close();
	ifs.open("jabberwocky.txt");
	int counter4 = 0;
	char c2;
	ifs >> noskipws;
	while (ifs >> c2){
		counter4++;
	}
	ifs >> skipws;
	ifs.close();
	ifs.open("jabberwocky.txt");
	int counter5 = 0;
	char c3;
	while (ifs >> c3){
		counter5++;
	}
	cout << "There are " << counter3 << " characters!" << endl;
	cout << "There are " << counter4 << " characters with whitespace!" << endl;
	cout << "There are " << counter5 << " characters with  no whitespace!" << endl;

	system("pause");
}