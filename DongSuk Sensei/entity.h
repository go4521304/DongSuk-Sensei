#pragma once
#include "globalhdr.h"

class Entity {
protected:
	string m_name;
	int m_hp;
	int m_str;
	int m_def;

public:
	Entity();
	Entity(string, int, int, int);

	/**********************************************************/

};