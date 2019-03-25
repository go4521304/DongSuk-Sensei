#include "globalhdr.h"
#include "entity.h"

Entity::Entity()
{
	m_name = "¾øÀ½";
	m_hp = -1;
	m_str = -1;
	m_def = -1;
}
Entity::Entity(string name, int hp, int str, int def)
	: m_name(name), m_hp(hp), m_str(str), m_def(def) { };