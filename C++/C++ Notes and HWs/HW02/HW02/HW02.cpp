/* 
	cb3172
	Chaitanya Bolla
	HW02
	Create classes for warriors and make them battle.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Weapon{
	//Weapon class: stores names and strengths of weapons of a warrior
public:
	Weapon(const string& name, int strength) : wName(name), strength(strength){}
	string getwName() const { return wName; }
	int getStrength() const { return strength; }
	void setStrength(int newStrength) { strength = newStrength; }
private:
	string wName;
	int strength;
};

class Warrior{
	//Warrior class: stores names, strength of warriors and their weapons and it's strength uses setters and getters
public:
	Warrior(const string& theName, const string& wponName, int theStrength) : name(theName), weapon(wponName, theStrength){}
	string getName() const { return name; }
	string getWeaponN() const { return weapon.getwName(); }
	int getWeaponS() const { return weapon.getStrength(); }
	void setWeaponS(int newStrength){ weapon.setStrength(newStrength); }

	void battle(vector<Warrior>& warriors, const string& warriorOne, const string& warriorTwo){
		//gets warriors and makes them battle against each other
		int warOne;
		int warTwo;

		for (size_t i = 0; i < warriors.size(); i++){
			if (warriors[i].name == warriorOne){
				warOne = i;
			}
			else if (warriors[i].name == warriorTwo){
				warTwo = i;
			}
		}
		cout << warriors[warOne].name << " battles " << warriors[warTwo].name << endl;

		if (warriors[warOne].getWeaponS() > warriors[warTwo].getWeaponS()){
			cout << warriors[warOne].name << " defeats " << warriors[warTwo].name << endl;
			warriors[warOne].setWeaponS(warriors[warOne].getWeaponS() - warriors[warTwo].getWeaponS());
			warriors[warTwo].setWeaponS(0);
		}
		else if (warriors[warOne].getWeaponS() < warriors[warTwo].getWeaponS()){
			cout << warriors[warTwo].name << " defeats " << warriors[warOne].name << endl;
			warriors[warOne].setWeaponS(warriors[warTwo].getWeaponS() - warriors[warOne].getWeaponS());
			warriors[warOne].setWeaponS(0);
		}
		else if (warriors[warOne].getWeaponS() == 0 && warriors[warTwo].getWeaponS() == 0){
			cout << "Oh NO! They are both dead! YUCK!!!" << endl;
		}
		else if (warriors[warOne].getWeaponS() == warriors[warTwo].getWeaponS()){
			warriors[warOne].setWeaponS(0);
			warriors[warTwo].setWeaponS(0);
			cout << "Mutual Annihilation: " << warriors[warOne].name << " and " << warriors[warTwo].name << " die at each other's hands!" << endl;
		}
	}
private:
	string name;
	Weapon weapon;
};

void warrior(ifstream& ifs, vector<Warrior>& warriors){
	//gets the names and strengths of the warriors
	string name;
	string weapon;
	int power;
	ifs >> name >> weapon >> power;
	Warrior warrior(name, weapon, power);
	warriors.push_back(warrior);
}

void display(const vector<Warrior>& warriors){
	//counts the instances of battles and deaths and displays them on the screen
	int count = 0;
	for (size_t i = 0; i < warriors.size(); i++){
		count++;
	}
	cout << "There are " << count << " warriors!" << endl;
	for (size_t i = 0; i < warriors.size(); i++){
		cout << "Warrior: " << warriors[i].getName() << ", Weapon: " << warriors[i].getWeaponN() << ", Strength: " << warriors[i].getWeaponS() << endl;
	}
}

void readFile(ifstream& ifs, vector<Warrior> warriors){
	//creates a warrior with his name and his strength from the opened file, then makes the warriors battle against each other.
	string warriorOrBattle;
	while (ifs >> warriorOrBattle){
		if (warriorOrBattle == "Warrior"){
			warrior(ifs, warriors);
		}
		else if (warriorOrBattle == "Battle"){
			string warriorOne;
			string warriorTwo;
			ifs >> warriorOne >> warriorTwo;
			for (size_t i = 0; i < warriors.size(); i++){
				if (warriors[i].getName() == warriorOne){
					warriors[i].battle(warriors, warriorOne, warriorTwo);
				}
			}
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