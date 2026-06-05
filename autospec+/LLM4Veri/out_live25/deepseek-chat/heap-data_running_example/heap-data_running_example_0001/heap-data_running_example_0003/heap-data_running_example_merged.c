#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
typedef struct node {
    int val;
    struct node *next;
} Node;
int main() {
    Node *p, *list = malloc(sizeof(*list));
    Node *tail = list;
    list->next = NULL;
    list->val = 10;
    /*@
    loop invariant tail- > next == \null;
    loop invariant tail != \null;
    loop invariant list != \null;
    loop invariant \valid(list);
    loop invariant \forall Node *q; \valid(q) && \reachable(list, q) ==> q->val >= 10 && q->val <= 20;
    loop invariant \forall Node *q; \valid(q) && \reachable(list, q) && q != tail ==> q->next != \null;
    loop assigns tail;
    loop assigns tail->val;
    loop assigns tail->next;
    loop assigns p;
    loop assigns p->val;
    loop assigns p->next;
    loop assigns list->next;
    */
    while (unknown()) {
        int x = unknown();
        if (x < 10 || x > 20) continue;
        p = malloc(sizeof(*p));
        tail->next = p;
        p->next = NULL;
        p->val = x;
        tail = p;
    }
    /*@
    loop invariant \valid(list);
    loop invariant \reachable(list, p);
    loop invariant \forall Node *q; \valid(q) && \reachable(list, q) ==> q->val >= 5 && q->val <= 20;
    loop assigns p;
    loop assigns p->val;
    */
    while (1) {
        /*@
        loop invariant p == \null ==> 1;
        loop invariant \valid(p);
        loop invariant \reachable(list, p);
        loop invariant \forall Node *q; \valid(q) && \reachable(list, q) ==> q->val >= 5 && q->val <= 20;
        loop assigns p;
        loop assigns p->val;
        */
        for (p = list; p!= NULL; p = p->next) {
            //@ assert(p->val <= 20 && p->val >= 10);
            if (p->val < 20) p->val++;
            else p->val /= 2;
        }
    }
}
