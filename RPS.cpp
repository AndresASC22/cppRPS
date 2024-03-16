#include<iostream>
#include<string>

void CPUchoice(int &RPS)
{
    RPS = rand() % 3 + 1;
    std::cout << RPS << std::endl;
} //This function generated either 1,2 or 3 to represent the CPU's choice
  //of rock, paper or scissors

int userRPS(std::string &user)
{
    if (user == "1"){
    return 1;
    }

    else if(user == "2"){
        return 2;
    }
    
     else if(user == "3"){
        return 3;
    }
    
    else{
        return -1;
    }
    
    return 0;
}

int winDecider(int &user, int &CPU) // 1 is rock, 2 is paper, 3 is scissors
{   //returning 4 means user won, returning 5 means CPU won, returning 6 means it was a draw
    
    while (user == 1) //While the user input is rock
    {
        if (CPU == 1){
            return 6;
        }

        else if (CPU == 2){
            return 5;
        }

        else{
            return 4;
        }
    }

    while (user == 2)
    {
        if (CPU == 1){
            return 4;
        }

        else if (CPU == 2){
            return 6;
        }

        else{
            return 5;
        }


    }

    while (user == 3)
    {
        if (CPU == 1){
            return 5;
        }

        else if (CPU == 2){
            return 4;
        }

        else{
            return 6;
        }
    }
    
    return 0;
}

int main()
{
    srand(time(0));
    int aiChoice = 0;
    CPUchoice(aiChoice);
    //aiChoice will now be either 1, 2 or 3
    int replay = 0;
    std::string userChoice;
    int userInput;

    while (replay == 0)
    {
        std::cout << "Enter 1 for rock, 2 for paper, 3 for scissors: ";
        std::cin >> userChoice;
        userInput = userRPS(userChoice);

        if(userInput == -1){
            std::cout << "Error: Wrong Input";
            return 0;
        }

        int winner;

        winner = winDecider(userInput, aiChoice);
        std::cout << winner << std::endl;

        switch(winner)
        {
            case 4:
                std::cout << "User won!" << std::endl;
                break;

            case 5:
                std::cout << "CPU won!" << std::endl;
                break;

            default:
                std::cout << "Draw !!!" << std::endl;
                break;
        }

        std::cout << "Do you want to play again? 1 for yes, 2 for no: ";
        std::cin >> userChoice;

        if (userChoice == "1"){
            replay = 0;
        }

        else{
            replay = 1;
        }
    }

    return 0;
}