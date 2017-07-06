#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
//Why can't you just do pass by constant value since you don't change it anyway?
//You don't want it to be a copy since it isn't as efficient, by reference is also an alias

//Structs - defining types
struct Word{
	string token; //a word
	vector<int> positions; //where does it occur in a file
};

//int index = findToken(token, words);
//int findToken(const string& token, vector<Word>& words){
size_t findToken(const string& token, const vector<Word>& words){ //pass by reference
	//Can't do foreach/ranged for loop
	//for (Word& word : words){
	//	if (token == word.token){
	//		return; //can't return the index
	//	}
	//}
	for (size_t i = 0; i < words.size(); i++){
		if (token == words[i].token){
			return i;
		}
		//else{
		//	return -1; //returns -1 many times
		//	//NO ELSE 
		//}
	}
	//returning index is a size_t so return type should be size_t as well
	//return -1; since the function returns size_t and -1 is not in the range, can't use
	return words.size(); //return something else after the loop if there's no success
}

void addNewWord(const string& token, int position, vector<Word>& words) {
	Word aWord;
	aWord.token = token; //don't worry about uppercase/lowercase
	aWord.positions.push_back(position);
	words.push_back(aWord);
}

void displayWords(const vector<Word>& words) {
	for (const Word& word : words) {
		cout << word.token << ":";
		for (int pos : word.positions) {
			cout << ' ' << pos;
		}
		cout << '.' << endl;
	}
}

//gazillion lines of text files - how often does that word occur, where does it occur, etc.
//web search engines care about this - tokens - store information about them
//where they exist in the document? - type in the search engine - get the information you wanted
//How would you represent/group the information?
//Code is secondary to how you want to group the information (create a solution first, then code it)

//Where in the program does the word "the" show up?
//Every occurence of it
//Collection of all the places it shows up (vector of positions) and a token (the word we are searching for such as "the", "is", etc).

int main(){
	//Open jabberwocky
	ifstream ifs("jabberwocky.txt");
	if (!ifs){
		cerr << "Could not open the file!";
		exit(1);
	}

	//Fill up the collection with words from the file
	vector<Word> words;

	//A bit more complicated!
	//Collection within a collection
	//Check to see if a certain word already exists in the vector of words
	string token;
	int position = 0;
	while (ifs >> token){
		//Have we seen this word already?
		int index = findToken(token, words);
		if (index < words.size()){ //FOUND IT!!!!
		//If we have seen this word already, we need to find it to add the new position of another occurence
			words[index].positions.push_back(position); 
			//since you already have the index, you do not have to loop through
		}
		else{
			//Word aWord;
			//aWord.token = token; //don't worry about uppercase/lowercase
			//aWord.positions.push_back(position);
			//words.push_back(aWord);
			addNewWord(token, position, words);
			//++position;
		}
		++position; //starts at 0 so increment after one push_back to make it correct
	}
	displayWords(words);
	system("pause");
}