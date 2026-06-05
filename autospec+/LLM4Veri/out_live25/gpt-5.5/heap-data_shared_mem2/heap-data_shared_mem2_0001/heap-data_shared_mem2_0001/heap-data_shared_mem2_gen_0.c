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
    loop invariant m != \null;
    loop invariant head != \null;
    loop invariant list == head;
    loop invariant m->val == 0;
    loop invariant head->x == 1;
    loop invariant head->mem == m;
    loop invariant head->next == head || 
                   (head->next != \null &&
                    head->next->mem == m &&
                    0 < head->next->x < 10 &&
                    head->next->next == head);
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
    while (m->val < 100) {
        if (list->mem->val + list->x <= 100)
            list->mem->val += list->x;
        list = list->next;
    }
    // @ assert(m->val == 100);
}
