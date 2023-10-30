#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct circle circle;
typedef struct dot dot;
struct dot
{
	int x;
	int y;
};
struct circle
{
	int x0;
	int y0;
	int r;
};
int min(int a, int b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
int sign(int a)
{
	if (a >= 0)
		return 1;
	else
		return 0;
}
int check_circle(circle c, dot p)
{
	if ((p.x - c.x0) * (p.x - c.x0) + (p.y - c.y0) * (p.y - c.y0 <= c.r * c.r))
		return 1;
	else
		return 0;
}
int main()
{
	dot point = { 26, 8 };
	dot old_point = { 26, 8 };
	int l = -3;
	struct circle vnutr = { 10, 10, 5 };
	struct circle vnesh = { 10, 10, 10 };

	for (int i = 1; i <= 50; i++)
	{
		point.x = (min(old_point.x + old_point.y, old_point.x + l) * (i + l)) % 30;
		point.x = old_point.y + (l * sign(old_point.y)) % 20 + (i * sign(old_point.x)) % 10;
		l = (max(max(old_point.x * old_point.y, old_point.x * l), old_point.y * l)) % 30;
		printf("x: %d y: %d\n", point.x, point.y);
		if ((point.x - vnesh.x0) * (point.x - vnesh.x0) + (point.y - vnesh.y0) * (point.y - vnesh.y0) <= vnesh.r * vnesh.r)
		{
			if ((point.x - vnutr.x0) * (point.x - vnutr.x0) + (point.y - vnutr.y0) * (point.y - vnutr.y0) >= vnutr.r * vnutr.r)
			{
				printf("Succes: x: %d y: %d\n", point.x, point.y);
				break;
			}
		}
		old_point.x = point.x;
		old_point.y = point.y;
	}
}