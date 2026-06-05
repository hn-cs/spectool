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
    loop invariant l == \null || \valid(l);
    loop invariant \forall Node *p; \reachable(l, p) ==> \valid(p);
    loop invariant \forall Node *p; \reachable(l, p) ==> p->stock >= 0;
    loop invariant \forall Node *p; \reachable(l, p) ==> p->order == 0;
    loop assigns l;
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
