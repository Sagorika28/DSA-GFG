// Given an integer N. A number guessing game is a simple guessing game where a user is supposed to guess a number
// between 0 and N in a maximum of 10 attempts. The game will end after 10 attempts and if the player failed to guess the number,
// and then he loses the game. -- O(log n)

#include <iostream>
using namespace std;

void guess(int n, int number)
{
    int beg = 0, end = n, numberofguess = 1, guess;
    do
    {
        if (numberofguess > 9)
        {
            cout << "\nYou Loose!\n";
            break;
        }

        guess = (beg + end) / 2;
        cout << guess << " ";

        if (guess > number)
        {
            end = guess - 1;
            numberofguess++;
        }

        // When user guesses higher than actual number
        else if (number > guess)
        {
            beg = guess + 1;
            numberofguess++;
        }
    } while (guess != number || beg > end);

    // Printing number of times user has taken to guess the number
    cout << "\nThe number was guessed in " << numberofguess << " attempts!\n";
}

// Driver Code
int main()
{
    int N;
    int number;
    cout << "Enter range N and number to be guessed: ";
    cin >> N >> number;
    // Function call
    guess(N, number);
    return 0;
}