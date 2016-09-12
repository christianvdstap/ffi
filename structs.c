#include <stdio.h>
#include <stdlib.h>
#include "structs.h"


struct child {
	char *name;
};

struct parent {
	char *name;
	struct child *child;
};


int simpleFunc(struct simple *param) {
	param->number = 42;
	return 0;
}

int simplePointerFunc(struct simple **param) {
	struct simple *s = (struct simple*) malloc(sizeof(struct simple));
	s->number = 24;
	*param = s;
	return 0;
}

int parentFunc(struct parent **p) {
	struct child *c = (struct child*) malloc(sizeof(struct child));
	c->name = "child";
	struct parent *p2 = (struct parent*) malloc(sizeof(struct parent));
	p2->name = "parent";
	p2->child = c;
	*p = p2;
	return 0;
}

int freeParentFunc(struct parent **p) {
	free((*p)->child);
	free(*p);
	*p = NULL;
	return 0;
}

struct element {
	void *data;
	struct element *next;
	struct element *prev;
};

struct list {
	struct element *head;
	struct element *tail;
	int size;
};

struct list *createList();
int freeList(struct list **l);

int appendElement(struct list *l, void *data);

int size(struct list *l);
struct element *head(struct list *l);
struct element *tail(struct list *l);
struct element *next(struct element *e);
struct element *prev(struct element *e);

int removeElement(struct list *l, struct element **e);
int removeHead(struct list *l);
int clear(struct list *l);

void dumpList(struct list *l);
void dumpElement(struct element *e);

struct list *createList() {
	struct list *l = (struct list*) malloc(sizeof(struct list));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

struct element *head(struct list *l) {
	return l->head;
}

struct element *tail(struct list *l) {
	return l->tail;
}

int size(struct list *l) {
	return l->size;
}

struct element *next(struct element *e) {
	return e->next;
}

struct element *prev(struct element *e) {
	return e->prev;
}

int removeElement(struct list *l, struct element **e) {
	if (e) {
		struct element *prev = (*e)->prev;
		struct element *next = (*e)->next;
		if (l->head == *e) {
			l->head = next;
		}
		if (l->tail == *e) {
			l->tail = prev;
		}
		if (prev) {
			prev->next = next;
		}
		if (next) {
			next->prev = prev;
		}
		l->size = l->size - 1;
		free(*e);
		*e = NULL;
	}
	return 0;
}

int removeHead(struct list *l) {
	struct element *head = l->head;
	if (head) {
		removeElement(l, &head);
	}
	return 0;
}

int clear(struct list *l) {
	struct element *next;
	next = head(l);
	while (next) {
		dumpList(l);
		removeHead(l);
		next = head(l);
	}
	return 0;
}

int freeList(struct list **l) {
	clear(*l);
	*l = NULL;
	return 0;
}

int appendElement(struct list *l, void *data) {
	struct element *newElement = (struct element*) malloc(sizeof(struct element));
	newElement->data = data;
	newElement->prev = NULL;
	newElement->next = NULL;
	
	l->size = l->size + 1;
	if (l->tail) {
		struct element *tail = l->tail;
		newElement->prev = tail;
		tail->next = newElement;
		l->tail = newElement;
	} else {
		l->head = newElement;
		l->tail = newElement;
	}
	return 0;
}

void dumpElement(struct element *e) {
	printf("(%p) next:%p - prev:%p - data:%p\n", (void*)e, (void*)e->next, (void*)e->prev, e->data); 
}

void dumpList(struct list *l) {
	printf("\n");
	printf("size: %i\n", l->size);
	struct element *next = l->head;
	int i = 0;
	while (next && i < 2) {
		dumpElement(next);
		next = next->next;
		i = i + 1;
	}
	printf("\n");
}

