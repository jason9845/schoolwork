#include <iostream>
#include <cstdlib> //these 2 include statements are required to generate random numbers
#include <ctime>
using namespace std;

#define UPPER_BOUND 100
#define LOWER_BOUND 1

int main() {
  char again = 'Y';
  while(again == 'y' || again == 'Y') {
    srand(time(0));
    int secretNumber;
    int guessNumber = -1;
    int numberAttempts = 0;
    int low = 0;
    int up = 100;

    secretNumber = (double) rand() / RAND_MAX * (UPPER_BOUND-LOWER_BOUND+1) + LOWER_BOUND;

    while(guessNumber != secretNumber) {
      int mid = (up+low)/2;
      cout << "Lower bound: " << low << ", " << "Upper bound: " << up << endl;
      cout << "Guess: "; cin >> guessNumber;
      if(guessNumber < low || guessNumber > up) {
        cout << "Number out of range. Please guess again: "; cin >> guessNumber;
      } else if (guessNumber == secretNumber) {
        numberAttempts++;
        cout << "Correct Answer! You win" << endl;
      } else {
        if(secretNumber > mid) {
          low = (guessNumber < mid) ? guessNumber : mid;
        } else {
          up = (guessNumber > mid) ? guessNumber : mid;
        }
        numberAttempts++;
      }
      cout << "Number of attempts: " << numberAttempts << endl;
    }
    cout << "Again? "; cin >> again;
  }
  return 0;
}
