#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
const int MAX_HANDS = 4; // maximum hands a player can have
typedef int intArray[MAX_HANDS][10]; // to store player cards

// identify the hand and suit
const char handType[MAX_HANDS][8] = {"Player", "split", "split 2", "split 3"};
const char SUIT[4] = {'H', 'S', 'D', 'C'};

// function prototypes
void game(int, int &, int [], int [], int [], int [], intArray);
void split(int &, int, intArray);
int calcScore(int [], int);
void printCard(int [], int);
void printHand(int [], int);
void drawCard(int [], int [], int);
void createDeck(int []);
void shuffleDeck(int []);
void result(int, int&, double&, double& , double &, int, double [], int [], int []);

int main() {
  char again = 'Y';
  double amount = 100;
  while(again == 'Y' || again == 'y'){
    int splitCount = 0; // number of times split has occurred
    double pay = 0; double amountWon[4] = {0}; double totalWin = 0;

    cout << "Player: $" << amount << endl;
    cout << "Pay for this round: "; cin >> pay;

    // index stores the card count, because the deck stores both card number
    // and the suite type, card count is always double the number of cards the player has
    int dealerCards[10] = {0}; int dealerScore = 0; int dealerIndex = 2;
    intArray playerCards = {0}; int playerScore[4] = {0}; int playerIndex[4] = {2, 2, 2, 2};

    // create a new deck of cards depending on the case
    // 52 cards, even indexes store card value and odd indexes store the type of suit
    int deck[104] = {3, 3, 7, 2, 2, 2, 2, 0, 5, 3, 9, 2, 10, 0, 2, 3, 4, 2, 3, 1, 4, 0, 11, 2, 0};
    char test;
        cout << "Test Case? (Y/N): "; cin >> test;
        if (test != 'y' && test != 'Y'){
          // deck is created and shuffled
          createDeck(deck); srand(time(0)); shuffleDeck(deck);
        }
    // draw the initial cards
    drawCard(deck, dealerCards, 0); drawCard(deck, dealerCards, 2);
    drawCard(deck, playerCards[0], 0); drawCard(deck, playerCards[0], 2);

    // starts the game and starts a new game for each split
    int i;
    for (i = 0; i <= splitCount; i++) {
      game(i, splitCount, playerIndex, playerScore, deck, dealerCards, playerCards);
    }

    // dealer draws cards after the player has finished drawing cards
    dealerScore = calcScore(dealerCards, dealerIndex);
    while(dealerScore < 17 && dealerIndex < 10) {
      dealerIndex += 2;
      drawCard(deck, dealerCards, dealerIndex);
      dealerScore = calcScore(dealerCards, dealerIndex);
    }

    // prints the final hand
    cout << "> Dealer: "; printHand(dealerCards, dealerIndex); cout << endl;
    for(int j = 0; j < i; j++ ) {
    cout << "> " << handType[j] << ": ";
    printHand(playerCards[j], playerIndex[j]);
    cout << endl;
    }

    // prints the score and distributes the rewards
    cout << "Dealer " << dealerScore << " points,Player "; i--;
    for(int j = 0; j <= i; j++) {
      result(j, i, totalWin, amount, pay, dealerScore, amountWon, playerIndex, playerScore);
    }
    cout << endl;

    // prints the end result
    if(totalWin > 0) {
      cout << "Player Win !!";
    } else if(totalWin ==  0){
      cout << "Tie";
    } else {
      cout << "Player Lost";
    }
    cout << endl; cout << "> Again? (Y/N): "; cin >> again;
  }
  return 0;
}

