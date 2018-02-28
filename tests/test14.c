//DL Prepend

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct node {
	int key;
	struct node *next;
	struct node *prev;
} node_t;

node_t *head = NULL;

int main(){
	int i;
	node_t *item;
	for (i = 0; i < 10; i++){
		item = malloc(sizeof(node_t));
		item->key = i << 1;
		item->next = NULL;
		item->prev = NULL;
		DL_PREPEND(head, item);
	}
	DL_FOREACH(head, item) printf("%d\n", item->key);
	printf("%d\n", head->next->next->prev->prev->key);
	return 0;
}
