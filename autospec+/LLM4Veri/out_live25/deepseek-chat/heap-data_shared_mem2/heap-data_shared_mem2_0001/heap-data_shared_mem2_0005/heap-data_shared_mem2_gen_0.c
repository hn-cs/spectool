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
    m->val = 0;
    struct list_node *head = malloc(sizeof(*head));
    head->x = 1;
    head->mem = m;
    head->next = head;
    struct list_node *list = head;
    /*@
    loop invariant \exists struct list_node *n; \reach(list, head, next) == \true && n->x == x;
    loop invariant \forall struct list_node *n; n != \null && \reach(list, head, next) == \true ==> n->mem == m;
    loop invariant list->x > 0;
    loop invariant list->x < 10;
    loop invariant \valid(m);
    loop invariant \valid(list);
    loop invariant \reach(list, head, next);
    loop invariant \forall struct list_node *n; n != \null && \reach(list, head, next) == \true ==> \valid(n);
    loop invariant \forall struct list_node *n; \reach(list, head, next) == \true ==> n->mem == m;
    loop invariant next != \null < list-;
    loop invariant m->val >= 0 && m->val <= 100;
    loop invariant list->x > 0 && list->x < 10;
    loop invariant list- > mem == m;
    loop invariant \valid(list);
    loop invariant \reach(list, head, next) == \true;
    loop invariant \forall struct list_node *n; \reach(list, head, next) == \true ==> \valid(n) && n->mem == m;
    loop assigns list;
    loop assigns list->next;
    loop assigns head->next;
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
    loop invariant x < 100 - list-;
    loop invariant val <= 100;
    loop invariant val <= 100 - list-;
    loop invariant val < m-;
    loop invariant val < 100 - m-;
    loop invariant m->val < 100 ==> list->mem->val + list->x <= 100;
    loop invariant m- > val % list- > x == 0;
    loop invariant list->x > 0 && list->x < 10;
    loop invariant \valid(m);
    loop invariant \valid(list);
    loop invariant \reach(list, head, next) == \true;
    loop invariant \forall struct list_node *n; \reach(list, head, next) == \true ==> n->mem == m;
    loop invariant \forall struct list_node *n; \reach(list, head, next) == \true ==> \valid(n) && n->mem == m;
    loop invariant 0 <= m->val;
    loop invariant 0 <= m-;
    loop assigns m->val;
    loop assigns list;
    */
    while (m->val < 100) {
        if (list->mem->val + list->x <= 100)
            list->mem->val += list->x;
        list = list->next;
    }
    // @ assert(m->val == 100);
}
