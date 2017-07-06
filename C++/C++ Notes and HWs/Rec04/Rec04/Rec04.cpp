#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sandwich{
public:
	Sandwich(int c = 1, double ma = 0.1, double mu = 0.05, int t = 2) : bread(2), cheese(c), mayo(ma), mustard(mu), tomato(t){}
	void display() const {
		cout << "Bread: " << bread << endl;
		cout << "Cheese: " << cheese << endl;
		cout << "Mayo: " << mayo << endl;
		cout << "Mustard: " << mustard << endl;
		cout << "Tomato: " << tomato << endl;
	}

	//Accessors
	int getCheese() const { return cheese; } //getter - accessor
	double getMayo() const { return mayo; }
	double getMustard() const { return mustard; }
	int getTomato() const { return tomato; }

	//Mutators
	void setCheese(int cheese1) { cheese = cheese1; } //setter - mutators
	void setMayo(double mayo1) { mayo = mayo1; }
	void setMustard(double mustard1) { mustard = mustard1; }
	void setTomato(int tomato1) { tomato = tomato1; }

private:
	const int bread;
	int cheese;
	double mayo;
	double mustard;
	int tomato;
};

class Truck{
public:
	void insertSandwich(const Sandwich& aSandwich){
		truck.push_back(aSandwich);
	}
	void checkBeforeLeaving() const {
		for (size_t i = 0; i < truck.size(); i++){
			cout << "Sandwich: " << i+1 << endl;
			cout << "---------\n";
			truck[i].display();
			cout << "=============\n";
		}
	}
private:
	vector<Sandwich> truck;
};

int main(){
	Sandwich S1;
	Sandwich S2;
	S2.setMustard(0.0);
	Sandwich S3;
	S3.setCheese(2);
	Sandwich S4;

	Truck aTruck;
	aTruck.insertSandwich(S1);
	aTruck.insertSandwich(S2);
	aTruck.insertSandwich(S3);
	aTruck.insertSandwich(S4);

	aTruck.checkBeforeLeaving();
	cout << "Mustard: " << S2.getMustard() << endl;
	
	system("pause");
}