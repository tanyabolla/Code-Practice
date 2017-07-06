/*
	cb3172
	Chaitanya Bolla
	HW03: Nobles hire, fire, and battle using warriors against other nobles*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Warrior{
	//Warrior class - creates an object for a warrior
public:
	Warrior(const string& name, int power) : wName(name), strength(power){}
	string getName() const { return wName; }
	int getStrength() const { return strength; }
	void setStrength(int theStrength){ strength = theStrength; }
private:
	string wName;
	int strength;
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
	void hire(Warrior& someWarrior){
		warriors.push_back(&someWarrior);
	}
	void fire(Warrior& someWarrior){
		for (size_t i = 0; i < warriors.size(); i++){
			if (someWarrior.getName() == warriors[i]->getName()){
				cout << warriors[i]->getName() << ", you're fired! -- " << nName << endl;
				warriors.pop_back();
			}
		}
	}
	void battle(Noble& opponent){
		int power = 0;
		for (size_t i = 0; i < warriors.size(); i++){
			power += warriors[i]->getStrength();
		}
		int opponentPow = 0;
		for (size_t i = 0; i < opponent.warriors.size(); i++){
			opponentPow += opponent.warriors[i]->getStrength();
		}
		cout << nName << " battles " << opponent.nName << endl;

		if (power > opponentPow){
			cout << nName << " defeats " << opponent.nName << endl;
			setStrength(power -= opponentPow);
			opponent.setStrength(0);
		}
		else if (power < opponentPow){
			cout << opponent.nName << " defeats " << nName << endl;
			opponent.setStrength(opponentPow -= power);
			setStrength(0);
		}
		else if (power == 0 && opponentPow == 0){
			cout << "Oh NO! They are both dead! YUCK!!!" << endl;
		}
		else if (power == opponentPow){
			setStrength(0);
			opponent.setStrength(0);
			cout << "Mutual Annihilation: " << nName << " and " << opponent.nName << " die at each other's hands!" << endl;
		}
	}
	void display() const {
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

int main(){
	Noble art("King Arthur");
	Noble lance("Lancelot du Lac");
	Noble jim("Jim");
	Noble linus("Linus Torvalds");
	Noble billie("Bill Gates");

	Warrior cheetah("Tarzan", 10);
	Warrior wizard("Merlin", 15);
	Warrior theGovernator("Conan", 12);
	Warrior nimoy("Spock", 15);
	Warrior lawless("Xena", 20);
	Warrior mrGreen("Hulk", 8);
	Warrior dylan("Hercules", 3);

	jim.hire(nimoy);
	lance.hire(theGovernator);
	art.hire(wizard);
	lance.hire(dylan);
	linus.hire(lawless);
	billie.hire(mrGreen);
	art.hire(cheetah);

	jim.display();
	lance.display();
	art.display();
	linus.display();
	billie.display();

	art.fire(cheetah);
	art.display();

	art.battle(lance);
	jim.battle(lance);
	linus.battle(billie);
	billie.battle(lance);

	system("pause");
}