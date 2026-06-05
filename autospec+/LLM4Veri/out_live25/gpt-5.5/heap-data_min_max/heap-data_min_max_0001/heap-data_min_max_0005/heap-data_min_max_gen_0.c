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
    loop invariant min == INT_MAX ==> l == \null;
    loop invariant min <= max ==> l != \null;
    loop invariant l != \null ==> \valid(&l->val);
    loop invariant l != \null ==> \valid(&l->next);
    loop invariant l == \null || max >= min;
    loop invariant l != \null ==> min != INT_MAX;
    loop invariant min <= INT_MAX;
    loop invariant max < INT_MAX;
    loop invariant l == \null || min <= max;
    loop invariant l == \null || \valid(l);
    loop invariant l == \null ==> min == INT_MAX;
    loop invariant l == \null ==> max == -INT_MAX;
    loop invariant l != \null ==> min < INT_MAX;
    loop invariant INT_MIN <= min;
    loop invariant -INT_MAX <= max;
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
    loop invariant min <= INT_MAX;
    loop invariant max < INT_MAX;
    loop invariant l == \null ==> i == \null;
    loop invariant l != \null ==> min <= max;
    loop invariant i == \null || min <= i- > val <= max;
    loop invariant i == \null || \valid(i);
    loop invariant i == \null || \valid(&i- > val);
    loop invariant i == \null || \valid(&i- > next);
    loop invariant i != \null ==> l != \null;
    loop invariant INT_MIN <= min;
    loop invariant -INT_MAX <= max;
    loop assigns i;
    */
    while (i != NULL) {
        // @ assert !(i->val < min);
        // @ assert !(i->val > max);
        i = i->next;
    }
}
