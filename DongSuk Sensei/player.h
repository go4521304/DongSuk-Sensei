#pragma once
#include "globalhdr.h"
#include "Entity.h"

class Player : public Entity {
public:
	Player(string name, int hp, int str, int def) : Entity(name, hp, str, def)
	{
		cout << "플레이어 " << this->GetName() << "이(가) 만들어졌습니다." << endl;
	}

	void LookStat()
	{
		cout << this->GetName() << "의 정보" << endl;
		cout << "체력: " << this->GetHp() << endl;
		cout << "공격력: " << this->GetStr() << endl;
		cout << "방어력: " << this->GetDef() << endl;
	}

	bool Die()
	{
		cout << this->GetName() << "이(가) 사망했습니다..." << endl;
		return true;
	}
};