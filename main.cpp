#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void rules();
int main()
{
    string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;
    srand(time(0));

    cout<<"\n\t\t===WELCOME TO CASINO ROYALE===\n\n";
    cout<<"\n\What's your name?"<<endl;
    getline(cin, playerName);
    cout<<"\nEnter the starting balance to play the game:$ ";
    cin>>balance;
    do
    {
        system("clear");
        rules();
        cout<<"\n\Your balance is $ "<<balance<<endl;
        do
        {
            cout<<"Hey, " <<playerName<< ", enter amount to bet: $";
            cin>>bettingAmount;
            if (bettingAmount > balance)
                cout<<"Betting balance can't be more than current balance!\n"
                    <<"\nRe-enter balance\n";
        } while (bettingAmount > balance);
        do
        {
            cout<<"Guess any betting number between 1 and 10: ";
            cin>>guess;
            if (guess <= 0 || guess > 10)
                cout<<"\nNumber should be between 1 to 10\n"
                    <<"Re-enter number:\n";
        } while (guess <=0 || guess > 10);
        dice = rand()%10 + 1;
        if (dice == guess) {
            cout<<"\n\You're in luck! You have won $" << bettingAmount*10;
            balance = balance + bettingAmount*10;
        }
        else {
            cout<<"Oops, better luck next time! You lost $" << bettingAmount;
        }
        cout<<"\nThe winning number was: " << dice << "\n";
        balance = balance - bettingAmount;
        cout<<"\n"<< playerName <<", you have a balance of $" <<balance<<"\n";
        if (balance == 0) {
            cout<<"You have no money to play.";
            break;
        }
        cout<<"\n\nWould you like to play again? (y/n)";
        cin>>choice;
    } while (choice == 'y' || choice == 'y');
    cout<<"\n\n\n";
    cout<<"\n\nThanks for playing the game! Your balance is $" << balance << "\n\n";
    return 0;
}
void rules()
{
    system("clear");
    cout<<"\t\t===RULES===\n";
    cout<<"\t1. Choose a number between 1 and 10\n";
    cout<<"\t2. Winner gets 10 times of the money bet\n";
    cout<<"\t3. Wrong bet, and you lose the amount you've placed\n\n";
}
