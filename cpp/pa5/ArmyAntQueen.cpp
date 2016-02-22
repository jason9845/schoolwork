#include "ArmyAntQueen.h"

ArmyAntQueen::ArmyAntQueen(Game* game, int player, int position): Animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "ArmyAntQueen";

}

ArmyAntQueen::~ArmyAntQueen() {

}

void ArmyAntQueen::attack()
{
}

void ArmyAntQueen::defend(Animal* opponent, int damage) {
	int ants = 0;
	for(int i = 0; i < 5; i++) {
		if(allies[i]->getName() == "ArmyAnt" && !(allies[i]->isDead())) {
			ants++;
		}
	}
	opponent->takeDamage(ants * 2);
}

void ArmyAntQueen::marchAndConquer() {
	for(int i = 0; i < 5; i++) {
		if(allies[i]->getName() == "ArmyAnt" && !allies[i]->isDead()) {
			allies[i]->marchAndConquerHEAL();
		}
	}
}
