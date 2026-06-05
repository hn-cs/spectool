#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
#define INTERVAL_SIZE 100
struct node {
    int hash;
    struct node *next;
};
/*@
ensures INT_MIN <= \result < INT_MAX;
assigns \nothing;
*/
int hash_fun() { return unknown(); }
/*@
requires \valid(list);
ensures \fresh(*list, sizeof(struct node));
ensures (*list)- > next == \old(*list);
ensures (*list)- > hash == hash;
assigns *list;
allocates *list;
*/
void append_to_list(struct node **list, int hash) {
    struct node *node = malloc(sizeof(*node));
    node->next = *list;
    node->hash = hash;
    *list = node;
}
int main() {
    struct node *list = NULL;
    int base = unknown();
    /*@
    loop invariant list == \null || (0 <= base <= 1000000);
    loop invariant base == \at(base,LoopEntry);
    loop invariant \forall struct node *p; \reachable(list, p) ==> p->hash >= base && p->hash < base + INTERVAL_SIZE;
    loop assigns list;
    loop assigns base;
    loop allocates \nothing;
    */
    while (unknown()) {
        if (base >= 0 && base <= 1000000) {
            base = base + 0;
            int hash = hash_fun();
            if (hash > base && hash < base + INTERVAL_SIZE)
                append_to_list(&list, hash);
        }
    }
    while (list) {
        // @ assert (list->hash >= base && list->hash < base + INTERVAL_SIZE);
        list = list->next;
    }
}
