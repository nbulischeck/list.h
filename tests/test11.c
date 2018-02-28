//Empty

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct node {
	int key;
	struct node *next;
} node_t;

node_t *head = NULL;

int main(){
	int empty;
	node_t *item;

	item = malloc(sizeof(node_t));
	item->key = 1;
	item->next = NULL;
	SL_APPEND(head, item);

	SL_EMPTY(head, empty);
	printf("%d\n", empty);

	SL_DELETE(head, item);
	SL_EMPTY(head, empty);
	printf("%d\n", empty);

	return 0;
}
