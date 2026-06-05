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
requires \valid(list);
ensures \separated(\result, list);
ensures \result- > next == *list;
ensures \result- > hash == hash;
ensures \result == \null;
ensures *list == \result;
disjoint behaviors;
complete behaviors;
behavior success:;
behavior failure:;
assumes \false;
assigns *list, \result;
*/
int hash_fun() { return unknown(); }
void append_to_list(struct node **list, int hash) {
    struct node *node = malloc(sizeof(*node));
    node->next = *list;
    node->hash = hash;
    *list = node;
}
int main() {
    struct node *list = NULL;
    int base = unknown();
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
