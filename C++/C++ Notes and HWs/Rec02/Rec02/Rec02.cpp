/*
	Chaitanya Bolla cb3172
	Rec 02
	Use a vector of vectors to push back elements and print them out using a for loop
	and foreach loop
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void openFile(ifstream& ifs){
	//Open the file and print out an error statement if the file isn't found or exist
	ifs.open("chemicals.txt");
	if (!ifs){
		cerr << "File doesn't exist!";
		exit(1);
	}
}

void readFile(ifstream& ifs, vector<vector<string>>& moleculeContainer){
	//read the opened file and push them back into the vector of vectors
	string HCName;
	string HCFormula;
	while (ifs >> HCName >> HCFormula){
		string newHCName = HCName;
		vector<string> HCName;
		HCName.push_back(newHCName);
		HCName.push_back(HCFormula);
		moleculeContainer.push_back(HCName);
	}
}

void printFile(const vector<vector<string>>& moleculeContainer){
	//print out the info from the vector of vectors using a for loop and for each loop
	for (size_t i = 0; i < moleculeContainer.size(); i++){
		for (size_t j = 0; j < moleculeContainer[i].size(); j++){
			cout << moleculeContainer[i][j] << " ";
		}
		cout << endl;
	}
	cout << "========" << endl;
	for (vector<string> molecules : moleculeContainer){
		cout << molecules[0] << " " << molecules[1] << endl;
	}
}

int main(){
	ifstream ifs;
	vector<vector<string>> moleculeContainer;
	openFile(ifs);
	readFile(ifs, moleculeContainer);
	printFile(moleculeContainer);
	ifs.close();
	system("pause");
}