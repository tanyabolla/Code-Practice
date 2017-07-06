#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

// Load up our vector with numbers from the input file
bool populateVector(vector<int>& rodLengths) {
	// Change the file name here!
	ifstream profits("rodcutting2.txt");
	if (!profits) { cout << "The file does not exist.\n"; return false; }
	string line;
	getline(profits, line);
	while (getline(profits, line)) {
		stringstream s(line);
		int length, value;
		char comma;
		s >> length >> comma >> value;
		rodLengths.push_back(value);
	}
	return true;
}

// This is just a sanity check to see that you got the numbers from the input file correctly
void printRods(const vector<int>& rodLengths) {
	for (int i = 0; i < rodLengths.size(); i++)
		cout << "Length: " << i << " Profit: " << rodLengths[i] << endl;
}

// This uses the "brute force" approach, which takes an exponential amount of time!!!
int bestCutBrute(const vector<int>& rodLengths, int length) {
	// Base Case: If the rod is length 0, then it gives us a profit of 0
	if (length == 0) return 0;
	int bestProfit = 0;
	// Loop through all possible lengths of the "first cut" we make in the rod
	// Essentially this loop will go through all possible ways that we can cut up this rod
	for (int i = 1; i < length; i++)
		bestProfit = max(bestProfit, rodLengths[i] + bestCutBrute(rodLengths, length - i));
	return bestProfit;
}

// This uses the "dynamic" approach, which only takes a quadratic amount of time

int bestCutDynamic (const vector<int>& rodLengths, int length) {


}


int main() {
	vector<int>	rodLengths;
	if (!populateVector(rodLengths)) return 0;
	printRods(rodLengths);
	cout << "Max profit is: " << bestCutBrute(rodLengths, rodLengths.size()) << endl;
	//cout << "Max profit is: " << bestCutDynamic(rodLengths, rodLengths.size()) << endl;
	//system("pause");
}