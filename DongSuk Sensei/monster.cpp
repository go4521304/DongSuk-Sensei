#include "globalhdr.h"
#include "monster.h"

Monster::Monster(string name, int hp, int str, int def)
	: Entity(name, hp, str, def) { };