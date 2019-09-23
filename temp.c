#include <stdio.h>
#include <stdlib.h>

typedef struct Link {
	int elem;
	struct Link* next;
}link;

link* initLink() {
	link* head = (link*)malloc(sizeof(link));
	link* a = (link*)malloc(sizeof(link));
	link* b = (link*)malloc(sizeof(link));
	link* c = (link*)malloc(sizeof(link));

	head->next = a;

	a->elem = 1;
	a->next = b;
	
	b->elem = 2;
	b->next = c;

	c->elem = 3;
	c->next = NULL;
}

link* displayLink(link* head) {
	link* temp = (link*)malloc(sizeof(link));
	for(temp->next = head; temp->next != NULL; temp = temp->next) {
		printf("%d\n", temp->elem);
	}
}

void main() {}

//139 张洪铭
