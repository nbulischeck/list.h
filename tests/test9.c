//Append

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct node {
	int key;
	struct node *next;
} node_t;

node_t *head = NULL;

int cmp(node_t *a, int key){
	return a->key - key;
}

int main(){
	int i;
	node_t *item;
	for (i = 0; i < 10; i++){
		item = malloc(sizeof(node_t));
		item->key = i << 1;
		item->next = NULL;
		SL_APPEND(head, item);
	}
	SL_FOREACH(head, item) printf("%d\n", item->key);
	SL_SEARCH(head, cmp, 10, item);
	if (item != NULL){
		printf("Deleting %d from the list!\n", item->key);
		SL_DELETE(head, item);
		free(item);
	}
	SL_FOREACH(head, item) printf("%d\n", item->key);
	return 0;
}
