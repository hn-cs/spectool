#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#define APPEND(l,i) {i->next=l; l=i;}
typedef struct node {
    struct node *next;
    int val;
} Node;
int main() {
    Node *l = NULL;
    int min = INT_MAX, max = -INT_MAX;
    /*@
    loop invariant \forall Node *p; \in_list(l, p) ==> min <= p->val && p->val <= max;
    loop invariant min <= max;
    loop invariant min == INT_MAX || \exists Node *p; \in_list(p, l) && p->val == min;
    loop invariant max == -INT_MAX || \exists Node *p; \in_list(p, l) && p->val == max;
    loop invariant min == INT_MAX || \exists Node *p; \in_list(l, p) && p- > val == min;
    loop invariant min <= max;
    loop invariant max == -INT_MAX || \exists Node *p; \in_list(l, p) && p- > val == max;
    loop invariant \valid_list(l);
    loop invariant \forall Node *p; \in_list(l, p) ==> min <= p->val && p->val <= max;
    loop assigns min;
    loop assigns max;
    loop assigns l;
    loop assigns \malloc_all;
    */
    while (unknown()) {
        Node *p = malloc(sizeof(*p));
        p->val = unknown();
        APPEND(l, p)
        if (min > p->val) {
            min = p->val;
        }
        if (max < p->val) {
            max = p->val;
        }
    }
    Node *i = l;
    /*@
    loop invariant \valid_list(l);
    loop invariant \valid(i);
    loop invariant \forall Node *p; \in_list(l, p) ==> min <= p->val && p->val <= max;
    loop assigns i;
    */
    while (i != NULL) {
        // @ assert !(i->val < min);
        // @ assert !(i->val > max);
        i = i->next;
    }
}
