#include <stdio.h>

void hanoiTower(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("���� 1�� %c���� %c�� �̵���Ŵ\n", from, to);
		return;
	}
	else
	{
		hanoiTower(num - 1, from, to, by);
		printf("���� %d�� %c���� %c�� �̵���Ŵ\n", num, from, to);
		hanoiTower(num - 1, by, from, to);
	}
}

void main()
{
	hanoiTower(4, 'A', 'B', 'C');
}