#ifndef _LIST_H_
#define _LIST_H_

/*
 * ----= SINGLY-LINKED LIST EXAMPLE =----
 *
 * typedef struct node {
 *		int key;
 *		struct node *next;
 * } node_t;
 * 
 * node_t *head = NULL;
 * 
 * int main(){
 *		node_t *item;
 *
 *		// Allocate and populate item //
 *
 *		// Append item to list //
 *		SL_APPEND(head, item);
 *
 *		// Print list values //
 *		SL_ITER(head, item){
 *			printf("%d\n", item->key);
 *		}
 *
 *		// Delete list //
 *		SL_ITER(head, item){
 *			SL_DELETE(head, item);
 *			free(item);
 *		}
 * }
 *
 * --------------------------------------
*/

#define SL_APPEND(head, entry) do { \
	if (head){ \
		typeof(head) tmp = head; \
		while (tmp->next != NULL){ tmp = tmp->next; } \
		tmp->next = entry; \
	} else { \
		head = entry; \
	} \
} while (0)

#define SL_PREPEND(head, entry) do { \
	if(head) entry->next = head; \
	head = entry; \
} while (0)

/* 
 * Sorting algorithm by Simon Tatham
 * https://www.chiark.greenend.org.uk/~sgtatham/algorithms/listsort.html
*/

#define SL_SORT(head, cmp) do { \
	typeof(head) _p, _q, _e, _tail; \
	int _insize, _nmerges, _psize, _qsize, _i; \
	if (head){ \
		_insize = 1; \
		while (1){ \
			_p = head; \
			head = NULL; \
			_tail = NULL; \
			_nmerges = 0; \
			while (_p){ \
				_nmerges++; \
				_q = _p; \
				_psize = 0; \
				for (_i = 0; _i < _insize; _i++){ \
					_psize++; \
					_q = _q->next; \
					if (!_q) break; \
				} \
				_qsize = _insize; \
				while (_psize > 0 || (_qsize > 0 && _q)){ \
					if (_psize == 0){ \
						_e = _q; _q = _q->next; _qsize--; \
					} else if (_qsize == 0 || !_q){ \
						_e = _p; _p = _p->next; _psize--; \
					} else if (cmp(_p, _q) <= 0){ \
						_e = _p; _p = _p->next; _psize--; \
					} else { \
						_e = _q; _q = _q->next; _qsize--; \
					} \
					if (_tail){ \
						_tail->next = _e; \
					} else { \
						head = _e; \
					} \
					_tail = _e; \
				} \
				_p = _q; \
			} \
			if (_tail) _tail->next = NULL; \
			if (_nmerges <= 1) break; \
			_insize *= 2; \
		} \
	} \
} while (0)

#define SL_REVERSE(head) do { \
	typeof(head) _cur = head, _prev = NULL, _next; \
	while (_cur) { \
		_next = _cur->next; \
		_cur->next = _prev; \
		_prev = _cur; \
		_cur = _next; \
	} \
	head = _prev; \
} while (0)

#define SL_CONCAT(head1, head2) do { \
	if (head1){ \
		typeof(head1) _tmp = head1; \
		while (_tmp->next){ _tmp = _tmp->next; } \
		_tmp->next = head2; \
	} else { \
		head1 = head2; \
	} \
} while(0)

#define SL_LENGTH(head, length) do { \
	length = 0; \
	typeof(head) _cur = head; \
	while (_cur){ length++; _cur = _cur->next; } \
} while(0)

#define SL_FOREACH(head, node) \
	for(node = head; node; node = node->next)

#define SL_INDEX(head, node, target) do { \
	int _i = target; \
	typeof(head) _cur = head; \
	while (_cur){ \
		if (!_i--) node = _cur; \
		_cur = _cur->next; \
	} \
} while(0)

#define SL_SEARCH(head, cmp, query, node) do { \
	typeof(head) _cur = head; \
	while (_cur){ \
		if (cmp(_cur, query) == 0) break; \
		_cur = _cur->next; \
	} \
	node = _cur; \
} while(0)

#define SL_DELETE(head, node) do { \
	typeof(head) cur = head; \
	if (node == head){ \
		head = head->next; \
	} else { \
		while (cur->next && cur->next != node) \
			cur = cur->next; \
		cur->next = node->next; \
	} \
} while (0)

#endif /* _LIST_H_ */
