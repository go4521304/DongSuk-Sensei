#pragma once
#include "globalhdr.h"
#include "Entity.h"

class Monster : public Entity {
public:
	Monster(string name, int hp, int str, int def) : Entity(name, hp, str, def)
	{
		cout << "���� " << this->GetName() << "��(��) ����������ϴ�." << endl;
	}

	void LookStat()
	{
		cout << "���� " << this->GetName() << endl;
		cout << "���� ü��: " << this->GetHp() << endl;
		cout << "���ݷ�: " << this->GetStr() << endl;
		cout << "����: " << this->GetDef() << endl;
	}
	bool Die()
	{
		cout << this->GetName() << "��(��) óġ�߽��ϴ�!" << endl;
		return false;
	}
};