#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
#define MAX_PROC 1000
struct process_node {
    int process_id;
    int time_to_wait;
    struct process_node *next;
};
/*@
assigns \nothing;
*/
void run_process(int id) { (void)id; }
/*@
requires \valid(q);
requires \valid(n);
requires \separated(n, q);
ensures n- > next == \old(*q);
ensures *q == n;
assigns n- > next, *q;
*/
void append_to_queue(struct process_node *n, struct process_node **q) {
    n->next = *q;
    *q = n;
}
/*@
inductive reachable{L}(struct process_node *from, struct process_node *p) {
  case reachable_head{L}: \forall struct process_node *from;
    from != \null ==> reachable(from, from);
  case reachable_next{L}: \forall struct process_node *from, *p;
    from != \null && \valid(from) && reachable(from->next, p) ==> reachable(from, p);
}

requires \valid(q);
requires *q != \null;
requires \forall struct process_node *p; reachable(*q, p) ==> \valid(p);
requires \forall struct process_node *p; reachable(*q, p) ==> p->time_to_wait >= 1;
requires \exists struct process_node *p; reachable(*q, p) && p->time_to_wait == 1;

ensures \result != \null;
ensures \valid(\result);
ensures reachable{Pre}(\old(*q), \result);
ensures \old(\result->time_to_wait) == 1;
ensures \forall struct process_node *p; reachable(*q, p) ==> \valid(p);
ensures \forall struct process_node *p; reachable(*q, p) ==> p->time_to_wait >= 1;

assigns \everything;
*/
struct process_node *choose_next(struct process_node **q) {
    struct process_node *node = *q;
    struct process_node *prev = NULL;
    struct process_node *result = NULL;
    /*@
    loop invariant result == \null || result- > time_to_wait == 1;
    loop invariant result == \null || \valid(result);
    loop invariant prev == \null || prev- > next == node;
    loop invariant prev == \null || \valid(prev);
    loop invariant node == \null || \valid(node);
    loop invariant \valid(q);
    loop assigns result;
    loop assigns prev;
    loop assigns node;
    loop assigns *q;
    */
    while (node != NULL) {
        if (node->time_to_wait == 1) {
            result = node;
            if (prev == NULL)
                *q = node->next;
            else
                prev->next = node->next;
        } else {
            node->time_to_wait--;
        }
        prev = node;
        node = node->next;
    }
    return result;
}
void check_queue(struct process_node *q) {
    for (struct process_node *n = q; n != NULL; n = n->next){
        // @ assert (n->time_to_wait >= 1);
    }
}
int main() {
    struct process_node *queue = NULL;
    int next_time = 1;
    while (unknown()) {
        if (next_time < MAX_PROC && unknown()) {
            int new_id = unknown();
            struct process_node *new_process = malloc(sizeof(*new_process));
            new_process->process_id = unknown();
            new_process->time_to_wait = next_time++;
            append_to_queue(new_process, &queue);
        } else if (next_time > 1){
            struct process_node *p = choose_next(&queue);
            next_time--;
            run_process(p->process_id);
        }
        check_queue(queue);
    } 
}
