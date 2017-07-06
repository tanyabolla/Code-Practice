#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Hydrocarbon{
	//Creats a struct with the attributes of number of carbon atoms, hydrogen atoms, and names of hydrocarbons
	int cAtoms;
	int hAtoms;
	vector<string> names;
};

void openFile(ifstream& ifs){
	//opens the hydrocarbon.txt file
	ifs.open("hydrocarbon-set-in-example.txt");
	if (!ifs){
		cerr << "File doesn't exist!" << endl;
		exit(1);
	}
}

size_t findCode(const vector<Hydrocarbon>& hydrocarbons, Hydrocarbon HS, string HC){
	//determines whether there exists a hydrocarbon with the same number of carbons and hydrogens and returns the index of that hydrocarbon
	//else it returns the size of the hydrocarbon vector
	for (size_t i = 0; i < hydrocarbons.size(); i++){
		if (HS.cAtoms == hydrocarbons[i].cAtoms && HS.hAtoms == hydrocarbons[i].hAtoms){
			return i;
		}
	}
	return hydrocarbons.size();
}

void readFile(ifstream& ifs, vector<Hydrocarbon>& hydrocarbons){
	//reads the file and pushes back hyrdocarbons into the hydrocarbon vector
	string HCName;
	char carbon;
	char hydrogen;
	int carbAtoms;
	int hydroAtoms;
	while (ifs >> HCName >> carbon >> carbAtoms >> hydrogen >> hydroAtoms){
		Hydrocarbon HS;
		HS.cAtoms = carbAtoms;
		HS.hAtoms = hydroAtoms;
		HS.names.push_back(HCName);
		size_t index = findCode(hydrocarbons, HS, HCName);
		if (index < hydrocarbons.size()){
			hydrocarbons[index].names.push_back(HCName);
		}
		else{
			hydrocarbons.push_back(HS);
		}
	}
}

void printFile(const vector<Hydrocarbon>& hydrocarbons){
	//prints the hydrocarbons in the vector in numberical order of carbon atoms and then prints out the names of each carbon atoms
	int cSize = 0;
	for (size_t i = 0; i < hydrocarbons.size(); i++){
		if (hydrocarbons[i].cAtoms > cSize){
			cSize = hydrocarbons[i].cAtoms;
		}
	}
	for (size_t j = 0; j < cSize; j++){
		for (size_t k = 0; k < hydrocarbons.size(); k++){
			if (hydrocarbons[k].cAtoms == j){
				cout << " C" << hydrocarbons[k].cAtoms << "H" << hydrocarbons[k].hAtoms << " ";
				for (size_t l = 0; l < hydrocarbons[k].names.size(); l++){
					cout << hydrocarbons[k].names[l] << " ";
				}
				cout << endl;
			}
		}
	}
}

int main(){
	ifstream ifs;
	vector<Hydrocarbon> hydrocarbons;
	openFile(ifs);
	readFile(ifs, hydrocarbons);
	printFile(hydrocarbons);
	ifs.close();
	system("pause");
}