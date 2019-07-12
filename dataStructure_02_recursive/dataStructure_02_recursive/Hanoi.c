#include <stdio.h>

void hanoiTower(int num, char from, char by, char to)
{
	if (num == 1)
	{
		printf("원반 1을 %c에서 %c로 이동시킴\n", from, to);
		return;
	}
	else
	{
		hanoiTower(num - 1, from, to, by);
		printf("원반 %d를 %c에서 %c로 이동시킴\n", num, from, to);
		hanoiTower(num - 1, by, from, to);
	}
}

void main()
{
	hanoiTower(4, 'A', 'B', 'C');
}