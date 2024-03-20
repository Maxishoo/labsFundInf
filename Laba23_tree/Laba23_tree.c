#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct level
{
	int value;
	int kol_v;
	struct level* next;
};
struct node {
	int value;
	struct node* child;
	struct node* brother; // right brother
	struct level* level;
};
void info()
{
	printf("\nINFO:\n");
	printf("? - print info. To use - enter <?>\n");///
	printf("q - exit programm. To use - enter <?>\n");//
	printf("+ - add new nod. To use - enter vertex as <parent> <child>. If there is none root, parent is -1\n");///
	printf("- - delete nod. To use - enter vertex as <vertex>\n");//
	printf("p - print tree. To use - enter <p>\n");
	printf("f - calculate function from tree. To use - enter <f> P.S. (levels starts from 0. Root`s level = 0\n");
}
struct node* find(struct node* cur, int val)
{
	if (cur == NULL)
		return NULL;
	if (cur->value == val)
		return cur;

	struct node* rez = find(cur->child, val);
	if (rez != NULL)
		return rez;
	else
		return find(cur->brother, val);
}
struct node* add(struct node* cur, int par,int ch)
{
	if (cur == NULL)
	{
		struct node* el = malloc(sizeof(struct node));
		struct level* l = malloc(sizeof(struct level));
		l->value = 0;
		l->kol_v = 1;
		l->next = NULL;

		el->value = ch;
		el->child = NULL;
		el->brother = NULL;
		el->level = l;
		return el;
	}
	struct node* parent = find(cur, par);
	if (parent->child == NULL)
	{
		struct node* el = malloc(sizeof(struct node));
		el->value = ch;
		el->child = NULL;
		el->brother = NULL;
		struct level* pr_level = parent->level;
		if (pr_level->next == NULL)
		{
			struct level* l = malloc(sizeof(struct level));
			l->value = pr_level->value + 1;
			l->kol_v = 0;
			l->next = NULL;
			pr_level->next = l;
		}
		(pr_level->next)->kol_v += 1;
		el->level = pr_level->next;
		parent->child = el;
		return cur;
	}
	struct node* new_child_pos = parent->child;
	while (new_child_pos->brother != NULL)
	{
		new_child_pos = new_child_pos->brother;
	}
	struct node* el = malloc(sizeof(struct node));
	(new_child_pos->level)->kol_v += 1;
	el->value = ch;
	el->child = NULL;
	el->brother = NULL;
	el->level = new_child_pos->level;
	new_child_pos->brother = el;
	return cur;
	
}
void printer(struct node* cur, int level) {
	if (cur == NULL)
		return;
	for (int i = 0; i < level; ++i)
		printf("- ");

	printf("%d\n", cur->value);

	printer(cur->child, level + 1);
	printer(cur->brother, level);
}
struct node* del_find(struct node* cur, int val)
{
	if (cur == NULL)
		return NULL;
	struct node* c_b = cur->brother;
	struct node* c_ch = cur->child;
	if ((c_b != NULL && c_b->value == val) || (c_ch != NULL && c_ch->value == val))
		return cur;

	struct node* rez = del_find(cur->child, val);
	if (rez != NULL)
		return rez;
	else
		return del_find(cur->brother, val);
}
struct node* del(struct node* cur, struct level* prev_level)
{
	if (cur == NULL)
		return NULL;
	if (cur->child == NULL && cur->brother == NULL)
	{
		(cur->level)->kol_v -= 1;
		if ((cur->level)->kol_v == 0)
		{
			prev_level->next = NULL;
			free(cur->level);
		}

		free(cur);
		return NULL;
	}
	else if (cur->child == NULL)
	{
		struct node* new_cur = cur->brother;

		(cur->level)->kol_v -= 1;
		if ((cur->level)->kol_v == 0)
		{
			prev_level->next = NULL;
			free(cur->level);
		}

		free(cur);
		del(new_cur, prev_level);
		return new_cur;
	}
	else if (cur->brother == NULL)
	{
		struct node* new_cur = cur->child;
		del(new_cur, cur->level);
		(cur->level)->kol_v -= 1;
		if ((cur->level)->kol_v == 0)
		{
			prev_level->next = NULL;
			free(cur->level);
		}

		free(cur);
		return new_cur;
	}
	else
	{
		cur->brother = del(cur->brother, prev_level);
		cur->child = del(cur->child, cur->level);

		(cur->level)->kol_v -= 1;
		if ((cur->level)->kol_v == 0)
		{
			prev_level->next = NULL;
			free(cur->level);
		}

		free(cur);
		return cur;
	}
}
struct node* rm(struct node* cur, int val)
{
	if (cur->value == val)
	{
		struct node* swaper = cur->child;
		struct level* c_l = cur->level;
		del(swaper, cur->level);
		free(cur);
		free(c_l);
		return NULL;
	}
	struct node* prev = del_find(cur, val);
	struct node* p_ch = prev->child;
	struct node* p_b = prev->brother;
	if (p_ch != NULL && p_ch->value == val)
	{
		struct node* prev_child = prev->child;
		struct node* swaper = prev_child->brother;
		(p_ch->level)->kol_v -= 1;
		if ((p_ch->level)->kol_v == 0)
		{
			(prev->level)->next = NULL;
			free(p_ch->level);
		}
		del(p_ch->child, p_ch->level);
		free(prev->child);
		prev->child = swaper;
		return cur;
	}
	else if (p_b != NULL && p_b->value == val)
	{
		struct node* prev_bro = prev->brother;
		struct node* swaper = prev_bro->brother;

		(p_b->level)->kol_v -= 1;

		del(prev_bro->child, prev->level);
		free(prev->brother);
		prev->brother = swaper;
		return cur;
	}
}
void function(struct node * header)
{
	if (header == NULL)
	{
		"There is no vertex in the tree\n";
		return;
	}
	int max_v = 0, max_l = 0;
	struct level* cur_l = header->level;
	while (cur_l != NULL)
	{
		//printf("%d ", cur_l->kol_v);
		if (cur_l->kol_v > max_v)
		{
			max_v = cur_l->kol_v;
			max_l = cur_l->value;
		}
		cur_l = cur_l->next;
	}
	printf("Level with max count of vertex is - %d\n", max_l);
}
int main()
{
	struct node* header = NULL;
	struct node* try_find = NULL;

	char fl;
	int par, ch;
	scanf("%c", &fl);
	while (fl != 'q')
	{
		switch (fl)
		{
		case '+':
			scanf("%d %d", &par, &ch);
			try_find = find(header, par);
			if ((par == -1 && header == NULL) || try_find != NULL)
			{
				try_find = find(header, ch);
				if (try_find == NULL)
				{
					header = add(header, par, ch);
					printf("%d added\n", ch);
				}
				else
					printf("%d is already in the tree\n", ch);
			}
			else if (par == -1)
				printf("You can add only one root\n");
			else
				printf("%d not in tree\n", par);
			break;
		case '-':
			scanf("%d", &ch);

			try_find = find(header, ch);
			if (try_find != NULL)
			{
				header = rm(header, ch);
				printf("%d deleted\n", ch);
			}else
				printf("%d is not in tree\n", ch);
			break;
		case 'f':
			function(header);
			break;
		case 'p':
			printer(header, 0);
			break;
		case '?':
			info();
			break;
		case 'q':
			printf("Quit.\n");
			return 0;
		default:
			break;
		}
		scanf("%c", &fl);
	}
}