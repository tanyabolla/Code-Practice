#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace WarriorCraft{
	//Noble Constructor
	Noble::Noble(const string& name) : nName(name) {}
	string Noble::getName() const { return nName; }
	void Noble::setStrength(int newStrength){
		for (size_t i = 0; i < warriors.size(); i++){
			warriors[i]->setStrength(newStrength);
		}
	}
	void Noble::hire(Warrior& someWarrior){
		//hires a warrior and adds to vector of warrior pointers
		if (someWarrior.getNoble() == nullptr){
			someWarrior.setNoble(this);
			warriors.push_back(&someWarrior);
			someWarrior.setEmployment(true);
		}
	}
	void Noble::fire(Warrior& someWarrior){
		for (size_t i = 0; i < warriors.size(); i++){
			if (someWarrior.getName() == warriors[i]->getName()){
				cout << warriors[i]->getName() << "flees in terror, abandoning his lord, " << nName << endl;
				warriors[i] = warriors[warriors.size() - 1];
				warriors.pop_back();
				someWarrior.setEmployment(false);
				someWarrior.setNoble(nullptr);
			}
		}
	}
	void Noble::battle(Noble& opponent){
		//finds collective sum of warrior's strengths
		int power = 0;
		for (size_t i = 0; i < warriors.size(); i++){
			power += warriors[i]->getStrength();
		}
		//finds collective sum of the opponent's strengths
		int opponentPow = 0;
		for (size_t i = 0; i < opponent.warriors.size(); i++){
			opponentPow += opponent.warriors[i]->getStrength();
		}
		cout << nName << " battles " << opponent.nName << endl;

		if (power == 0 && opponentPow == 0){
			cout << "Oh NO! They are both dead! YUCK!!!" << endl;
		}
		else if (power == opponentPow){
			setStrength(0);
			opponent.setStrength(0);
			cout << "Mutual Annihilation: " << nName << " and " << opponent.nName << " die at each other's hands!" << endl;
		}
		else if (power > opponentPow){
			//if this one is stronger than the opponent
			cout << nName << " defeats " << opponent.nName << endl;
			setStrength(power -= opponentPow);
			opponent.setStrength(0);
		}
		else if (power < opponentPow){
			//if opponent is stronger
			cout << opponent.nName << " defeats " << nName << endl;
			opponent.setStrength(opponentPow -= power);
			setStrength(0);
		}
	}
	void Noble::display(ostream& os) const {
		int count = warriors.size();
		cout << nName << " has an army of " << count << endl;
		for (size_t i = 0; i < warriors.size(); i++){
			cout << "\t" << warriors[i]->getName() << ": " << warriors[i]->getStrength() << endl;
		}
	}

	ostream& operator<<(ostream& os, const Noble& output){
		output.display(os);
		return os;
	}
}