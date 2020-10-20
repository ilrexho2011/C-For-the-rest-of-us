#include <iostream>
using namespace std;
int main()
{
    cout << "Think of a number between 1 and 100!" << endl;
    int highest = 100, lowest = 0, attempts = 0, guess = 0;
    char response;
    guess = {lowest + ((highest - lowest) * 0.5)};
    cout << "I guess " << guess << " Am I right?" << endl;
    cout << "'Q'/'q' to quit, 'Y'/'y' if correct, 'H'/'h' if too high, 'L'/'l' if too low." << endl;
    cout << "Enter your answer: ";
    cin >> response;
    attempts++;
    do {
            if ((response == 'Q' || response == 'q'))
            {
                goto label1;
            }
            else if ((response != 'Q' || response != 'q') || (response != 'H' || response != 'h') || (response != 'L' || response != 'l'))
            {
                cout << "I didn’t understand that response!" << endl;
                attempts++;
            }
                if (response == 'H' || response == 'h')
            {
                highest = guess;
                guess = lowest + ((highest - lowest) * 0.5);
                attempts++;
            }
            else if (response == 'L' || response == 'l')
            {
                lowest = guess;
                guess = lowest + ((highest - lowest) * 0.5);
                attempts++;
            }
            else if ((response == 'Y' || response == 'y'))
            {
                cout << "I guessed it in " << attempts << " attempts!" << endl; goto label2;
            }
            cout << "I guess " << guess << " Am I right?" << endl;
            cout << "'Q'/'q' to quit, 'Y'/'y' if correct, 'H'/'h' if too high, 'L'/'l' if too low." << endl;
            cout << "Enter your answer: " << endl;;
            cin >> response;
      } while (response != 'Y' || response != 'y');
    label1: cout << "Bye! Exited after " << attempts << " attempts!" << endl;
    label2: return 0;
}
