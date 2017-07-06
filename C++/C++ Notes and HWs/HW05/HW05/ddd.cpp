//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//
////Abstract Noble class
//class Noble{
//public:
//	//Noble class - methods to hire, and battle warriors in a war with other nobles
//	Noble(const string& name) : nName(name), strength(0), isAlive(true) {}
//	string getName() const { return nName; }
//	bool getStateOfLiving() const { return isAlive; }
//	void setStateOfLiving() { isAlive = false; }
//	int getStrength(){ return strength; }
//	void setStrength(int newStrength){ strength = newStrength; }
//	//Pure virtual battle method
//	virtual void battle(Noble& opponent) = 0;
//private:
//	string nName;
//	int strength;
//	bool isAlive;
//};
//
////Abstract Protector class
//class Protector{
//public:
//	Protector(const string& name, int power) : wName(name), strength(power), noble(nullptr), isAlive(true) {}
//	string getName() const { return wName; }
//	int getStrength() const { return strength; }
//	void setStrength(int theStrength){ strength = theStrength; }
//	bool getLiving() const { return isAlive; }
//	void setLiving(){ isAlive = false; }
//	Noble* getNoble() const { return noble; }
//	void setNoble(Noble* nob) { noble = nob; }
//	//Pure virtual battleCry method
//	virtual void battleCry() const = 0;
//private:
//	string wName;
//	int strength;
//	bool isAlive;
//	Noble* noble;
//};
//
//class Swordsman : public Protector{
//public:
//	Swordsman(const string& name, int strength) : Protector(name, strength) {}
//	void battleCry() const {
//		if (!getLiving()){
//			cout << "CLANG!  ";
//			cout << getName();
//			cout << " says: Take that in the name of my lord, ";
//			cout << getNoble()->getName();
//			cout << endl;
//		}
//	}
//private:
//};
//
//class Archer : public Protector{
//public:
//	Archer(const string& name, int strength) : Protector(name, strength) {}
//	void battleCry() const {
//		if (!getLiving()){
//			cout << "TWANG!  ";
//			cout << getName();
//			cout << " says: Take that in the name of my lord, ";
//			cout << getNoble()->getName();
//			cout << endl;
//		}
//	}
//private:
//};
//
//class Wizard : public Protector{
//public:
//	Wizard(const string& name, int strength) : Protector(name, strength) {}
//	void battleCry() const {
//		if (getLiving()){
//			cout << "POOF!!" << endl;
//		}
//	}
//private:
//};
//
//class Lord : public Noble{
//public:
//	Lord(const string& name) : Noble(name) {}
//	void hires(Protector& someProtector){
//		//hires a warriors for the noble
//		if (someProtector.getNoble() == nullptr){
//			someProtector.setNoble(this);
//			Protector *ptr = &someProtector;
//			protectors.push_back(ptr);
//		}
//		setStrength(sumStrengths());
//	}
//	int sumStrengths() const {
//		int power = 0;
//		for (size_t i = 0; i < protectors.size(); i++){
//			power += protectors[i]->getStrength();
//		}
//		return power;
//	}
//	void battle(Noble& opponent){
//		//battles another noble using the warriors that were hired
//		cout << getName() << " battles " << opponent.getName() << endl;
//		if (getStrength() == 0 && opponent.getStrength() == 0){
//			cout << "Oh, NO! They're both dead! YUCK!!!" << endl;
//		}
//		else if (getStrength() != 0 && opponent.getStrength() == 0){
//			cout << "He's dead, " << getName() << endl;
//		}
//		else if (getStrength() == 0 && opponent.getStrength() != 0){
//			cout << "He's dead, " << opponent.getName() << endl;
//		}
//		else if (getStrength() > opponent.getStrength()){
//			opponent.setStrength(0);
//			opponent.setStateOfLiving();
//			for (size_t i = 0; i < protectors.size(); i++){
//				protectors[i]->battleCry();
//				protectors[i]->setStrength(protectors[i]->getStrength() - (opponent.getStrength() / protectors.size()));
//				if (protectors[i]->getStrength() < 0){
//					protectors[i]->setStrength(0);
//					protectors[i]->setLiving();
//				}
//			}
//			cout << getName() << " defeats " << opponent.getName() << endl;
//		}
//		else if (getStrength() < opponent.getStrength()){
//			opponent.setStrength(opponent.getStrength() - getStrength());
//			for (size_t i = 0; i < protectors.size(); i++){
//				protectors[i]->battleCry();
//				protectors[i]->setStrength(0);
//				protectors[i]->setLiving();
//			}
//			setStrength(0);
//			setStateOfLiving();
//			cout << opponent.getName() << " defeats " << getName() << endl;
//		}
//	}
//private:
//	vector<Protector*> protectors;
//};
//
//class PersonWithStrengthToFight : public Noble{
//public:
//	PersonWithStrengthToFight(const string& name, int strength) : Noble(name){
//		setStrength(strength);
//	}
//	void battle(Noble& opp){
//		cout << "COCKS" << endl;
//	}
//private:
//};
//
//int main(){
//	Lord sam("Sam");
//	Archer samantha("Samantha", 200);
//	sam.hires(samantha);
//	Lord joe("Joe");
//	PersonWithStrengthToFight randy("Randolf the Elder", 250);
//	joe.battle(randy);
//	joe.battle(sam);
//	Lord janet("Janet");
//	Swordsman hardy("TuckTuckTheHardy", 100);
//	Swordsman stout("TuckTuckTheStout", 80);
//	janet.hires(hardy);
//	janet.hires(stout);
//	PersonWithStrengthToFight barclay("Barclay the Bold", 300);
//	janet.battle(barclay);
//	janet.hires(samantha);
//	Archer pethora("Pethora", 50);
//	Archer thora("Thorapleth", 60);
//	Wizard merlin("Merlin", 150);
//	janet.hires(pethora);
//	janet.hires(thora);
//	sam.hires(merlin);
//	janet.battle(barclay);
//	sam.battle(barclay);
//	joe.battle(barclay);
//	system("pause");
//}