// starts the round
void game(int i, int &splitCount, int playerIndex[], int playerScore[], int deck[], int dealerCards[], intArray playerCards) {
  char draw;
  while(playerIndex[i] < 10) {

    // print the cards drawn so far
    cout << "> Dealer: * "; printCard(dealerCards, 2); cout << endl;
    for(int x = 0; x <= splitCount; x++) {
      cout << "> " << handType[x] << ": ";
      playerScore[x] = calcScore(playerCards[x], playerIndex[x]);
      printHand(playerCards[x], playerIndex[x]);
      cout << endl;
    }

    // check for possible split
    if(playerCards[i][0] == playerCards[i][2] && playerIndex[i] == 2) {
      char askSplit; cout << "Split ? (Y/N): "; cin >> askSplit;
      if(askSplit == 'y' || askSplit == 'Y') {
        split(splitCount, i, playerCards);
        splitCount++;
        drawCard(deck, playerCards[i], 2); drawCard(deck, playerCards[i + 1], 2);
        cout << endl; continue;
      }
    }

    // end conditions
    if(playerScore[i] > 21) {
      cout << endl;
      break;
    }

    // asks if the player wants to draw again
    if (i == 0) {
      cout << "Draw? (Y/N): ";
    } else {
      cout << "Draw for " << handType[i] << "? (Y/N): ";
    }
    cin >> draw; cout << endl;
    if(draw != 'y' && draw != 'Y') {
      break;
    }

    // new card is drawn
    playerIndex[i] += 2;
    drawCard(deck, playerCards[i], playerIndex[i]);
  }
}

// implements the split
void split(int &splitCount, int i, intArray playerCards) {
  playerCards[splitCount + 1][0] = playerCards[i][2];
  playerCards[splitCount + 1][1] = playerCards[i][3];
}

// calculates the score of each hand
int calcScore(int Cards[], int Index) {
  int aceCount = 0;
  int score = 0;
  for(int i = 0; i <= Index; i += 2) {
    if((Cards[i] > 1) && (Cards[i] < 11)) {
      score += Cards[i];
    } else if((Cards[i] >= 11)) {
      score += 10;
    } else {
      score++;
      aceCount++;
    }
  }
  while(score < 12 && aceCount > 0) {
    score += 10;
    aceCount--;
  }
  return score;
}

// prints the whole hand upto the cards that have been drawn
void printHand(int Cards[], int Index) {
  for(int i = 0; i <= Index; i += 2) {
    printCard(Cards, i); cout << " ";
  }
}

// prints only one card at the specified index
void printCard(int Cards[], int cardNumber) {
  cout << Cards[cardNumber] << SUIT[Cards[cardNumber + 1]];
}

// draws a new card from the deck and makes that card on the deck -1
// which makes sure that the a card cannot be drawn twice
void drawCard(int deck[], int Cards[], int i) {
  bool drawn = true;
  int cardNumber = 0; int suitType = 1;
  while(drawn) {
    if(deck[cardNumber] != -1){
      Cards[i] = deck[cardNumber];
      Cards[i + 1] = deck[suitType];
      deck[cardNumber] = -1; deck[suitType] = -1;
      drawn = false;
    } else {
      cardNumber++; suitType++;
    }
  }
}

// creates a deck of playing cards
void createDeck(int deck[]) {
  for(int i = 0; i < 13; i += 1) {
    for(int j = 0; j < 7; j += 2) {
      deck[i * 8 + j] = i + 1;
    }
  }
  for(int i = 0; i < 4; i += 1) {
    for(int j = 1; j < 26; j += 2) {
      deck[i * 26 + j] = i;
    }
  }
}

// swaps each card with a random card to shuffle the deck
void shuffleDeck(int deck[]) {
  for(int i = 0; i < 104; i += 2) {
    int random = 2 * (rand() % 52);
    int temp = deck[i];
    deck[i] = deck[random];
    deck[random] = temp;
  }
  for(int i = 1; i < 104; i += 2) {
    int random = 2 * (rand() % 52) + 1;
    int temp = deck[i];
    deck[i] = deck[random];
    deck[random] = temp;
  }
}

// calculates net amount the player won or lost and prints the points of each hand
void result(int j, int &i, double& totalWin, double& amount, double &pay, int dealerScore, double amountWon[], int playerIndex[], int playerScore[]){
  amount -= pay; totalWin -= pay;
  if((playerIndex[j] == 2) && (playerScore[j] == 21)) {
    amountWon[j] = 1.5 * pay;
  } else if((dealerScore <= 21 && playerScore[j] < dealerScore) || playerScore[j] > 21) {
    amountWon[j] = 0;
  } else if(playerScore[j] == dealerScore) {
    amountWon[j] = pay;
  } else {
    amountWon[j] = 2 * pay;
  }
  amount += amountWon[j]; totalWin += amountWon[j];

  if(j == 0) {
    cout << playerScore[j] << " points";
  } else {
    if(j < i) {
    cout << ", ";
  } else {
    cout << ": and " << playerScore[j] << " points";
    }
  }
}
