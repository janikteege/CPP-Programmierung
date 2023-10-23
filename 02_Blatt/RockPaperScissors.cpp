#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Choice {
    Rock = 1,
    Paper = 2,
    Scissors = 3
};

const char* handToString(Choice hand)
{
    switch(hand){
        case Rock:
            return "1: Rock";
        case Paper:
            return "2: Paper";
        case Scissors:
            return "3: Scissors";
        default:
            return "invalid";
    }
}

/*
 * Determines if choice1 beats choice2.
 *
 * Valid values for both parameters are:
 * 1: Rock
 * 2: Paper
 * 3: Scissors
 *
 * Rock beats Scissors, Paper beats Rock, Scissors beat Paper.
 *
 * Returns true if choice1 beats choice2
 */
bool beats(Choice choice1, Choice choice2)
{
    if ((choice1 == Rock && choice2 == Scissors) ||
        (choice1 == Paper && choice2 == Rock) || 
        (choice1 == Scissors && choice2 == Paper)) {
        return true;
    }
    return false;
}

Choice getRandomHand() {
    return Choice(rand() % 3 + 1);
}

/*
 * Performs a game of Rock-Paper-Scissors.
 *
 * Prompts the player for a choice of Rock, Paper or Scissors (1, 2 or 3)
 * and chooses a second choice to play against.
 *
 * Displays the choice of the player and computer.
 *
 * Returns true if the player wins, false if the player loses.
 * Repeats the game in case of a draw.
 */
bool play()
{
    int playerInput;
    // Insert your code here
    while(true)
    {
        cout << "Choose a hand: \n"
             << handToString(Rock) << "\n"
             << handToString(Paper) << "\n"
             << handToString(Scissors)  << "\n"
             << "0: exit\n";
        cout << "Your choice: ";
        cin >> playerInput;
        if(playerInput == 0) return 0;
        if(playerInput < 1 || playerInput > 3)
        {
            cout << "Invalid choice\n";
            continue;
        }
        break;
    }
    Choice computerChoice = getRandomHand();
    Choice playerChoice = Choice(playerInput);

    cout << "Computer chose: "
         << handToString(computerChoice) << "\n";
    
    return beats(playerChoice, computerChoice);
}


/*
 * Performs three games of Rock-Paper-Scissors and returns true if the player
 * wins at least two of them.
 */
bool bestOf3()
{
    int nOfWins = 0;
    for (int i = 0 ; i < 3; i++) {
        cout << "\nRound " << i+1 << ":\n";
        bool result = play(); 
        if (result) {
            nOfWins++;
        }
        cout << "You won " << nOfWins << "/" << i+1 << " times \n";
    }
    return nOfWins >= 2;
}


/*
 * Performs five games of Rock-Paper-Scissors and returns true if the player
 * wins at least three of them.
 */
bool bestOf5()
{
    int nOfWins = 0;
    for (int i = 0 ; i < 5; i++) {
        cout << "\nRound " << i+1 << ":\n";
        bool result = play(); 
        if (result) {
            nOfWins++;
        }
        cout << "You won " << nOfWins << "/" << i+1 << " times \n";
    }
    return nOfWins >= 3;
}


/******************************************************************************/
// Template code starts here. Please do not edit beyond this point.
/******************************************************************************/

/*
 * Converts a game mode choice into the game mode's name for display purposes.
 *
 * Note: we can only return a raw pointer here because string literals have
 * static storage duration i.e. they survive for the whole run time of the
 * program. Returning a pointer to something that is not a string literal
 * would be dangerous!
 */
const char* gameModeToString(int mode)
{
    switch(mode){
        case 1:
            return "Single";
        case 2:
            return "Best of Three";
        case 3:
            return "Best of Five";
        default:
            return "invalid";
    }
}


int main()
{
    // Initialize random seed
    srand(time(nullptr));

    int mode = 0;
    while(true)
    {
        cout << "Choose a game mode: \n"
             << "1: " << gameModeToString(1) << "\n"
             << "2: " << gameModeToString(2) << "\n"
             << "3: " << gameModeToString(3)  << "\n"
             << "0: exit\n";
        cout << "Your choice: ";
        cin >> mode;
        if(mode == 0) return 0;
        if(mode < 1 || mode > 3)
        {
            cout << "Invalid choice\n";
            continue;
        }
        break;
    }

    bool won = false;
    switch(mode)
    {
        case 1:
            won = play();
            break;
        case 2:
            won = bestOf3();
            break;
        case 3:
            won = bestOf5();
            break;
        default:
            // unreachable code
            return -1;
    }

    if(won)
    {
        cout << "Congratulations! You win the game!\n";
    }
    else
    {
        cout << "Unfortunate! You lose the game.\n";
    }

    return 0;
}
