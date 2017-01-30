// Implementing Heap Data- structure with dynamic memory allocation

# include <stdio.h>
# include <stdlib.h>
# define maxxxx 10000 

typedef struct {
	node *l, *r, *p;
	int valu;
} node;

typedef struct {
	node *root, *lst_nd;
	int length;
} heap;

typedef struct {
	node *arr[maxxxx];
	int top, bottom;
} que;

node *pop(que *q) {
	int temp;
	if(top == bottom) {
		printf("queue empty");
		return;
	}
	temp = q -> arr[q -> bottom];
	(q -> bottom) += 1;
	return temp;
}

void push(que *q, int val) {
	if(top >= maxxxx) {
		printf("memory excedded");
		return;
	}
}

void max_heapify(node *nd) {
	node *tl, *tr;
	node *largest;
	tl = nd -> l;
	tr = nd -> r;
	
	if(tl != NULL && tl -> valu > nd -> valu) {
		largest = tl;
	}
	else
		largest = nd;
	if(tr != NULL && tr -> valu > largest -> valu) {
		largest = tr;
	}
	if(largest != nd) {
		temp = nd -> valu;
		nd -> valu = largest -> valu;
		largest -> valu = temp;
	}
}

heap* insert(heap *hp, int val, que *q) {
	hp -> length += 1;
	node *tmp;
	tmp = hp -> lst_nd;
	node *new;
	new = (node *)malloc(sizeof(node));
	new -> valu = INT_MIN;
	new -> l = NULL;
	new -> r = NULL;
	new -> p = tmp;

	if(tmp -> l == NULL) 
		tmp -> l = new;
	else if(tmp -> r == NULL)
		tmp -> r = new;
	else{
		tmp = pop(q);
		hp -> lst_nd = tmp;
		new -> p = tmp;	
		tmp -> l = new;
	}
	increase_val(node *new, int val);
}

void increase_val(node *new, int val ) {
	int temp;
	if(new -> valu > val)
		return;
	new -> valu = val;
	while(new -> p != NULL && (new -> p) -> valu < new -> valu) {
		temp = new -> valu;
		new -> valu = (new -> p) -> valu;
		new = new -> p;
	}
}

int main() {
	heap *hp;
	node *temp;
	int a, b, c, siz;
	scanf("%d", &siz);
	scanf("%d", &a);
	hp = (heap *)malloc(sizeof(heap));
	temp = (node *)malloc(sizeof(node));
	temp -> p = temp -> l = temp -> r = NULL;
	temp -> valu = a;
	hp -> root = temp;
	hp -> lst_nd = temp;
	hp -> length += 1;


	for(i = 1; i < siz; i++) {
		temp = (node *)malloc(sizeof(node));
		temp -> l = temp -> r = NULL;
		
		
	}

	return 0;
}