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
    loop invariant 10 <= tail->val <= 20;
    loop invariant list == tail ==> tail->val == 10;
    loop invariant list != tail ==> list->next != \null;
    loop invariant list->next == \null ==> tail == list;
    loop invariant list->next != \null ==> \valid(list->next);
    loop invariant list->next != \null ==> 10 <= list->next->val <= 20;
    loop invariant tail->next == \null;
    loop invariant \valid_read(tail) && \valid_read(list);
    loop invariant val <= 20;
    loop invariant val < tail-;
    loop invariant val < list-;
    loop invariant tail- > next == \null;
    loop invariant tail != \null;
    loop invariant list- > val == 10;
    loop invariant list != \null;
    loop invariant \valid(tail);
    loop invariant \valid(list);
    loop invariant 10 <= tail-;
    loop invariant 10 <= list-;
    loop assigns tail;
    loop assigns tail->next;
    loop assigns p;
    loop assigns \heap;
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
    loop invariant val <= 20;
    loop invariant val < tail-;
    loop invariant val < list-;
    loop invariant tail- > next == \null;
    loop invariant tail != \null;
    loop invariant list != \null;
    loop invariant \valid(tail);
    loop invariant \valid(list);
    loop invariant 10 <= tail-;
    loop invariant 10 <= list-;
    loop assigns p;
    loop assigns \heap;
    */
    while (1) {
        /*@
        loop invariant val <= 20;
        loop invariant val < list-;
        loop invariant p == \null || p- > next == \null || \valid(p- > next);
        loop invariant p == \null || p- > next == \null || (10 <= p- > next- > val <= 20);
        loop invariant p == \null || \valid(p);
        loop invariant p == \null || (10 <= p- > val <= 20);
        loop invariant \valid(list);
        loop invariant 10 <= list-;
        loop assigns p;
        loop assigns \heap;
        */
        for (p = list; p!= NULL; p = p->next) {
            // @ assert(p->val <= 20 && p->val >= 10);
            if (p->val < 20) p->val++;
            else p->val /= 2;
        }
    }
}
