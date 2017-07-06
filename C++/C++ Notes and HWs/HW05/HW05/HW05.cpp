/*
	cb3172
	Chaitanya Bolla
	HW05: Implementing the warrior and noble class game from the previous homeworks
	with Inheritance and abstract classes
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Abstract Noble class
class Noble{
public:
	Noble(const string& name) : name(name), isDead(false), strength(0){}
	string getName() const { return name; }
	bool getDeath() const { return isDead; }
	void setDeath(){ isDead = true; }
	int getStrength() const { return strength; }
	void setStrength(int newStr){ strength = newStr; }
	//virtual void battle method
	virtual void battle(Noble& opponent) = 0;
private:
	string name;
	bool isDead;
	int strength;
};

//Abstract Protector class
class Protector{
public:
	Protector(const string& pName, int strength) : name(pName), strength(strength), noble(nullptr), isDead(false) {}
	string getName() const { return name; }
	int getStrength() const { return strength; }
	void setStrength(int newStrength){ strength = newStrength; }
	Noble* getNoble() const{ return noble; }
	void setNoble(Noble* nob) { noble = nob; }
	bool getDeath() const{ return isDead; }
	void setDeath(){ isDead = true; }
	//virtual void defend method
	virtual void battleCry() = 0;
private:
	string name;
	int strength;
	Noble* noble;
	bool isDead;
};

class Wizard : public Protector{
public:
	Wizard(const string& name, const int& mana) : Protector(name, mana){}
	//overridden battle cry method
	void battleCry() {
		if (!getDeath()){
			cout << "POOF!" << endl;
		}
	}
private:
};

class Archer : public Protector{
public:
	Archer(const string& name, const int& arrows) : Protector(name, arrows){}
	//overridden battle cry method
	void battleCry() {
		if (!getDeath()){
			cout << "TWANG!  ";
			cout << getName();
			cout << " says: Take that in the name of my lord, ";
			cout << getNoble()->getName();
			cout << endl;
		}
	}
private:
};

class Swordsman : public Protector{
public:
	Swordsman(const string& name, const int& blades) : Protector(name, blades){}
	//overridden battle cry method
	void battleCry() {
		if (!getDeath()){
			cout << "CLANG!  ";
			cout << getName();
			cout << " says: Take that in the name of my lord, ";
			cout << getNoble()->getName();
			cout << endl;
		}
	}
private:
};

class Lord : public Noble{
public:
	Lord(const string& name) : Noble(name) {}

	//finds collective sum of army's strengths
	int sumStrengths() const {
		int power = 0;
		for (size_t i = 0; i < army.size(); i++){
			power = power + army[i]->getStrength();
		}
		return power;
	}

	//hires a warrior and adds to army
	void hires(Protector& warrior){
		if (warrior.getNoble() == nullptr){
			warrior.setNoble(this);
			Protector* ptr = &warrior;
			army.push_back(ptr);
		}
		setStrength(sumStrengths());
	}

	void battle(Noble& opponent) {
		cout << getName() << " battles " << opponent.getName() << endl;
		//if both are dead
		if (opponent.getDeath() && getDeath()){
			cout << "Oh NO! They're both dead! Yuck!" << endl;
		}
		//if this one is dead
		else if (getDeath()){
			cout << "He's dead, " << opponent.getName() << endl;
		}
		//if the other is dead
		else if (opponent.getDeath()){
			cout << "He's dead, " << getName() << endl;
		}
		//if both kill each other
		else if (getStrength() == opponent.getStrength()){
			opponent.setStrength(0);
			opponent.setDeath();
			//kills all in the army
			for (size_t f = 0; f < army.size(); ++f){
				army[f]->setStrength(0);
			}
			setStrength(0);
			setDeath();
			cout << "Mutual Annihilation!" << endl;
		}
		//if this one is stronger than the opponent
		else if (getStrength() > opponent.getStrength()){
			opponent.setStrength(0);
			opponent.setDeath();
			for (size_t r = 0; r < army.size(); ++r){
				army[r]->battleCry();
				army[r]->setStrength(
					army[r]->getStrength() - (opponent.getStrength() / army.size()));
				if (army[r]->getStrength() < 0){
					army[r]->setStrength(0);
					army[r]->setDeath();
				}
			}
			cout << getName() << " defeats " << opponent.getName() << endl;
		}
		//if opponent is stronger
		else{
			opponent.setStrength(opponent.getStrength() - getStrength());
			for (size_t c = 0; c < army.size(); ++c){
				army[c]->battleCry();
				army[c]->setStrength(0);
				army[c]->setDeath();
			}
			setStrength(0);
			setDeath();
			cout << opponent.getName() << " defeats " << getName() << endl;
		}
	}
private:
	vector<Protector*> army;
};

class PersonWithStrengthToFight : public Noble{
public:
	PersonWithStrengthToFight(const string& name, const int& strength) : Noble(name) {
		setStrength(strength);
	}
	void battle(Noble& opp){ cout << "COCKS" << endl; }
private:
};

int main(){
	Lord sam("Sam");
	Archer samantha("Samantha", 200);
	sam.hires(samantha);
	Lord joe("Joe");
	PersonWithStrengthToFight randy("Randolf the Elder", 250);
	joe.battle(randy);
	joe.battle(sam);
	Lord janet("Janet");
	Swordsman hardy("TuckTuckTheHardy", 100);
	Swordsman stout("TuckTuckTheStout", 80);
	janet.hires(hardy);
	janet.hires(stout);
	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
	janet.battle(barclay);
	janet.hires(samantha);
	Archer pethora("Pethora", 50);
	Archer thora("Thorapleth", 60);
	Wizard merlin("Merlin", 150);
	janet.hires(pethora);
	janet.hires(thora);
	sam.hires(merlin);
	janet.battle(barclay);
	sam.battle(barclay);
	joe.battle(barclay);
	system("pause");
}