//Example

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct node {
    int key;
    struct node *next;
} node_t;

node_t *head = NULL;
 
int main(){
    node_t *item, *tmp;

    item = malloc(sizeof(node_t));
    item->key = 5;
    item->next = NULL;
    SL_APPEND(head, item);

    SL_FOREACH(head, item) printf("%d\n", item->key);

    SL_FOREACH_SAFE(head, item, tmp){
        SL_DELETE(head, item);
        free(item);
    }

    return 0;
}
