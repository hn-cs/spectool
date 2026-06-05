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
    loop invariant \valid_list(l);
    loop invariant min <= max;
    loop invariant min == INT_MAX || \exists Node *p; \in_list(l, p) && p->val == min;
    loop invariant max == -INT_MAX || \exists Node *p; \in_list(l, p) && p->val == max;
    loop invariant \forall Node *p; \in_list(l, p) ==> min <= p->val && p->val <= max;
    loop assigns l, min, max, \malloc_all;
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
    while (i != NULL) {
        // @ assert !(i->val < min);
        // @ assert !(i->val > max);
        i = i->next;
    }
}
