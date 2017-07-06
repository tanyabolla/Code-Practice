/*
cb3172
Chaitanya Bolla

The purpose of the program was create a warrior game where they fight to the death and print out the statistics at the end of the game.
//NO negative health
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Warrior{
	//creates the struct Warrior with a string and an int as attributes
	string warName;
	int strength;
};

void warrior(ifstream& ifs, vector<Warrior>& warriors){
	//gets the names and strengths of the warriors
	string name;
	int power;
	ifs >> name >> power;
	Warrior warrior;
	warrior.warName = name;
	warrior.strength = power;
	warriors.push_back(warrior);
}

void battle(ifstream& ifs, vector<Warrior>& warriors){
	//gets warriors and makes them battle against each other
	string warriorOne;
	string warriorTwo;
	int warOne;
	int warTwo;
	ifs >> warriorOne >> warriorTwo;

	for (int i = 0; i < warriors.size(); i++){
		if (warriors[i].warName == warriorOne){
			warOne = i;
		}
		else if (warriors[i].warName == warriorTwo){
			warTwo = i;
		}
	}
	cout << warriors[warOne].warName << " battles " << warriors[warTwo].warName << endl;

	if (warriors[warOne].strength > warriors[warTwo].strength){
		cout << warriors[warOne].warName << " defeats " << warriors[warTwo].warName << endl;
		warriors[warOne].strength -= warriors[warTwo].strength;
		warriors[warTwo].strength = 0;
	}
	else if (warriors[warOne].strength < warriors[warTwo].strength){
		cout << warriors[warOne].warName << " defeats " << warriors[warTwo].warName << endl;
		warriors[warTwo].strength -= warriors[warOne].strength;
		warriors[warOne].strength = 0;
	}
	else if (warriors[warOne].strength == 0 && warriors[warTwo].strength == 0){
		cout << "Oh NO! They are both dead! YUCK!!!" << endl;
	}
	else if (warriors[warOne].strength == warriors[warTwo].strength){
		warriors[warOne].strength = 0;
		warriors[warTwo].strength = 0;
		cout << "Mutual Annihilation: " << warriors[warOne].warName << " and " << warriors[warTwo].warName << " die at each other's hands!" << endl;
	}
}

void display(const vector<Warrior>& warriors){
	//counts the instances of battles and deaths and displays them on the screen
	int count = 0;
	for (size_t i = 0; i < warriors.size(); i++){
		count++;
	}
	cout << "There are " << count << " warriors!" << endl;
	for (int i = 0; i < warriors.size(); i++){
		cout << "Warrior: " << warriors[i].warName << " Strength: " << warriors[i].strength << endl;
	}
}

void readFile(ifstream& ifs, vector<Warrior>& warriors){
	//creates a warrior with his name and his strength from the opened file, then makes the warriors battle against each other.
	string warriorOrBattle;
	while (ifs >> warriorOrBattle){
		if (warriorOrBattle == "Warrior"){
			warrior(ifs, warriors);
		}
		else if (warriorOrBattle == "Battle"){
			battle(ifs, warriors);
		}
		else if (warriorOrBattle == "Status"){
			display(warriors);
		}
	}
}

int main(){
	ifstream ifs("warriors.txt");
	if (!ifs){
		cerr << "File doesn't work";
		exit(1);
	}
	vector<Warrior> warriors;
	readFile(ifs, warriors);
	ifs.close();
	system("pause");
}