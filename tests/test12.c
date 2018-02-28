//Last Node

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

#define BUF_SIZE 32

typedef struct node {
	char key[BUF_SIZE];
	struct node *next;
} node_t;

node_t *head = NULL;

int cmp_sort(node_t *a, node_t *b){
	return strcmp(a->key, b->key);
}

int cmp_search(node_t *a, char *key){
	return strcmp(a->key, key);
}

int main(){
	node_t *strings, *tmp;
	int i = 0;
	char *buffer[] = {"OneString", "TwoString", 
						"RedString", "BlueString", NULL};

	while(buffer[i] != NULL){
		if ((strings = malloc(sizeof(node_t))) == NULL) exit(-1);
		strncpy(strings->key, buffer[i++], BUF_SIZE);
		strings->next = NULL;
		SL_APPEND(head, strings);
	}

	printf("Original List:\n");
	SL_FOREACH(head, tmp) printf("%s\n", tmp->key);
	SL_LAST(head, tmp);
	printf("Last Element: %s\n", tmp->key);
	SL_SORT(head, cmp_sort);
	printf("Sorted List:\n");
	SL_FOREACH(head, tmp) printf("%s\n", tmp->key);
	SL_LAST(head, tmp);
	printf("Last Element: %s\n", tmp->key);
	return 0;
}
