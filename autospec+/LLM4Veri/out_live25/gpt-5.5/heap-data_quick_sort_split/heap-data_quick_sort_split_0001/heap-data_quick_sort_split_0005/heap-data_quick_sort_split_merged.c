#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
#define LOW -1
#define HIGH 1
struct node {
    int expected_list;
    int value;
    struct node *next;
};
/*@
requires \valid(list);
ensures \valid(*list);
ensures \fresh(*list, sizeof(struct node));
ensures (*list)- > value == val;
ensures (*list)- > next == \old(*list);
ensures (*list)- > expected_list == exp;
assigns *list;
allocates *list;
*/
void append_to_list(struct node **list, int val, int exp) {
    struct node *node = malloc(sizeof(*node));
    node->next = *list;
    node->value = val;
    node->expected_list = exp;
    *list = node;
}
/*@
ensures \result == \null || \valid(\result);
ensures \result != \null ==> (\result->expected_list == LOW || \result->expected_list == HIGH);
ensures \result != \null ==> ((\result->value < 0 ==> \result->expected_list == LOW) && (\result->value >= 0 ==> \result->expected_list == HIGH));
assigns \nothing;
*/
struct node *create_list() {
    struct node *list = NULL;
    /*@
    loop invariant list == \null || \valid(list);
    loop invariant list != \null ==> (list->expected_list == LOW || list->expected_list == HIGH);
    loop invariant list != \null ==> ((list->value < 0 ==> list->expected_list == LOW) && (list->value >= 0 ==> list->expected_list == HIGH));
    loop assigns list;
    */
    while (unknown()) {
        int v = unknown();
        if (v < 0)
            append_to_list(&list, v, LOW);
        else 
            append_to_list(&list, v, HIGH);
    }
    return list;
}
int main() {
    struct node *list = create_list();
    struct node *low = NULL;
    struct node *high = NULL;
    struct node *p = list;
    /*@
    loop invariant p == \null || \valid(p);
    loop invariant p != \null ==> (p->expected_list == LOW || p->expected_list == HIGH);
    loop invariant p != \null ==> ((p->value < 0 ==> p->expected_list == LOW) && (p->value >= 0 ==> p->expected_list == HIGH));
    loop invariant low == \null;
    loop invariant high == \null;
    loop assigns p;
    loop assigns p->next;
    */
    while (p) {
        struct node *l = p->value >= 0 ? high : low;
        struct node *next = p->next;
        p->next = l;
        l = p;
        p = next;
    }
    /*@
    loop invariant low == \null;
    loop assigns low;
    */
    while (low) {
        // @ assert(low->expected_list == LOW);
        low = low->next;
    }
    while (high) {
        // @ assert(high->expected_list == HIGH);
        high = high->next;
    }
}
