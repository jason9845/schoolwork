#include <iostream>
#include <fstream>

#include "Game.h"
#include "Dog.h"

/*
 * Remember to include the header file of the animal classes here
 */

 #include "Cat.h"
 #include "Hawk.h"
 #include "Bat.h"
 #include "Turtle.h"
 #include "Shark.h"
 #include "ArmyAnt.h"
 #include "ArmyAntQueen.h"
 #include "Dragon.h"

using namespace std;

Game::Game(std::string file) {
	load(file);
}

Game::~Game() {
	for(int i = 0; i < 10; i++)
		delete animals[i/5][i%5];
}

/**
 * You should instantiate the animal objects here
 * Please refer to the example of "Dog"
 */
void Game::load(std::string file)
{
	ifstream in(file.c_str());
	int c = 0;
	int id;
	while(in >> id)
	{
		switch(id)
		{
		case DOG:
			animals[c/5][c%5] = new Dog(this, c/5, c%5);
			break;
		case CAT:
			animals[c/5][c%5] = new Cat(this, c/5, c%5);
			break;
		case HAWK:
			animals[c/5][c%5] = new Hawk(this, c/5, c%5);
			break;
		case BAT:
			animals[c/5][c%5] = new Bat(this, c/5, c%5);
			break;
		case TURTLE:
			animals[c/5][c%5] = new Turtle(this, c/5, c%5);
			break;
		case SHARK:
			animals[c/5][c%5] = new Shark(this, c/5, c%5);
			break;
		case ARMY_ANT:
			animals[c/5][c%5] = new ArmyAnt(this, c/5, c%5);
			break;
		case ARMY_ANT_QUEEN:
			animals[c/5][c%5] = new ArmyAntQueen(this, c/5, c%5);
			break;
		case DRAGON:
			animals[c/5][c%5] = new Dragon(this, c/5, c%5);
			break;
		}

		c++;
	}

}

/**
 * Do NOT modify this function
 */
bool Game::isEnd()
{
	int deadCount1 = 0;
	int deadCount2 = 0;
	for(int i = 0; i < 5; i++)
	{
		deadCount1 += animals[P1][i]->isDead();
		deadCount2 += animals[P2][i]->isDead();
	}

	if(deadCount1 == 5 && deadCount2 == 5)
	{
		cout << "Draws!" << endl;
	}else if (deadCount1 == 5)
	{
		cout << "Player " << P2+1 << " Wins!" << endl;
	} else if (deadCount2 == 5)
	{
		cout << "Player " << P1+1 << " Wins!" << endl;
	} else {
		return false;
	}
	return true;

}

void Game::start()
{
	Player currentPlayer = P1;
	int turnCount = 1;
	while(!isEnd())
	{
		for(int i = 0; i < 5; i++)
		{
			if(!animals[currentPlayer][i]->isDead())
				animals[currentPlayer][i]->attack();
		}

		/**
		 * To-Do 2: Codes for Special moves (if any) should be written here
		 * Hint: You should use dynamic binding, you may add data members/ functions in the Game class to help you implement this part
		 */
    if(flyingAnimals(currentPlayer) > 2) {
      for(int i = 0; i < 5; i++) {
        if(!animals[currentPlayer][i]->isDead()) {
          animals[currentPlayer][i]->harass();
        }
      }
    }

    if(swimmingAnimals(currentPlayer) > 2) {
      for(int i = 0; i < 5; i++) {
        if(!animals[currentPlayer][i]->isDead()) {
          animals[currentPlayer][i]->summonTsunami();
        }
      }
    }

    if(antAnimals(currentPlayer) == 5) {
      for(int i = 0; i < 5; i++) {
        if(!animals[currentPlayer][i]->isDead()) {
          animals[currentPlayer][i]->marchAndConquer();
        }
      }
    }

		//Output turn info
		cout << "Turn " << turnCount++ << " Player " << currentPlayer+1 << " attacks:" << endl;
		cout << "Player 1" << endl;
		for(int i = 0; i < 5; i++)
		{
			if(!animals[P1][i]->isDead())
				cout << animals[P1][i]->getName() << ":"
				<< animals[P1][i]->getCurrentHP() << " ";
			else
				cout << animals[P1][i]->getName() << ":"
				<< "DEAD" << " ";
		}
		cout << endl;
		cout << "Player 2" << endl;
		for(int i = 0; i < 5; i++)
		{
			if(!animals[P2][i]->isDead())
				cout << animals[P2][i]->getName() << ":"
				<< animals[P2][i]->getCurrentHP() << " ";
			else
				cout << animals[P2][i]->getName() << ":"
				<< "DEAD" << " ";
		}
		cout << endl;


		//Switch player turn
		if(currentPlayer == P1)
			currentPlayer = P2;
		else
			currentPlayer = P1;
	}
}

bool Game::isFlying(Animal* animal) {
  if(animal->getName() == "Hawk" || animal->getName() == "Bat" || animal->getName() == "Dragon") {
    return true;
  }
  return false;
}

bool Game::isSwimming(Animal* animal) {
  if(animal->getName() == "Turtle" || animal->getName() == "Shark") {
    return true;
  }
  return false;
}

bool Game::isAnt(Animal* animal) {
  if(animal->getName() == "ArmyAnt" || animal->getName() == "ArmyAntQueen") {
    return true;
  }
  return false;
}

int Game::flyingAnimals(int player) {
  int number = 0;
  for(int i = 0; i < 5; i++) {
    if(isFlying(animals[player][i]) && !animals[player][i]->isDead()) {
      number++;
    }
  }
  return number;
}

int Game::swimmingAnimals(int player) {
  int number = 0;
  for(int i = 0; i < 5; i++) {
    if(isSwimming(animals[player][i]) && !animals[player][i]->isDead()) {
      number++;
    }
  }
  return number;
}

int Game::antAnimals(int player) {
  int number = 0;
  for(int i = 0; i < 5; i++) {
    if(isAnt(animals[player][i])) {
      number++;
    }
  }
  return number;
}
