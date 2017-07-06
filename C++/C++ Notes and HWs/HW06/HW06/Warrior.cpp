#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace WarriorCraft{
	//Warrior constructor
	Warrior::Warrior(const string& name, int power) : wName(name), strength(power), isEmployed(false), noble(nullptr) {}
	//Gets name of warrior
	string Warrior::getName() const { return wName; }
	//Gets and sets strength of warrior
	int Warrior::getStrength() const { return strength; }
	void Warrior::setStrength(int theStrength){ strength = theStrength; }
	//Gets and sets the employment of warrior
	bool Warrior::getEmployment() const { return isEmployed; }
	void Warrior::setEmployment(bool hasJob){ isEmployed = hasJob; }
	//Gets and sets the noble who hired the warrior
	Noble* Warrior::getNoble() const{ return noble; }
	void Warrior::setNoble(Noble* nob) { noble = nob; }
	void Warrior::runaway(){
		//Uses the fire method in noble class to remove the warrior from the vector of warriors
		if (noble != nullptr){
			noble->fire(*this);
			noble = nullptr;
		}
	}
}