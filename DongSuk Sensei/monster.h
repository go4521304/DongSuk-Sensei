#pragma once
#include "globalhdr.h"
#include "Entity.h"

class Monster : public Entity {
public:
	Monster(string name, int hp, int str, int def) : Entity(name, hp, str, def)
	{
		cout << "몬스터 " << this->GetName() << "이(가) 만들어졌습니다." << endl;
	}

	void LookStat()
	{
		cout << "몬스터 " << this->GetName() << endl;
		cout << "남은 체력: " << this->GetHp() << endl;
		cout << "공격력: " << this->GetStr() << endl;
		cout << "방어력: " << this->GetDef() << endl;
	}
	bool Die()
	{
		cout << this->GetName() << "을(를) 처치했습니다!" << endl;
		return false;
	}
};