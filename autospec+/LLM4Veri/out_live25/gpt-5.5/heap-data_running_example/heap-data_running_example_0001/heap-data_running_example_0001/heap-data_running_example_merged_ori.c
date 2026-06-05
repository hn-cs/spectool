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
    while (1) {
        for (p = list; p!= NULL; p = p->next) {
            // @ assert(p->val <= 20 && p->val >= 10);
            if (p->val < 20) p->val++;
            else p->val /= 2;
        }
    }
}
