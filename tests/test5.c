//Concatenation

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct node {
	int key;
	struct node *next;
} node_t;

node_t *head1 = NULL, *head2 = NULL;

int main(){
	int i;
	node_t *item;
	for (i = 0; i < 10; i++){
		item = malloc(sizeof(node_t));
		item->key = i << 1;
		item->next = NULL;
		if (i < 5){
			SL_APPEND(head1, item);
		} else{
			SL_APPEND(head2, item);
		}
	}

	printf("List 1:\n");
	SL_FOREACH(head1, item) printf("%d\n", item->key);
	printf("List 2:\n");
	SL_FOREACH(head2, item) printf("%d\n", item->key);
	SL_CONCAT(head1, head2);
	printf("Combined:\n");
	SL_FOREACH(head1, item) printf("%d\n", item->key);
	return 0;
}
