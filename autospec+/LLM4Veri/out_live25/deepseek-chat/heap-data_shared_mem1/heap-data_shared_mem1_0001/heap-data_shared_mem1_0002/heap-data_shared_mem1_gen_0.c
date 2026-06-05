#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
struct mem {
    int val;
};
struct list_node {
    int x;
    struct mem *mem;
    struct list_node *next;
};
int main() {
    struct mem *m = malloc(sizeof(*m));
    m->val = 100;
    struct list_node *head = malloc(sizeof(*head));
    head->x = 1;
    head->mem = m;
    head->next = head;
    struct list_node *list = head;
    /*@
    loop invariant m- > val == 100;
    loop invariant list == head || \valid(list);
    loop invariant \valid(m);
    loop invariant \valid(list);
    loop invariant \valid(head);
    loop invariant 0;
    loop assigns m;
    loop assigns list;
    loop assigns head;
    loop assigns \nothing;
    */
    while (unknown()) {
        int x = unknown();
        if (x > 0 && x < 10) {
            struct list_node *n = malloc(sizeof(*n));
            n->x = x;
            n->mem = m;
            n->next = head;
            list->next = n;
        }
    }
    list = head;
    /*@
    loop invariant \valid(list) || list == \null;
    loop invariant \valid(m);
    loop invariant (list == \null) || (list->mem == m);
    loop invariant m->val >= 90 && m->val <= 110;
    loop assigns list;
    loop assigns m->val;
    */
    while (list) {
        if (list->mem->val <= 100)
            list->mem->val += list->x;
        else
            list->mem->val -= list->x;
        list = list->next;
        // @ assert(m->val > 90 && m->val < 110);
    }
}
