/*
	cb3172 - Chaitanya Bolla
	HW00
	Decrypt an encrypted text and print it out onto the screen.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int cypherNumber(ifstream& ifs){
	//get number of steps form the first line of the file and return it
	int cypher;
	ifs >> cypher;
	return cypher;
}

void shift(char& y, const int& cypher){
	//changes encrypted string into unencrypted form
	if (y - cypher >= 'a'){
		y = y - cypher;
	}
	else{
		y = 'z' - (cypher - (y - 'a') - 1);
	}
}

//char str[] = "hello";
//int cypher = 5; //num of characters to move
//for (int i = 0; str[i] != '\0'; i++){
//	if (y - cypher >= 'a'){
//		y = y - cypher;
//	}
//	else{
//		y = 'z' - (cypher - (y - 'a') - 1);
//	}
//}

vector<string> decrypt(ifstream& ifs, int cypher){
	//takes encrypted characters, pushes back the decrypted character into a vector and returns it
	string input;
	vector<string> lines;
	while (getline(ifs, input)){
		lines.push_back(input);
	}
	for (size_t i = 0; i < lines.size(); i++){
		for (size_t j = 0; j < lines[i].size(); j++){
			if (islower(lines[i][j])){
				char y = lines[i][j];
				shift(y, cypher);
				lines[i][j] = y;
			}
		}
	}
	return lines;
}

void printBackwards(const vector<string>& lines){
	//reverse the lines in the file and ouputs the encrypted file
	for (size_t i = lines.size(); i > 0; i--){
		cout << lines[i - 1] << endl;
	}

}

int main(){
	ifstream ifs("encrypted.txt");
	if (!ifs){
		cerr << "File doesn't exist!" << endl;
		exit(1);
	}

	int cypher = cypherNumber(ifs);
	vector<string> lines = decrypt(ifs, cypher);
	printBackwards(lines);
	ifs.close();
	system("pause");
}