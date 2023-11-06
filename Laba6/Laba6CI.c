#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char newc(char c, int ind)
{
	ind = ind % 26;
	char nc = c - ind;
	if ('A' <= c && c <= 'Z')
	{
		if (nc - 'A' >= 0)
			return nc;
		else
			return 'Z' + nc - 'A' + 1;
	}
	else if ('a' <= c && c <= 'z')
	{
		if (nc - 'a' >= 0)
			return nc;
		else
			return 'z' + nc - 'a' + 1;
	}
	else
		return c;
}
int main()
{
	FILE* f;
	f = fopen("3test.txt", "r");

	int sost = 0;//0-поиск начала слова 1-работа с буквами слова 2-конец слова
	char c;
	int ind=0;
	int flag = 0;
	while (fscanf(f, "%c", &c) != EOF)
	{
		switch (sost)
		{
		case 0:
			switch (c)
			{
			case ' ':
			case '\n':
			case '\t':
				printf("%c", c);
				sost = 0;
				break;
			default:
				ind = ind + 1;
				sost = 1;
			}
		case 1:
			switch (c)
			{
			case ' ':
			case '\n':
			case '\t':
				printf("%c", c);
				sost = 0;
				break;
			default:
				c = newc(c, ind);
				printf("%c", c);
			}
		default:
			break;
		}
	}
	fclose(f);
}