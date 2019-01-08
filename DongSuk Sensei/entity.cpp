#include "globalhdr.h"
#include "entity.h"

Entity::Entity()
{
	name_ = "¾øÀ½";
	hp_ = -1;
	str_ = -1;
	def_ = -1;
}
Entity::Entity(string name, int hp, int str, int def)
	: name_(name), hp_(hp), str_(str), def_(def) { };

void Entity::SetName(string newName) { name_ = newName; }
void Entity::SetHp(int newHp) { hp_ = newHp; }
void Entity::SetStr(int newStr) { str_ = newStr; }
void Entity::SetDef(int newDef) { def_ = newDef; }
