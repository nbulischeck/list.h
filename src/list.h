#ifndef LIST_H
#define LIST_H

/* Singly-linked Lists */

#define SL_EMPTY(head, empty) \
	empty = (head == NULL) ? 1 : 0;

#define SL_APPEND(head, entry) do { \
	if (head){ \
		__typeof__(head) _tmp = head; \
		while (_tmp->next != NULL){ _tmp = _tmp->next; } \
		_tmp->next = entry; \
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
	__typeof__(head) _p, _q, _e, _tail; \
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
	__typeof__(head) _cur = head, _prev = NULL, _next; \
	while (_cur) { \
		_next = _cur->next; \
		_cur->next = _prev; \
		_prev = _cur; \
		_cur = _next; \
	} \
	head = _prev; \
} while (0)

#define SL_LAST(head, node) do { \
	node = head; \
	while (node->next){ node = node->next; } \
} while (0)

#define SL_CONCAT(head1, head2) do { \
	if (head1){ \
		__typeof__(head1) _tmp = head1; \
		while (_tmp->next){ _tmp = _tmp->next; } \
		_tmp->next = head2; \
	} else { \
		head1 = head2; \
	} \
} while (0)

#define SL_LENGTH(head, length) do { \
	length = 0; \
	__typeof__(head) _cur = head; \
	while (_cur){ length++; _cur = _cur->next; } \
} while (0)

#define SL_FOREACH(head, node) \
	for(node = head; node; node = node->next)

#define SL_FOREACH_SAFE(head, node, tmp) \
	for (node = head, tmp = node->next; node; node = tmp, tmp = tmp == NULL ? NULL : tmp->next)

#define SL_INDEX(head, node, target) do { \
	int _i = target; \
	__typeof__(head) _cur = head; \
	while (_cur){ \
		if (!_i--) node = _cur; \
		_cur = _cur->next; \
	} \
} while (0)

#define SL_SEARCH(head, cmp, query, node) do { \
	__typeof__(head) _cur = head; \
	while (_cur){ \
		if (cmp(_cur, query) == 0) break; \
		_cur = _cur->next; \
	} \
	node = _cur; \
} while (0)

#define SL_DELETE(head, node) do { \
	__typeof__(head) _cur = head; \
	if (node == head){ \
		head = head->next; \
	} else { \
		while (_cur->next && _cur->next != node) \
			_cur = _cur->next; \
		_cur->next = node->next; \
	} \
} while (0)

/* Doubly-linked Lists */

#define DL_EMPTY SL_EMPTY

#define DL_APPEND(head, entry) do { \
	if (head) { \
		__typeof__(head) _tmp = head; \
		while (_tmp->next != NULL){ _tmp = _tmp->next; } \
		entry->prev = _tmp; \
		_tmp->next = entry; \
	} else { \
		head = entry; \
	} \
} while (0)

#define DL_PREPEND(head, entry) do { \
	if(head){ \
		entry->next = head; \
		head->prev = entry; \
	} \
	head = entry; \
} while (0)

#define DL_SORT SL_SORT

#define DL_REVERSE(head) do { \
	__typeof__(head) _temp; \
	while (head) { \
		_temp = head->prev; \
		head->prev = head->next; \
		head->next = _temp; \
		if (!head->prev) break; \
		head = head->prev; \
	} \
} while (0)

#define DL_LAST SL_LAST

#define DL_CONCAT SL_CONCAT

#define DL_LENGTH SL_LENGTH

#define DL_FOREACH SL_FOREACH

#define DL_FOREACH_SAFE SL_FOREACH_SAFE

#define DL_INDEX SL_INDEX

#define DL_SEARCH SL_SEARCH

#define DL_DELETE(head, node) do { \
    if (node->prev) \
        node->prev->next = node->next; \
    if (node->next) \
        node->next->prev = node->prev; \
} while (0)

#endif
