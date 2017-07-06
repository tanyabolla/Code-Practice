#ifndef NOBLE_H
#define NOBLE_H

#include "Warrior.h"
#include <iostream>
#include <vector>
#include <string>

namespace WarriorCraft{
	class Warrior;
	class Noble{
	public:
		//Noble class - methods to hire, fire, and battle warriors in a war with other nobles
		Noble(const std::string& name);
		std::string getName() const;
		void setStrength(int newStrength);
		void hire(Warrior& someWarrior);
		void fire(Warrior& someWarrior);
		void battle(Noble& opponent);
		void display(std::ostream& os) const;
	private:
		std::string nName;
		std::vector<Warrior*> warriors;
	};
	std::ostream& operator<<(std::ostream& os, const Noble& output);
}
#endif