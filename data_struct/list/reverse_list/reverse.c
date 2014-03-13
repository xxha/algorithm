#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int iData;
	struct node *next;
}LNode, *LinkList;


LinkList Link_insert(LinkList p, int num)
{
	LinkList temp = NULL;

	temp = (LinkList)malloc(sizeof(LNode));
	if (NULL == temp) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	temp->iData = num;
	temp->next = p;
	p = temp;

	return p;
}

void Link_print(LinkList temp)
{
	while (temp != NULL) {
		printf("%d\t", temp->iData);
		temp = temp->next;
	}

	printf("\n");
}

LinkList reverse_link(LinkList list)
{
	if (NULL == list
		|| NULL == list->next)
		return list;

	LinkList temp, prev, next;

	prev = list;
	temp = list->next;
	prev->next = NULL;

	while(temp != NULL) {
		next = temp->next;
		temp->next = prev;
		prev = temp;
		temp = next;
	}

	return prev;
}








int main(int argc, char **argv)
{
	LinkList head = NULL;
	int temp = 0;
	int i;

	for (i=0; i<10; i++) {
		printf("input number:");
		scanf("%d", &temp);
		head = Link_insert(head, temp);
		Link_print(head);
	}

	head = reverse_link(head);
	printf("After reverse: ---------------------------------------------------\n");
	Link_print(head);

	return 0;
}
