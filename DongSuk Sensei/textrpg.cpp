#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

class Character {
private:
	string name_;
	int hp_;
	int str_;
	int def_;

public:
	Character()
	{
		name_ = "����";
		hp_ = -1;
		str_ = -1;
		def_ = -1;
	}

	Character(string name, int hp, int str, int def) : name_(name), hp_(hp), str_(str), def_(def)
	{
		;
	}

	// Getter
	string GetName() { return name_; }
	int GetHp() { return hp_; }
	int GetStr() { return str_; }
	int GetDef() { return def_; }

	// Setter
	void SetName(string newName) { name_ = newName; }
	void SetHp(int newHp) { hp_ = newHp; }
	void SetStr(int newStr) { str_ = newStr; }
	void SetDef(int newDef) { def_ = newDef; }

	/**********************************************************/
	void Attack(Character* target)
	{
		cout << this->name_ << "�� " << target->GetName() << "����" << this->str_ << "��ŭ�� �������� �־����ϴ�." << endl;

		target->Attacked(this);
	}

	void Attacked(Character* attacker)
	{
		this->hp_ -= attacker->GetStr();
	}
};

class Player : public Character {
public:
	Player(string name, int hp, int str, int def) : Character(name, hp, str, def)
	{
		cout << "�÷��̾� " << this->GetName() << "��(��) ����������ϴ�." << endl;
	}

	void LookStat()
	{
		cout << this->GetName() << "�� ����" << endl;
		cout << "ü��: " << this->GetHp() << endl;
		cout << "���ݷ�: " << this->GetStr() << endl;
		cout << "����: " << this->GetDef() << endl;
	}

	bool Die()
	{
		cout << this->GetName() << "��(��) ����߽��ϴ�..." << endl;
		return true;
	}
};

class Monster : public Character {
public:
	Monster(string name, int hp, int str, int def) : Character(name, hp, str, def)
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

void pressSpace()
{
	cout << "����ϱ�..." << endl;
	cin.ignore();
	cin.get();
}

int main()
{
	Player *player;
	Monster *monster[5];

	player = new Player("�׽�Ʈ1", 10, 10, 10);
	for (int i = 0; i < 5; ++i)
	{
		monster[i] = new Monster(to_string(i), i, i, i);
	}

	pressSpace();

	int currentMonster = 0;
	while (currentMonster < 5)
	{
		while (1)
		{
			system("cls");

			cout << "�޴�" << endl;
			cout << "1. ĳ���� ����" << endl;
			cout << "2. ���� ����" << endl;
			cout << "3. ����" << endl;
			cout << "4. ��������" << endl;

			int menu;
			cin >> menu;

			system("cls");
			if (menu == 1)
				player->LookStat();

			else if (menu == 2)
				monster[currentMonster]->LookStat();

			else if (menu == 3)
			{
				player->Attack(monster[currentMonster]);
				pressSpace();
				if (monster[currentMonster]->GetHp() <= 0)
				{
					monster[currentMonster]->Die();
					pressSpace();
					break;
				}

				monster[currentMonster]->Attack(player);
				pressSpace();
				if (player->GetHp() <= 0)
				{
					player->Die();
					pressSpace();
					break;
				}
			}

			else if (menu == 4)
			{
				cout << monster[currentMonster]->GetName() << "���Լ� �����ƽ��ϴ�!" << endl;
				pressSpace();
				break;
			}

			pressSpace();
		}
		currentMonster += 1;
	}
}