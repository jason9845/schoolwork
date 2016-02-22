#include "Dragon.h"

Dragon::Dragon(Game* game, int player, int position): Animal(game,player,position){
	hp = MAX_HP;
	atk_damage = DEFAULT_ATK_DAMAGE;
	name = "Dragon";

}

Dragon::~Dragon() {

}

void Dragon::attack()
{
	enemies[pos]->defend(this, atk_damage);
	if(pos > 0) {
		enemies[pos-1]->defend(this, atk_damage);
	}
	if(pos < 4) {
		enemies[pos+1]->defend(this, atk_damage);
	}
}

void Dragon::defend(Animal* opponent, int damage) {
	takeDamage(0.8 * damage);
}

void Dragon::harass() {
  for (int i = 0; i < 5; i++) {
		enemies[i]->takeDamage(2);
	}
}
