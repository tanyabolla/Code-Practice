/*
cb3172
Chaitanya Bolla
HW04 - create warriors and nobles on the heap and make them battle
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Warrior{
	//Warrior class - creates an object for a warrior
public:
	Warrior(const string& name, int power) : wName(name), strength(power), isEmployed(false) {}
	string getName() const { return wName; }
	int getStrength() const { return strength; }
	void setStrength(int theStrength){ strength = theStrength; }
	bool getEmployment() const { return isEmployed; }
	void setEmployment(bool hasJob){ isEmployed = hasJob; }
private:
	string wName;
	int strength;
	bool isEmployed;
};

class Noble{
	//Noble class - methods to hire, fire, and battle warriors in a war with other nobles
public:
	Noble(const string& name) : nName(name) {}
	string getName() const { return nName; }
	void setStrength(int newStrength){
		for (size_t i = 0; i < warriors.size(); i++){
			warriors[i]->setStrength(newStrength);
		}
	}
	void hire(Warrior*& someWarrior){
		//hires a warriors for the noble
		warriors.push_back(someWarrior);
		someWarrior->setEmployment(true);
	}
	void fire(Warrior*& someWarrior){
		//fires a warrior from the nobles' employment
		for (size_t i = 0; i < warriors.size(); i++){
			if (someWarrior->getName() == warriors[i]->getName()){
				cout << warriors[i]->getName() << ", you're fired! -- " << nName << endl;
				warriors[i] = warriors[warriors.size() - 1];
				warriors.pop_back();
				someWarrior->setEmployment(false);
			}
		}
	}
	void battle(Noble*& opponent){
		//battles another noble using the warriors that were hired
		int power = 0;
		for (size_t i = 0; i < warriors.size(); i++){
			power += warriors[i]->getStrength();
		}
		int opponentPow = 0;
		for (size_t i = 0; i < opponent->warriors.size(); i++){
			opponentPow += opponent->warriors[i]->getStrength();
		}
		cout << nName << " battles " << opponent->nName << endl;

		if (power > opponentPow){
			cout << nName << " defeats " << opponent->nName << endl;
			setStrength(power -= opponentPow);
			opponent->setStrength(0);
		}
		else if (power < opponentPow){
			cout << opponent->nName << " defeats " << nName << endl;
			opponent->setStrength(opponentPow -= power);
			setStrength(0);
		}
		else if (power == 0 && opponentPow == 0){
			cout << "Oh NO! They are both dead! YUCK!!!" << endl;
		}
		else if (power == opponentPow){
			setStrength(0);
			opponent->setStrength(0);
			cout << "Mutual Annihilation: " << nName << " and " << opponent->nName << " die at each other's hands!" << endl;
		}
	}
	void display() const {
		//displays the name, warriors, and the strength of nobles' warriors
		int count = warriors.size();
		cout << nName << " has an army of " << count << endl;
		for (size_t i = 0; i < warriors.size(); i++){
			cout << "\t" << warriors[i]->getName() << ": " << warriors[i]->getStrength() << endl;
		}
	}
private:
	string nName;
	vector<Warrior*> warriors;
};

void createNoble(vector<Noble*>& nobles, const string& nobleName){
	//creates a noble on the heap and checks to see if the noble doesn't exist already on the heap
	if (nobles.size() == 0){
		Noble* noblePtr = new Noble(nobleName);
		nobles.push_back(noblePtr);
	}
	else{
		for (size_t i = 0; i < nobles.size(); i++){
			if ((nobles[i]->getName()) == nobleName){ //checks for existence of the noble in the collection
				cerr << "Error. Noble exists already" << endl;
				exit(1);
			}
			else{
				Noble* noblePtr = new Noble(nobleName);
				nobles.push_back(noblePtr);
				i = nobles.size();
			}
		}
	}
}

void createWarrior(vector<Warrior*>& warriors, const string& warName, int strength){
	//creates a warrior on the heap and check to see if the warrior doesn't exist already on the heap
	if (warriors.size() == 0){
		Warrior* warPtr = new Warrior(warName, strength);
		warriors.push_back(warPtr);
	}
	else{
		for (size_t i = 0; i < warriors.size(); i++){
			if (warriors[i]->getName() == warName){ //checks for existence of the warrior of the noble in the collection
				cerr << "Error. Warrior exists already" << endl;
				exit(1);
			}
			else{
				Warrior* warPtr = new Warrior(warName, strength);
				warriors.push_back(warPtr);
				i = warriors.size();
			}
		}
	}
}

void hireWarrior(const vector<Noble*>& nobles, vector<Warrior*>& warriors, const string& nobleName, const string& warName){
	//by using nobles and warriors from the heap, the warriors are hired by a specific noble
	for (size_t i = 0; i < nobles.size(); i++){
		if (nobleName == nobles[i]->getName()){ //checks for existence of the noble
			for (size_t j = 0; j < warriors.size(); j++){
				if (warName == warriors[j]->getName()){ //checks for existence of the warrior
					nobles[i]->hire(warriors[j]);
				}
			}
		}
	}
}

void fireWarrior(const vector<Noble*>& nobles, vector<Warrior*>& warriors, const string& nobleName, const string& warName){
	//calls the fire function in the class Noble
	for (size_t i = 0; i < nobles.size(); i++){
		if (nobleName == nobles[i]->getName()){ //checks for existence of the noble
			for (size_t j = 0; j < warriors.size(); j++){
				if (warName == warriors[j]->getName()){ //checks for existence of the warrior
					nobles[i]->fire(warriors[j]);
				}
			}
		}
	}
}

void noblesBattle(vector<Noble*>& nobles, const string& nobleOne, const string& nobleTwo){
	//takes the two names from the input files and calls the battle function
	for (size_t i = 0; i < nobles.size(); i++){
		if (nobleOne == nobles[i]->getName()){ //checks for existence of the noble
			for (size_t j = 0; j < nobles.size(); j++){
				if (nobleTwo == nobles[j]->getName()){ //checks for existence of the noble
					nobles[i]->battle(nobles[j]);
				}
			}
		}
	}
}

void status(vector<Noble*>& nobles, vector<Warrior*>& warriors){
	//whenever status is called, the display function is called and also prints out the unemployed warriors
	cout << "Status\n" << "======\n" << "Nobles:" << endl;
	if (nobles.size() == 0){
		cout << "NONE" << endl;
	}
	else{
		for (size_t i = 0; i < nobles.size(); i++){
			nobles[i]->display();
		}
	}
	bool isUnemployed = true;
	cout << "Unemployed Warriors:" << endl;
	for (size_t i = 0; i < warriors.size(); i++){
		if (warriors[i]->getEmployment() == false){
			cout << warriors[i]->getName() << ": " << warriors[i]->getStrength() << endl;
			isUnemployed = false;
		}
		else{
			i;
		}
	}
	if (isUnemployed){
		cout << "NONE" << endl;
	}
}

void clearVector(vector<Noble*>& nobles, vector<Warrior*>& warriors){
	//clears the nobles and warriors from the heap and clears the vectors of nobles and warriors
	for (size_t i = 0; i < nobles.size(); i++){
		delete nobles[i];
		nobles[i] = nullptr;
	}
	for (size_t j = 0; j < warriors.size(); j++){
		delete warriors[j];
		warriors[j] = nullptr;
	}
	nobles.clear();
	warriors.clear();
}

void readFile(vector<Noble*>& nobles, vector<Warrior*>& warriors){
	//function that deals with the input from the file by using ifs and calling other functions 
	ifstream ifs("noblewarriors.txt");
	if (!ifs){
		cerr << "File doesn't exist" << endl;
		exit(1);
	}
	string identifier;
	while (ifs >> identifier){
		if (identifier == "Noble"){
			string nobleName;
			ifs >> nobleName;
			createNoble(nobles, nobleName);
		}
		else if (identifier == "Warrior"){
			string warName;
			int strength;
			ifs >> warName >> strength;
			createWarrior(warriors, warName, strength);
		}
		else if (identifier == "Hire"){
			string nobleName, warName;
			ifs >> nobleName >> warName;
			hireWarrior(nobles, warriors, nobleName, warName);
		}
		else if (identifier == "Fire"){
			string nobleName, warName;
			ifs >> nobleName >> warName;
			fireWarrior(nobles, warriors, nobleName, warName);
		}
		else if (identifier == "Battle"){
			string nobleOne, nobleTwo;
			ifs >> nobleOne >> nobleTwo;
			noblesBattle(nobles, nobleOne, nobleTwo);
		}
		else if (identifier == "Status"){
			status(nobles, warriors);
		}
		else if (identifier == "Clear"){
			clearVector(nobles, warriors);
		}
	}
	ifs.close();
}

int main(){
	vector<Noble*> nobles;
	vector<Warrior*> warriors;
	readFile(nobles, warriors);
	system("pause");
}