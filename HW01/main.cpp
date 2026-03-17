#include <iostream>
#include <vector>
using namespace std;



void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion = count;
	*p_MPPotion = count;
}

void addPotion(int count, int* Potion) {
	*Potion += count;
}

int main()
{
	vector<int> status(5, 0);
	int menu = -1;
	int HpPotion = 5, MpPotion = 5;
	int level = 1;


	while (1) {
		cout << "HP와 MP를 입력해주세요: ";
		cin >> status[0] >> status[1];
		if (cin.fail()) {
			cout << "숫자를 입력해주세요" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (status[0] <= 50 || status[1] <= 50) {
			cout << "HP나 MP값이 너무 작습니다. 다시 입력하세요" << endl;
		}
		else {
			break;
		}
	}

	while (1) {
		cout << "공격력과 방어력를 입력해주세요: ";
		cin >> status[2] >> status[3];

		if (cin.fail()) {
			cout << "숫자를 입력해주세요" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (status[2] <= 0 || status[3] <= 0) {
			cout << "공격력이나 방어력 값이 너무 작습니다.다시 입력하세요" << endl;
		}
		else {
			break;
		}
	}
	while (1) {
		cout << "속도를 입력해주세요: ";
		cin >> status[4];

		if (cin.fail()) {
			cout << "숫자를 입력해주세요" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else if (status[4] <= 0) {
			cout << "속도 값이 너무 작습니다.다시 입력하세요" << endl;
		}
		else {
			break;
		}
	}

	setPotion(5, &HpPotion, &MpPotion);
	cout << "포션이 지급되었습니다.(HP,MP 포션 각 5개)" << endl;
	cout << "=============================================" << endl;

	while (menu != 0) {
		cout << "1.HP UP / 2.MP UP / 3.공격력 UP / 4.방어력 UP / 5.속도 UP / 6.현재 능력치 / 7.Level Up / 0.나가기" << endl;
		cout << "번호를 선택해주세요 ";
		cin >> menu;
		if (menu == 0) {
			cout << "메뉴판에서 나갑니다." << endl;
			break;
		}
		switch (menu) {
		case 1: {
			if (HpPotion > 0) {
				status[0] += 20;
				--HpPotion;
				cout << "HP가 20 증가했습니다. HP 포션이 1개 차감됩니다." << endl;
				cout << "현재 HP : " << status[0] << endl;
				cout << "남은 HP 포션 : " << HpPotion;
				cout << endl;
			}
			else {
				cout << "남은 HP 포션이 없습니다." << endl;
				cout << endl;
			}
			break;
		}
		case 2: {
			if (MpPotion > 0) {
				status[1] += 20;
				--MpPotion;
				cout << "MP가 20 증가했습니다. MP 포션이 1개 차감됩니다." << endl;
				cout << "현재 MP : " << status[1] << endl;
				cout << "남은 MP 포션 : " << MpPotion;
				cout << endl;
			}
			else {
				cout << "남은 MP 포션이 없습니다." << endl;
				cout << endl;
			}
			break;
		}
		case 3: {
			cout << "공격력이 2배 증가했습니다." << endl;
			status[2] <<= 1;
			cout << "현재 공격력 : " << status[2] << endl;
			cout << endl;
			break;
		}
		case 4: {
			cout << "방어력이 2배 증가했습니다." << endl;
			status[3] <<= 1;
			cout << "현재 방어력 : " << status[3] << endl;
			cout << endl;
			break;
		}
		case 5: {
			cout << "속도가 2배 증가했습니다." << endl;
			status[4] <<= 1;
			cout << "현재 속도 : " << status[4] << endl;
			cout << endl;
			break;
		}
		case 6: {
			cout << "현재 능력치" << endl;
			cout << "HP\tMP\t공격력\t방어력\t속도\t레벨" << endl;
			for (int i : status) {
				cout << i << "\t";
			}
			cout << level << endl;

			cout << "남은 포션 개수" << endl;
			cout << "HP포션\tMP포션" << endl;
			cout << HpPotion << "\t" << MpPotion << "\t" << endl;

			cout << endl;
			break;
		}
		case 7: {
			++level;
			addPotion(1, &MpPotion);
			addPotion(1, &HpPotion);

			cout << "레벨이 1 증가했습니다." << endl;
			cout << "현재 레벨 : " << level << endl;

			cout << "Hp,Mp 포션이 1개씩 충전됩니다." << endl;
			cout << "현재 남은 포션" << endl;
			cout << "HP 포션 : " << HpPotion << endl;
			cout << "MP 포션 : " << MpPotion << endl;
			cout << endl;
			break;
		}
		default: {
			cout << "잘못된 입력입니다. 다시 입력하세요" << endl;
			cout << endl;
			break;
		}
		}
	}

	return 0;
}
