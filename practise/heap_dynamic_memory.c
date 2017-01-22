// Implementing Heap Data- structure with dynamic memory allocation

# include <stdio.h>
# include <stdlib.h>

typedef struct {
	node *l, *r, *p;
	int valu;
} node;

typedef struct {
	node *root, *lst_nd;
	int ocp;
	int length;
} heap;

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
		new -> p = tmp;	
		tmp -> l = new;
	}
	increase_val(node *new, int val);
}

int main() {
	

	return 0;
}