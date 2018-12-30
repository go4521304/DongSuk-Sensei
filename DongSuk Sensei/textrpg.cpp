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
		name_ = "없음";
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
		cout << this->name_ << "가 " << target->GetName() << "에게" << this->str_ << "만큼의 데미지를 주었습니다." << endl;

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

class Monster : public Character {
public:
	Monster(string name, int hp, int str, int def) : Character(name, hp, str, def)
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

void pressSpace()
{
	cout << "계속하기..." << endl;
	cin.ignore();
	cin.get();
}

int main()
{
	Player *player;
	Monster *monster[5];

	player = new Player("테스트1", 10, 10, 10);
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

			cout << "메뉴" << endl;
			cout << "1. 캐릭터 정보" << endl;
			cout << "2. 몬스터 정보" << endl;
			cout << "3. 공격" << endl;
			cout << "4. 도망가기" << endl;

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
				cout << monster[currentMonster]->GetName() << "에게서 도망쳤습니다!" << endl;
				pressSpace();
				break;
			}

			pressSpace();
		}
		currentMonster += 1;
	}
}