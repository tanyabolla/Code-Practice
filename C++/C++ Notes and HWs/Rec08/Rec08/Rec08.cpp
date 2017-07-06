#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Instrument{
public:
	virtual void makeSound() const = 0;
private:
};

class Brass : public Instrument {
public:
	Brass(const unsigned size) : size(size) {}
	virtual void makeSound() const = 0;
private:
	unsigned int size;
};

class Trumpet : public Brass {
public:
	Trumpet(const unsigned size) : Brass(size) {}
	virtual void makeSound() const {
		cout << "Toot" << endl;
	}
private:
};

class Trombone : public Brass {
public:
	Trombone(const unsigned size) : Brass(size) {}
	virtual void makeSound() const {
		cout << "Blat" << endl;
	}
private:
};

class String : public Instrument {
public:
	String(const unsigned int pitch) : pitch(pitch) {}
	virtual void makeSound() const = 0;
	int getPitch() const { return pitch; }
private:
	unsigned int pitch;
};

class Violin : public String {
public:
	Violin(const unsigned int pitch) : String(pitch) {}
	virtual void makeSound() const {
		cout << "Screech" << endl;
	}
private:
};

class Cello : public String {
public:
	Cello(const unsigned int pitch) : String(pitch) {}
	virtual void makeSound() const {
		cout << "Squawk" << endl;
	}
private:
};

class Percussion : public Instrument {
public:
	virtual void makeSound() const = 0;
private:
};

class Cymbal : public Instrument{
public:
	virtual void makeSound() const {
		cout << "Crash" << endl;
	}
private:
};

class Drum : public Instrument {
public:
	virtual void makeSound() const {
		cout << "Boom" << endl;
	}
private:
};

class MILL{
public:
	Instrument* loanOut(){
		Instrument* instr;
		for (size_t i = 0; i < instruments.size(); i++){
			if (instruments[i] != nullptr){
				instr = instruments[i];
				instruments[i] = nullptr;
				return instr;
			}
		}
		return nullptr;
	}

	Instrument* receiveInstr(Instrument& anInstr){
		for (size_t i = 0; i < instruments.size(); i++){
			if (instruments[i] == nullptr){
				instruments[i] = &anInstr;
				return instruments[i];
			}
		}
		instruments.push_back(&anInstr);
		return instruments[instruments.size() -1];
	}

	void dailyTestPlay() const {
		for (size_t i = 0; i < instruments.size(); i++){
			if (instruments[i] != nullptr){
				instruments[i]->makeSound();
			}
		}
	}
private:
	vector<Instrument*> instruments;
};

class Musician {
public:
	Musician() : instr(NULL) {}
	void acceptInstr(Instrument& i) { 
		instr = &i; 
	}
	Instrument* giveBackInstr() {
		Instrument* tmp(instr);
		instr = NULL;
		return tmp;
	}
	void testPlay() const {
		if (instr){
			instr->makeSound();
		}
		/*else{
			cerr << "have no instr\n";
		}*/
	}
private:
	Instrument* instr;
};

class Orchestra{
public:
	void addPlayer(Musician& mus){
		musicians.push_back(&mus);
	}
	void play() const{
		for (size_t i = 0; i < musicians.size(); i++){
			musicians[i]->testPlay();
		}
	}
private:
	vector<Musician*> musicians;
};

int main(){
	Drum drum;
	Cello cello(673);
	Cymbal cymbal;
	Trombone tbone(4);
	Trumpet trpt(12);
	Violin violin(567);

	MILL mill;
	mill.receiveInstr(trpt);
	mill.receiveInstr(violin);
	mill.receiveInstr(tbone);
	mill.receiveInstr(drum);
	mill.receiveInstr(cello);
	mill.receiveInstr(cymbal);

	Musician bob;
	Musician sue;
	Musician mary;
	Musician ralph;
	Musician jody;
	Musician morgan;

	Orchestra orch;

	//Bob joins the orchestra without an instrument.
	orch.addPlayer(bob);

	//The orchestra performs
	cout << "orch performs\n";
	orch.play();

	//Sue gets an instrument from the MIL2 and joins the orchestra.
	sue.acceptInstr(*mill.loanOut());
	orch.addPlayer(sue);

	//Ralph gets an instrument from the MIL2.
	ralph.acceptInstr(*mill.loanOut());

	//Mary gets an instrument from the MIL2 and joins the orchestra.
	mary.acceptInstr(*mill.loanOut());
	orch.addPlayer(mary);

	//Ralph returns his instrument to the MIL2.
	mill.receiveInstr(*ralph.giveBackInstr());

	//Jody gets an instrument from the MIL2 and joins the orchestra.
	jody.acceptInstr(*mill.loanOut());
	orch.addPlayer(jody);

	// morgan gets an instrument from the MIL2
	morgan.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Ralph joins the orchestra.
	orch.addPlayer(ralph);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	// bob gets an instrument from the MIL2
	bob.acceptInstr(*mill.loanOut());

	// ralph gets an instrument from the MIL2
	ralph.acceptInstr(*mill.loanOut());

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	//Morgan joins the orchestra.
	orch.addPlayer(morgan);

	//The orchestra performs.
	cout << "orch performs\n";
	orch.play();

	system("pause");
}