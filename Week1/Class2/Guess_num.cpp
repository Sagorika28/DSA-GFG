// Given an integer N. A number guessing game is a simple guessing game where a user is supposed to guess a number
// between 0 and N in a maximum of 10 attempts. The game will end after 10 attempts and if the player failed to guess the number,
// and then he loses the game.

#include <cmath>
#include <iostream>
using namespace std;
// Function that generate a number in
// the range [1, N] and checks if the
// generated number is the same as the
// guessed number or not
void guess(int N)
{
    int number, guess, numberofguess = 0;

    // Generate a random number
    number = rand() % N;

    cout << "Guess a number between 1 and " << N;

    // Using a do-while loop that will work until user guesses the correct number
    do
    {
        if (numberofguess > 9)
        {
            cout << "\nYou Loose!\n";
            break;
        }

        // Input by user
        cin >> guess;

        // When user guesses lower than actual number
        if (guess > number)
        {
            cout << "Lower number please!\n";
            numberofguess++;
        }

        // When user guesses higher than actual number
        else if (number > guess)
        {
            cout << "Higher number please!\n";
            numberofguess++;
        }

        // Printing number of times user has taken to guess the number
        else
            cout << "You guessed the number in " << numberofguess << " attempts!\n";

    } while (guess != number);
}

// Driver Code
int main()
{
    int N = 100;

    // Function call
    guess(N);

    return 0;
}