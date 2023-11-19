#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//01000100000100000100010001 = 17842449
const int glasnie = 17842449;

int set_len(int a, int b)
{
	int c = a & b;
	int len = 0;
	while (c > 0)
	{
		len += c % 2;
		c /= 2;
	}
	return len;
}
int set_push_back(int *slovo, char c)
{
	int check = 0;
	if ('a' <= c && c <= 'z')
	{
		check |= (1 << (c - 'a'));
		if ((check & glasnie) & *slovo > 0)
		{
			*slovo = glasnie;
			return 0;
		}else
			*slovo |= (1 << (c - 'a'));
	}
	else if ('A' <= c && c <= 'Z')
	{
		check |= (1 << (c - 'A'));
		if ((check & glasnie) & *slovo > 0)
		{
			slovo = glasnie;
			return 0;
		}else
			*slovo |= (1 << (c - 'A'));
	}
	return 1;
}
int main()
{

	char c;
	int sost = 0;
	int slovo=0;
	scanf("%c", &c);
	while (1)
	{
		if (c == '\n' || c == '\t' || c == ' ' || c == '!')
		{
			if (sost == 1 && set_len(glasnie, slovo) == 1)
			{
				printf("YES");
				return 0;
			}
			if (c == '!')
			{
				printf("NO");
				return 0;
			}
			sost = 0;
		}
		else
		{
			if (sost == 0)
			{
				sost = 1;
				slovo = 0;
			}
			if (sost == 1)
			{
				set_push_back(&slovo, c);
			}

		}
		scanf("%c", &c);
	}
}