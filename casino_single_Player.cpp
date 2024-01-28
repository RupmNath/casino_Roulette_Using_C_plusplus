#include <iostream>  // for I/O
#include <windows.h> // for Windows-specific functions/features
#include <cstdlib>   // for general purpose
#include <ctime>     // for time related functions
#include <string>    // for string
using namespace std;

// intro function
void intro(){
    string var = "\n====================================================================================================="
                 "\n=       CCCCCCCC         A       SSSSSSSSSSSSSS  IIIIIIIIII  NN            NN       OOOOOOOOOO      ="
                 "\n=    CCCC               A A      SSSS            IIIIIIIIII  NN NN         NN     OOO        OOO    ="
                 "\n=   CCC                A   A     SSSSSS             III      NN   NN       NN   OOO           OOO   ="
                 "\n=  CC                 A     A    SSSSSSSSSSSSSS     III      NN     NN     NN  OOO             OOO  ="
                 "\n=   CCC              AAAAAAAAA           SSSSSS     III      NN       NN   NN   OOO           OOO   ="
                 "\n=    CCCC           A         A            SSSS  IIIIIIIIII  NN         NN NN    OOO         OOO    ="
                 "\n=       CCCCCCCC   A           A  SSSSSSSSSSSSS  IIIIIIIIII  NN            NN      OOOOOOOOOOO      ="
                 "\n=====================================================================================================";
    for(int i=0;i<var.size();i++)// size function to compared with int variable 'i'
    {
        // to delay the printing
        Sleep(5);
        cout<<var[i];
    }
    cout<<endl;
}

// rules function
void rules()
{
    string var ="\n=================================================================================================="
                "\n=                                        GAME RULES                                              ="
	            "\n=================================================================================================="
            	"\n= 1. Choose Number Between 0 To 32.                                                              ="
            	"\n= 2. Winning Amount Will Be 32 Times Of Bid Amount.                                              ="
            	"\n= 3. Loose Amount Will Be Biding Amount.                                                         ="
             	"\n= 4. You Can Leave A Game Any Time.                                                              ="
               	"\n==================================================================================================";
    for(int i=0;i<var.size();i++)
    {
        Sleep(5);
        cout<<var[i];
    }
    cout<<endl;
}

// name input function
void name()
{
    string name;
    cout << "Enter your name: ";
    getline(cin, name); // getline to take string as input
    cout << "Welcome to the game: " << name << endl;
}

// Account balance
double initialBalance()
{
    double money;
    cout << "Enter the deposite: ";
    cin >> money;
    return money;
}

// betting ammount
double bettingAmount()
{
    double bet;
    cout << "Enter your bet: ";
    cin >> bet;
    return bet;
}

// random number generator
int randNumGen()
{
    int num;
    srand(time(NULL));
    num = rand() % 33;
    return num;
}

// player's lucky number
int playerNumber()
{
    int playerNum;
    cout << "Enter your lucky number: ";
    cin >> playerNum;
    return playerNum;
}

// game betting code with balance and betting as parameter
void gameLogic(double balance, double betting)
{
    char continueGame = 'y'; // Initialize to start the loop
    while (continueGame == 'y')
    {
        int randNum;
        if (betting > balance) // Check if the betting amount is greater than the balance
        {
            cout << "Insufficient balance! Please place a bet within your available balance.\n";
            betting = bettingAmount(); // Get a new betting amount
            continue;                  // Continue to the next iteration of the loop
        }
        // Ask the user for their lucky number
        int playerNum = playerNumber();
        // Check if the player's number is valid (between 0 and 32)
        if (playerNum < 0 || playerNum > 32)
        {
            cout << "Invalid number! Please choose a number between 0 and 32.\n";
            continue; // Continue to the next iteration of the loop
        }

        // Generate a random number
        randNum = randNumGen();
        cout << "The ball stopped at number: " << randNum << endl;

        // Check if the player's number matches the random number
        if (playerNum == randNum)
        {
            balance = balance + (betting * 32);
            cout << "Congratulations! You won. Your current balance: " << balance << endl;
        }
        else
        {
            balance = balance - betting;
            cout << "Oops! You lost. Your current balance: " << balance << endl;
        }

        // Ask the player if they want to continue playing
        cout << "Would you like to continue playing the game?" << endl;
        cout << "Type 'y' and hit enter to continue or type 'n' and hit enter to exit." << endl;
        cin >> continueGame;

        // If the player wants to continue, get a new betting amount
        if (continueGame == 'y')
        {
            betting = bettingAmount();
        }
    }
}

// main function
int main()
{
    // caling intro function
    intro();
    // calling rules function
    rules();
    // calling name function
    name();
    // calling and assigning balance function
    double balance = initialBalance();
    // calling and assigning betting function
    double betting = bettingAmount();
    // calling the game function
    gameLogic(balance, betting);
    return 0;
}