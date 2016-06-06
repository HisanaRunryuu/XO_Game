// bitbucket + sourcetree
// c++ best ide



#include "stdafx.h"
#include <iostream> 
#include <cstring> 
using namespace std;

char win = '-'; //—имвол победы ("-" - ничь€, "’" - первого игрока, "ќ" - второго)
char cells[9] = { '-', '-', '-', '-', '-', '-', '-', '-', '-' }; // массив с данными о клетках ("-" - пустой)

void show_cells();
void make_move(int num);
char check();
void result();

int main() {
	show_cells();

	for (int move = 1; move <= 9; move++) { //÷икл на 9 ходов, т.к. у нас 9 клеточек
		if (move % 2) make_move(1); //≈сли ход нечетный, то остаток от делени€ на будет равен 1 (то есть true) - ход первого игрока. »наче - второго
		else make_move(2);
		show_cells();
		if (move >= 5) { //≈сли номер хода 5 или больше, то проходит проверка на победу (раньше, чем на 5-ом ходе победить нельз€)
			win = check(); //—имвол победы - это возвращенное значение функции проверки
			if (win != '-') //≈сли символ победы не "-" (то есть кто-то победил) - прерывание цикла
				break;
		}
	}
	//÷икл закончилс€ и никто не победил - ничь€
	result();
	system("pause");
	return 0;
}

void show_cells() { //вывод пол€
	system("cls");

	cout << "Numbers of cells:\n" << endl;
	//Ќомера клеток дл€ того, чтобы человек знал, куда ходить
	cout << "-" << 1 << "-" << '|' << "-" << 2 << "-" << '|' << "-" << 3 << "-" << endl;
	cout << "-" << 4 << "-" << '|' << "-" << 5 << "-" << '|' << "-" << 6 << "-" << endl;
	cout << "-" << 7 << "-" << '|' << "-" << 8 << "-" << '|' << "-" << 9 << "-" << "\n" << endl;

	cout << "Current situation (--- is empty):\n" << endl;
	cout << "-" << cells[0] << "-" << '|' << "-" << cells[1] << "-" << '|' << "-" << cells[2] << "-" << endl;
	cout << "-" << cells[3] << "-" << '|' << "-" << cells[4] << "-" << '|' << "-" << cells[5] << "-" << endl;
	cout << "-" << cells[6] << "-" << '|' << "-" << cells[7] << "-" << '|' << "-" << cells[8] << "-" << "\n" << endl;
}


void make_move(int num) { // ход

	if (num == 1) cout << "First player";
	else cout << "Second player";
	cout << ", enter a cell's number to make move: ";
	int cell;
	cin >> cell;
	cout << "\n";
	while (cell > 9 || cell < 1 || cells[cell - 1] == 'O' || cells[cell - 1] == 'X') {
		//ѕроверка (клеточка не зан€та и ее номер не <1 и не >9
		cout << "Enter a CORRECT (1-9) or EMPTY (---) cell's number to make move: ";
		cin >> cell; //≈сли проверка не пройдена, то игрок должен еще раз ввести номер клеточки
		cout << "\n";
	}

	if (num == 1) cells[cell - 1] = 'X'; //ѕервый игрок играет "крестиками", а второй - "ноликами"
	else cells[cell - 1] = 'O';
}


char check() {
	for (int i = 0; i < 3; i++) //ƒл€ победы нужны 3 клеточки
		if (cells[i * 3] == cells[i * 3 + 1] && cells[i * 3 + 1] == cells[i * 3 + 2]) // по горизонтали
		{
			return cells[i]; break;
		}
		else if (cells[i] == cells[i + 3] && cells[i + 3] == cells[i + 6]) // по вертикали
		{
			return cells[i]; break;
		}
		else if ((cells[2] == cells[4] && cells[4] == cells[6]) || (cells[0] == cells[4] && cells[4] == cells[8])) //по диагонали
		{
			return cells[i]; break;
		}
		else return '-'; //иначе - ничь€
}

void result() {
	if (win == 'X') cout << "First player won! Congratulations!" << endl;
	else if (win == 'O') cout << "Second player won! Congratulations!" << endl;
	else cout << "Draw!" << endl;
}