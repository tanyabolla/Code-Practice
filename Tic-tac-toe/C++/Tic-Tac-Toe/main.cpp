/* Chaitanya Bolla
   Implementation of Tic-Tac-Toe
   Personal Project
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void updateBoard(vector<char>& inputs){
	//Can be optimized by using a for loop by changing the amount of increment i += 2
	cout << "  " << inputs[0] << " ||  " << inputs[1] << " ||  " << inputs[2] << endl;
	cout << "=================" << endl;
	cout << "  " << inputs[3] << " ||  " << inputs[4] << " ||  " << inputs[5] << endl;
	cout << "=================" << endl;
	cout << "  " << inputs[6] << " ||  " << inputs[7] << " ||  " << inputs[8] << endl;
}

bool checkWin(vector<char>& inputs){
	//Checking wins
	//Check if all the tiles are full
	//Need to make sure if the space is already full, such as X or O is already been place in the space
	if (inputs[0] != ' ' && inputs[1] != ' ' && inputs[2] != ' ' && inputs[3] != ' ' && inputs[4] != ' ' && inputs[5] != ' ' && inputs[6] != ' ' && inputs[7] != ' ' && inputs[8] != ' '){
		cout << "Player One and Player Two tied! No one wins..." << endl;
		return true;
	}
	//Horizontal
	if ((inputs[0] == 'X' && inputs[1] == 'X' && inputs[2] == 'X') || (inputs[0] == 'O' && inputs[1] == 'O' && inputs[2] == 'O')){
		if (inputs[0] == 'X'){
			cout << "Player One wins!!" << endl;
			return true;
		}
		else{
			cout << "Player Two wins!!" << endl;
			return true;
		}
	}
	if ((inputs[3] == 'X' && inputs[4] == 'X' && inputs[5] == 'X') || (inputs[3] == 'O' && inputs[4] == 'O' && inputs[5] == 'O')){
		if (inputs[3] == 'X'){
			cout << "Player One wins!!" << endl;
			return true;
		}
		else{
			cout << "Player Two wins!!" << endl;
			return true;
		}
	}
	if ((inputs[6] == 'X' && inputs[7] == 'X' && inputs[8] == 'X') || (inputs[6] == 'O' && inputs[7] == 'O' && inputs[8] == 'O')){
		if (inputs[6] == 'X'){
			cout << "Player One wins!!" << endl;
			return true;
		}
		else{
			cout << "Player Two wins!!" << endl;
			return true;
		}
	}
	//Vertical
	if ((inputs[0] == 'X' && inputs[3] == 'X' && inputs[6] == 'X') || (inputs[0] == 'O' && inputs[3] == 'O' && inputs[6] == 'O')){
		if (inputs[0] == 'X'){
			cout << "Player One wins!!" << endl;
			return true;
		}
		else{
			cout << "Player Two wins!!" << endl;
			return true;
		}
	}
	if ((inputs[1] == 'X' && inputs[4] == 'X' && inputs[7] == 'X') || (inputs[1] == 'O' && inputs[4] == 'O' && inputs[7] == 'O')){
		if (inputs[1] == 'X'){
			cout << "Player One wins!!" << endl;
			return true;
		}
		else{
			cout << "Player Two wins!!" << endl;
			return true;
		}
	}
	if ((inputs[2] == 'X' && inputs[5] == 'X' && inputs[8] == 'X') || (inputs[2] == 'O' && inputs[5] == 'O' && inputs[8] == 'O')){
		if (inputs[2] == 'X'){
			cout << "Player One wins!!" << endl;
			return true;
		}
		else{
			cout << "Player Two wins!!" << endl;
			return true;
		}
	}
	//Diagonal
	if ((inputs[0] == 'X' && inputs[4] == 'X' && inputs[8] == 'X') || (inputs[0] == 'O' && inputs[4] == 'O' && inputs[8] == 'O')){
		if (inputs[0] == 'X'){
			cout << "Player One wins!!" << endl;
			return true;
		}
		else{
			cout << "Player Two wins!!" << endl;
			return true;
		}
	}
	if ((inputs[2] == 'X' && inputs[4] == 'X' && inputs[6] == 'X') || (inputs[2] == 'O' && inputs[4] == 'O' && inputs[6] == 'O')){
		if (inputs[2] == 'X'){
			cout << "Player One wins!!" << endl;
			return true;
		}
		else{
			cout << "Player Two wins!!" << endl;
			return true;
		}
	}
	return false;
}

void playerInputs(vector<char>& inputs, int input, bool playerOne){
	//The input must change from X and O: nested switch statments or if statements -- used a for loop, Done
	--input;
	for (size_t i = 0; i < inputs.size(); i++){
		if (i == input && playerOne){
			inputs[i] = 'X';
			updateBoard(inputs);
			break;
		}
		else if (i == input && playerOne == false){
			inputs[i] = 'O';
			updateBoard(inputs);
			break;
		}
	}
}

int main(){
	cout << "Tic Tac Toe" << endl;
	int input;
	vector<char> inputs(9, ' ');
	cout << "Let's play, shall we?" << endl;
	cout << "Each space represents a number from 1 - 9. The upper left space is 1 and the next one is 2, etc till we get to the lower right space, which is 9" << endl;
	//Prints the initial board, every space is empty
	updateBoard(inputs);

	//Getting player's choices
	//Need a loop here that terminates, if the player wins or all the spaces are full
	//Need to differentiate between player 1 and player 2's turn
	cout << "Player One is X and Player Two is O" << endl;
	bool playerOne = true; //it's player one's turn
	bool win = false;
	while (win != true){
		if (playerOne){
			cout << "Player One choose an empty tile (1 - 9): ";
			cin >> input;
			//playerOne = false; //switches x and o
			if (inputs[input - 1] == ' '){
				playerInputs(inputs, input, playerOne);
				playerOne = false;
			}
			else{
				cout << "That tile has already been chosen. Choose another" << endl;
				playerOne = true;
			}
			if (checkWin(inputs)){ break; } //can return a bool instead
		}
		else{
			cout << "Player Two choose an empty tile (1 - 9): ";
			cin >> input;
			//playerOne = true;
			if (inputs[input - 1] == ' '){
				playerInputs(inputs, input, playerOne);
				playerOne = true;
			}
			else{
				cout << "That tile has already been chosen. Choose another" << endl;
				playerOne = false;
			}
			if (checkWin(inputs)){ break; } //can return a bool instead
		}
	}
	return 0;
}