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
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event2 == 2 ==> p->event1 != 0);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event2 >= 2 ==> p->event1 != 0);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event2 == 3 ==> p->event1 >= 2);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event1 <= 1 ==> p->event2 <= 2);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event1 == 0 ==> p->event2 < 2);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event1 == 1 ==> p->event2 <= 2);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> !((p->event1 < 2) && (p->event2 == 3));
    loop invariant \forall Node *p; \reachable(l,p,next) ==> !((p->event1 == 0) && (p->event2 >= 2));
    loop invariant l == NULL || \valid(l);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> \valid(p);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> 0 <= p->event2 <= 3;
    loop invariant \forall Node *p; \reachable(l,p,next) ==> 0 <= p->event1 <= 3;
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event2 == 3 ==> p->event1 == 2 || p->event1 == 3);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event1 == 1 ==> p->event2 != 3);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> (p->event1 == 0 ==> p->event2 == 0 || p->event2 == 1);
    loop invariant \forall Node *p; \reachable(l,p,next) ==> !((p->event1 == 1) && (p->event2 == 3));
    loop invariant \forall Node *p; \reachable(l,p,next) ==> !((p->event1 == 0) && (p->event2 == 3));
    loop invariant \forall Node *p; \reachable(l,p,next) ==> !((p->event1 == 0) && (p->event2 == 2));
    loop assigns l;
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
    loop invariant i == NULL || \valid(i);
    loop invariant i == NULL || \reachable(l, i, next);
    loop invariant \forall Node *p; \reachable(i, p, next) ==> \valid(p);
    loop invariant \forall Node *p; \reachable(i, p, next) ==> 0 <= p->event2 <= 3;
    loop invariant \forall Node *p; \reachable(i, p, next) ==> 0 <= p->event1 <= 3;
    loop invariant \forall Node *p; \reachable(i, p, next) ==> (p->event2 == 3 ==> p->event1 == 2 || p->event1 == 3);
    loop invariant \forall Node *p; \reachable(i, p, next) ==> (p->event1 == 1 ==> p->event2 != 3);
    loop invariant \forall Node *p; \reachable(i, p, next) ==> (p->event1 == 0 ==> p->event2 == 0 || p->event2 == 1);
    loop invariant \forall Node *p; \reachable(i, p, next) ==> !((p->event1 == 1) && (p->event2 == 3));
    loop invariant \forall Node *p; \reachable(i, p, next) ==> !((p->event1 == 0) && (p->event2 == 3));
    loop invariant \forall Node *p; \reachable(i, p, next) ==> !((p->event1 == 0) && (p->event2 == 2));
    loop assigns i;
    */
    while (i != NULL) {
        // @ assert !((i->event1 == 1) && (i->event2 == 3)) || ((i->event1 == 0) && (i->event2 == 2));
        i = i->next;
    }
}
