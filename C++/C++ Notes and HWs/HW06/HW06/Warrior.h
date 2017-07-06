#ifndef WARRIOR_H
#define WARRIOR_H

#include "Noble.h"
#include <iostream>
#include <vector>
#include <string>

namespace WarriorCraft{
	class Noble;
	class Warrior{
	public:
		//Warrior class - creates an object for a warrior
		Warrior(const std::string& name, int power);
		std::string getName() const;
		int getStrength() const;
		void setStrength(int theStrength);
		bool getEmployment() const;
		void setEmployment(bool hasJob);
		Noble* getNoble() const;
		void setNoble(Noble* nob);
		void runaway();
	private:
		std::string wName;
		int strength;
		Noble* noble;
		bool isEmployed;
	};
}
#endif