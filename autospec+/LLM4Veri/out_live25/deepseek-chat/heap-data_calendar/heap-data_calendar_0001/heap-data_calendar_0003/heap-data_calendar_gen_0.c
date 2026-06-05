#include<limits.h>
/*@ 
    assigns \result;
    ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
#define APPEND(l,i) {i->next=l; l=i;}
typedef struct node {
    struct node *next;
    int event1;
    int event2;
} Node;
int main() {
    Node *l = NULL;
    /*@
    loop invariant \forall Node *n; \valid(n) ==> (n->event1 >= 0 && n->event1 <= 3 && n->event2 >= 0 && n->event2 <= 3);
    loop invariant ev2 <= 3;
    loop invariant ev1 <= 3;
    loop invariant \forall Node *p; l == NULL || \exists Node *q; q- > next == p;
    loop invariant \forall Node *n; \valid(n);
    loop invariant 0 <= ev2;
    loop invariant 0 <= ev1;
    loop assigns p;
    loop assigns l;
    loop assigns i;
    */
    while (unknown()) {
        int ev1 = unknown();
        int ev2 = unknown();
        if (ev1 < 0 || ev1 > 3 || ev2 < 0 || ev2 > 3)
            continue;
        if (((ev1 == 0) && (ev2 == 2)) || ((ev1 == 1) && (ev2 == 3)) || ((ev1 == 0) && (ev2 == 3)))
            continue;
        Node *p = malloc(sizeof(*p));
        p->event1 = ev1;
        p->event2 = ev2;
        APPEND(l,p)
    }
    Node *i = l;
    /*@
    loop invariant event2 <= 3;
    loop invariant event2 < i-;
    loop invariant event1 <= 3;
    loop invariant event1 < i-;
    loop invariant \forall Node *n; n == i || n- > next == i || ...;
    loop invariant \forall Node *n; \valid(n);
    loop invariant \forall Node *n; \exists Node *m; m == i || m == i- > next || m == i- > next- > next || ...;
    loop invariant 0 <= i-;
    loop invariant !((i- > event1 == 1) && (i- > event2 == 3));
    loop invariant !((i- > event1 == 0) && (i- > event2 == 3));
    loop invariant !((i- > event1 == 0) && (i- > event2 == 2));
    loop assigns i;
    */
    while (i != NULL) {
        // @ assert !((i->event1 == 1) && (i->event2 == 3)) || ((i->event1 == 0) && (i->event2 == 2));
        i = i->next;
    }
}
