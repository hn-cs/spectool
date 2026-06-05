#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
#define APPEND(l,i) {i->next=l; l=i;}
typedef struct node {
    struct node *next;
    int stock;
    int order;
} Node;
int main() {
    Node *l = NULL;
    /*@
    loop invariant \valid(l) || l == \null;
    loop invariant \in_lseg(l, \null);
    loop invariant \forall Node *x; \valid(x) && \in_lseg(l, x) ==> x->stock >= 0 && x->order == 0;
    loop assigns l;
    loop assigns \nothing;
    */
    while (unknown()) {
        int stock = unknown();
        if (stock < 0)
            continue;
        Node *p = malloc(sizeof(*p));
        p->stock = stock;
        p->order = 0;
        APPEND(l,p)
    }
    Node *i = l;
    /*@
    loop invariant \in_lseg(l, \null);
    loop invariant \valid(i);
    loop invariant \in_lseg(i, \null);
    loop invariant \forall Node *x; \valid(x) && \in_lseg(l, x) ==> x->stock >= 0 && x->order >= 0;
    loop invariant \forall Node *x; \valid(x) && \in_lseg(l, i) && \in_lseg(i, x) || x == i ==> x->order <= x->stock;
    loop assigns i;
    loop assigns i->order;
    loop assigns i->stock;
    */
    while (i != NULL) {
        int order = unknown();
        if (order < 0 || i->stock < order)
            continue;
        i->order = order;
        i->stock = i->stock;
        i = i->next;
    }
    i = l;
    while (i != NULL) {
        // @ assert !(i->order > i->stock);
        i = i->next;
    }
}
