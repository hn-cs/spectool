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
    loop invariant head->next != \null;
    loop invariant \valid(head->next);
    loop invariant head->next->next == head;
    loop invariant head->next->mem == m;
    loop invariant head->next->mem->val == 100;
    loop invariant 1 <= head->next->x < 10;
    loop invariant head->mem->val == 100;
    loop invariant list == head;
    loop invariant head->mem == m;
    loop invariant x < next-;
    loop invariant x < 10;
    loop invariant next- < head-;
    loop invariant next) < \valid(head-;
    loop invariant next != \null < head-;
    loop invariant m- > val == 100;
    loop invariant m != \null;
    loop invariant list- > x == 1;
    loop invariant list- > next == head- > next;
    loop invariant list == head;
    loop invariant list != \null;
    loop invariant head- > x == 1;
    loop invariant head- > next- > next == head;
    loop invariant head- > next- > mem- > val == 100;
    loop invariant head- > next- > mem == m;
    loop invariant head- > next- > mem == head- > mem;
    loop invariant head- > mem == m;
    loop invariant head != \null;
    loop invariant \valid(m);
    loop invariant \valid(list);
    loop invariant \valid(head);
    loop invariant 1 <= head-;
    loop invariant 0 < head->next->x;
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
    loop invariant x < next-;
    loop invariant x < list-;
    loop invariant x < head-;
    loop invariant x < 10;
    loop invariant val < m-;
    loop invariant val < 110;
    loop invariant next- < list-;
    loop invariant next- < head-;
    loop invariant next) < \valid(head-;
    loop invariant next != \null < list-;
    loop invariant next != \null < head-;
    loop invariant mem) < \valid(list-;
    loop invariant m != \null;
    loop invariant list- > next- > next == list;
    loop invariant list- > next- > mem == m;
    loop invariant list- > mem == m;
    loop invariant list == head || list == head- > next;
    loop invariant list != \null;
    loop invariant head- > next- > next == head;
    loop invariant head- > next- > mem == m;
    loop invariant 90 < m-;
    loop invariant 1 <= list-;
    loop invariant 1 <= head-;
    loop assigns m->val;
    loop assigns list;
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
