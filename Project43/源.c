// 单词查找树： R向查找树
#include <stdio.h>
#define R 26
// 数据结构
typedef struct trieST{
	int val;
	struct trieST ** next;
}TrieST;
// API
TrieST * get(TrieST * root, char * key, int d);
TrieST * Creat(int r);
TrieST * put(TrieST * root, char * key, int val, int d);
int main(void)
{
	int val;
	TrieST * x, * text = NULL;
	char input[30];
	while (scanf("%d", &val) == 1)
	{
		getchar();
		gets(input);
		text = put(text, input, val, 0);
	}
	while (getchar() != '\n');
	gets(input);
	x = get(text, input, 0);
	if (x->val != -1)
		printf("%d\n", x->val);
	else
		printf("不存在\n");
}

TrieST * Creat(int r)
{
	TrieST * root = (TrieST *)malloc(sizeof(TrieST));
	root->val = -1;
	root->next = (TrieST **)malloc(sizeof(TrieST *) * r);
	for (int i = 0; i < r; i++)
		root->next[i] = NULL;
	return root;
}
TrieST * put(TrieST * root, char * key, int val, int d)
{
	if (!root)
		root = Creat(R);
	if (d == strlen(key))
		root->val = val;
	else
		root->next[key[d] - 'a'] = put(root->next[key[d] - 'a'], key, val, d + 1);
	return root;
}
TrieST * get(TrieST * root, char * key, int d)
{
	char c = key[d];
	if (!root)
		return NULL;
	if (d == strlen(key))
		return root;
	int n = c - 'a';
	get(root->next[n], key, d + 1);
}