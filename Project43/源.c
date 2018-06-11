//   链表
#include <stdio.h>
typedef int item;
typedef struct node {
	item item;
	struct node * next;
}Node;
typedef Node * List; 
List insert(List root, item item);
List find(List root, item item);
List delet(List root, item item);
List CreatList();

int main(void)
{

}
List insert(List root, item item)
{
	List current = (List)malloc(sizeof(Node));
	current->item = item;
	current->next = root;
	root = current;
	return root;
}

List find(List root, item item)
{
	List it;
	for (it = root; it != NULL && it->item != item; it = it->next);
	return it;
}

List delet(List root, item item)
{
	List pre = NULL;
	List heart = root;
	if (!heart)
		return NULL;
	while (heart->next != NULL && heart->item != item)
	{
		pre = heart;
		heart = heart->next;
	}
	if (heart->item == item)  // 找到了
	{
		if (heart == root) // 是第一个
		{
			List temp = root;
			root = root->next;
			free(temp);
		}
		else
		{
			List temp = heart;
			pre->next = heart->next;
			free(temp);
		}
	}
	return root;
}

List CreatList()
{
	List current = NULL;
	return current;
}
