# list.h

As of right now, there are only functions available for singly-linked lists.

## Functions Available

| Function Name | Arg 1 | Arg 2  | Arg 3 | Arg 4 |
| ------------- | ----- | ------ | ----- | ----- |
| SL_APPEND     | head  | node   |       |       |
| SL_PREPEND    | head  | node   |       |       |
| SL_SORT       | head  | fn *   |       |       |
| SL_REVERSE    | head  |        |       |       |
| SL_CONCAT     | head  | head   |       |       |
| SL_LENGTH     | head  | length |       |       |
| SL_FOREACH    | head  | node   |       |       |
| SL_INDEX      | head  | node   | index |       |
| SL_SEARCH     | head  | fn *   | query | node  |
| SL_DELETE     | head  | node   |       |       |


### SL_APPEND

This function appends a node to the end of a linked list.

Argument 1: The head node of the list

Argument 2: The node to be appended to the list

Call:
```C
SL_APPEND(head, node);
```

### SL_PREPEND

This function prepends a node to the end of a linked list.

Argument 1: The head node of the list

Argument 2: The node to be prepended to the list

Call:
```C
SL_APPEND(head, node);
```

### SL_SORT

This function sorts a linked list in O(n log n) time.

Argument 1: The head node of the list

Argument 2: A function pointer to a compare function

Call:
```C
SL_SORT(head, fn *);
```

>**Note**: The function pointer must be able to identify if one key is less than or equal to another and return a value accordingly. The check to swap is if the return value of the compare function is less than or equal to zero. For strings, you can use `strcmp()` and for integers you can simply return the difference.

### SL_REVERSE

This function reverses a linked list. For example, `a->b->c->d` becomes `d->c->b->a`.

Argument 1: The head node of the list

Call:
```C
SL_REVERSE(head);
```

### SL_CONCAT

This function concatenates two linked lists. For example, list1: `a->b` and list2: `c->d` becomes `a->b->c->d`.

Argument 1: The head node of the first list

Argument 2: The head node of the second list

Call:
```C
SL_CONCAT(head, head);
```

### SL_LENGTH

This function stores the length of a linked list in the second argument.

Argument 1: The head node of the list

Argument 2: An integer to store the length of the list

Call:
```C
SL_LENGTH(head, length);
```

>**Note**: The second argument **will** be clobbered!

### SL_FOREACH

This function iterates over the length of the list and returns the node at each step. This is helpful when operating on every node in the list (printing the list, altering each node, or destroying the list).

Argument 1: The head node of the list

Argument 2: A temporary node to store each intermediary node

Call:
```C
SL_FOREACH(head, node);
```

### SL_INDEX

This function returns a node at the nth position in the list. The list is zero-indexed, so if you ask for the 0th node, you'll get the head.

Argument 1: The head node of the list

Argument 2: A temporary node to store the returned node

Argument 3: An integer index value

Call:
```C
SL_INDEX(head, node, index);
```

>**Note**: Check for a proper return value after a function call to SL_INDEX. If your index is out of range, a NULL node will be returned.


### SL_SEARCH

This function searches the list and compares each node to the query using the function pointer argument. If a valid match is found, the matching node is placed in the fourth argument `node`. This is one of the most versatile functions due to the nature of the function pointer. You're given the ability to search for nodes, keys (int, char *, ...), etc. The limit to which you can search the list is your ability to write a proper compare function.

Argument 1: The head node of the list

Argument 2: A function pointer to a compare function

Argument 3: The item you want to query

Argument 4: A temporary node to store the returned node

Call:
```C
SL_SEARCH(head, cmp, query, node);
```

>**Note**: Check for a proper return value after a function call to SL_SEARCH. If a node is not found, a NULL node will be returned.

### SL_DELETE

This function removes a node from the linked list. **SL_DELETE only unlinks the node!** The memory **must** be freed to avoid a memory leak.

Argument 1: The head node of the list

Argument 2: The node to be removed

Call:
```C
SL_DELETE(head, node);
```
