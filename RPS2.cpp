#include<iostream>
using namespace std;

int RPScheck(int& user, int& AI);
void RPSai(int& a);


int main() {
    int userChoice, rpsAIChoice = 0;
    int userWin;
    int userWinCount = 0, AIwinCount = 0;
    int continueGame, i = 0, j = 0;

    while (i == 0) //This loop gives the possibilty to replay the game
    {
        while (j == 0) { //This loop ensures that a invalid input won't screw anything up
            cout << "Enter 1 for Rock, 2 for Paper and 3 for Scissors: ";
            cin >> userChoice;
            if (userChoice != 1 && userChoice != 2 && userChoice != 3)
                cout << "Invalid Input!" << endl;

            else
                j++;
        }

        RPSai(rpsAIChoice); //AI will generate the choice for the RPS AI
        userWin = RPScheck(userChoice, rpsAIChoice); //Function will see who wins the match

        if (userWin == 1)
            userWinCount++;

        else if (userWin == 2)
            AIwinCount++;

        else //Draw statement
            cout << "Draw!!!" << endl;

        cout << "User wins: " << userWinCount << " AI wins: " << AIwinCount << endl;

        cout << "Do you want to continue playing? 1 for yes, 2 for no: ";
        cin >> continueGame;

        switch (continueGame) {
        case 1:
            i = 0;
            break;
        default:
            return 0;
        }
    }
}

void RPSai(int& a) {
    srand(time(0));
    a = (rand() % 3) + 1;
    cout << a << endl;
} //Randomly Generates input for the RPS AI

int RPScheck(int& user, int& AI) { //Checking to see who won, 1 is rock, 2 is paper, 3 is scissors
    while (user == 1) { //Returning 3 means tie, returning 2 means AI won, Returning 1 means User won
        if (AI == 1)
            return 3;


        if (AI == 2)
            return 2;


        if (AI == 3)
            return 1;

    }

    while (user == 2) {
        if (AI == 1)
            return 1;

        if (AI == 2)
            return 3;

        if (AI == 3)
            return 2;
    }

    while (user == 3) {
        if (AI == 1)
            return 2;

        if (AI == 2)
            return 1;

        if (AI == 3)
            return 3;
    }
}
