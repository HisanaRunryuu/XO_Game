// bitbucket + sourcetree
// c++ best ide



#include "stdafx.h"
#include <iostream> 
#include <cstring> 
using namespace std;

char win = '-'; //������ ������ ("-" - �����, "�" - ������� ������, "�" - �������)
char cells[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' }; // ������ � ������� � ������� ("-" - ������)

void show_cells();
void make_move(int num);
char check();
void result();

int main() {
	show_cells();

	for (int move = 1; move <= 9; move++) { //���� �� 9 �����, �.�. � ��� 9 ��������
		if (move % 2) make_move(1); //���� ��� ��������, �� ������� �� ������� �� ����� ����� 1 (�� ���� true) - ��� ������� ������. ����� - �������
		else make_move(2);
		show_cells();
		if (move >= 5) { //���� ����� ���� 5 ��� ������, �� �������� �������� �� ������ (������, ��� �� 5-�� ���� �������� ������)
			win = check(); //������ ������ - ��� ������������ �������� ������� ��������
			if (win != '-') //���� ������ ������ �� "-" (�� ���� ���-�� �������) - ���������� �����
				break;
		}
	}
	//���� ���������� � ����� �� ������� - �����
	result();
	system("pause");
	return 0;
}

void show_cells() { //����� ����
	system("cls");

	cout << "Numbers of cells:\n" << endl;
	//������ ������ ��� ����, ����� ������� ����, ���� ������
	cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-" << endl;
	cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-" << endl;
	cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-" << "\n" << endl;

	cout << "Current situation (--- is empty):\n" << endl;
	cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
	cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
	cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;
}


void make_move(int num) { // ���

	if (num == 1) cout << "First player";
	else cout << "Second player";
	cout << ", enter a cell's number to make move: ";
	int cell;
	cin >> cell;
	cout << "\n";
	while (cell > 9 || cell < 1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X') {
		//�������� (�������� �� ������ � �� ����� �� <1 � �� >9
		cout << "Enter a CORRECT (1-9) or EMPTY (---) cell's number to make move: ";
		cin >> cell; //���� �������� �� ��������, �� ����� ������ ��� ��� ������ ����� ��������
		cout << "\n";
	}

	if (num == 1) cells[cell - 1] = 'X'; //������ ����� ������ "����������", � ������ - "��������"
	else cells[cell - 1] = 'O';
}


char check() {
	for (int i = 0; i < 3; i++) //��� ������ ����� 3 ��������
		if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2]) // �� �����������
		{
			return cells[i]; break;
		}
		else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) // �� ���������
		{
			return cells[i]; break;
		}
		else if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8])) //�� ���������
		{
			return cells[i]; break;
		}
		else return '-'; //����� - �����
}

void result() {
	if (win == 'X') cout << "First player won! Congratulations!" << endl;
	else if (win == 'O') cout << "Second player won! Congratulations!" << endl;
	else cout << "Draw!" << endl;
}