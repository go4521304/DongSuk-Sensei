#pragma once
#include "globalhdr.h"

class Entity {
protected:
	string name_;
	int hp_;
	int str_;
	int def_;

public:
	Entity();
	Entity(string, int, int, int);

	// Setter
	void SetName(string);
	void SetHp(int);
	void SetStr(int);
	void SetDef(int);

	/**********************************************************/

};