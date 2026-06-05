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
    loop invariant next != \null < list-;
    loop invariant m- > val == 0;
    loop invariant m != \null;
    loop invariant list- > x == 1;
    loop invariant list- > next == head || (list- > next- > next == head && list- > next- > mem == m);
    loop invariant list- > next == head || (0 < list- > next- > x && list- > next- > x < 10);
    loop invariant list- > mem == m;
    loop invariant list == head;
    loop invariant head- > x == 1;
    loop invariant head- > next == head ||;
    loop invariant head- > mem- > val == 0;
    loop invariant head- > mem == m;
    loop invariant head != \null;
    loop invariant \valid(m);
    loop invariant \valid(list);
    loop invariant \valid(head);
    loop assigns head->next;
    head- > next- > next == head);
    head- > next- > mem == m &&;
    0 < head- > next- > x < 10 &&;
    (head- > next != \null &&;
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
    loop invariant x <= 9;
    loop invariant next) < \valid(list-;
    loop invariant mem) < \valid(list-;
    loop invariant list- > next == head || list- > next == head- > next;
    loop invariant head- > next == head || head- > next- > next == head;
    loop invariant head- > next == head || head- > next- > mem == m;
    loop invariant head- > next == head || \valid(head- > next);
    loop invariant head- > next == head || 1 <= head- > next- > x <= 9;
    loop invariant 1 <= list-;
    loop invariant x < next-;
    loop invariant x < list-;
    loop invariant x < 10;
    loop invariant val <= 100;
    loop invariant val < m-;
    loop invariant next- < list-;
    loop invariant next- < head-;
    loop invariant next != \null < list-;
    loop invariant next != \null < head-;
    loop invariant m != \null;
    loop invariant list- > next- > mem == m;
    loop invariant list- > mem == m;
    loop invariant list == head || list == head- > next;
    loop invariant list != \null;
    loop invariant head- > x == 1;
    loop invariant head- > next- > next == head;
    loop invariant head- > next- > mem == m;
    loop invariant head- > mem == m;
    loop invariant head != \null;
    loop invariant 0 <= m-;
    loop invariant 0 < list-;
    loop invariant 0 < head-;
    loop assigns m->val;
    loop assigns list;
    */
    while (m->val < 100) {
        if (list->mem->val + list->x <= 100)
            list->mem->val += list->x;
        list = list->next;
    }
    //@ assert(m->val == 100);
}
