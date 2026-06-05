#include<limits.h>
/*@
assigns \nothing;
ensures INT_MIN <= \result < INT_MAX;
*/
int unknown();
#include <assert.h>
#include <stdlib.h>
#define LOW 0
#define HIGH 1
typedef struct packet {
    unsigned size;
    unsigned prio;
    char *payload;
} Packet;
typedef struct packet_list_node {
    struct packet packet;
    struct packet_list_node *next;
} *Node;
struct packet_queue {
    struct packet_list_node *front;
};
/*@
ensures \result.prio == LOW || \result.prio == HIGH;
assigns \nothing;
*/
Packet receive() {
    Packet packet;
    packet.size = unknown();
    packet.prio = unknown() ? LOW : HIGH;
    packet.payload = unknown();
    return packet;
}
/*@
assigns \nothing;
*/
void send(struct packet p) { (void)p; }
/*@
requires \valid(q);
ensures \valid(*q);
ensures (*q)- > packet.size == p.size;
ensures (*q)- > packet.prio == p.prio;
ensures (*q)- > packet.payload == p.payload;
ensures (*q)- > next == \old(*q);
assigns *q;
allocates *q;
*/
void append_to_queue(Packet p, Node *q) {
    Node node = malloc(sizeof(*node));
    node->packet = p;
    node->next = *q;
    *q = node;
}
/*@
predicate prio_queue(Node q) =
    q == \null ||
    (\valid(q) &&
     (q->packet.prio == HIGH || q->packet.size < 500) &&
     prio_queue(q->next));

requires prio_queue(q);
assigns \nothing;
*/
void process_prio_queue(Node q) {
    /*@
    loop invariant node == \null || node- > packet.prio == HIGH || node- > packet.size < 500;
    loop assigns node;
    */
    for (Node node = q; node != NULL; node = node->next) {
        // @ assert (node->packet.prio == HIGH || node->packet.size < 500);
        send(node->packet);
    }
}
void process_normal_queue(Node q) {
    for (Node node = q; node != NULL; node = node->next) {
        // @ assert (node->packet.prio == LOW && node->packet.size >= 500);
        send(node->packet);
    }
}
int main() {
    Node prio_queue = NULL;
    Node normal_queue = NULL;
    while (unknown()) {
        Packet new_packet = receive();
        if (new_packet.size > 0) {
            if (new_packet.prio == HIGH) {
                append_to_queue(new_packet, &prio_queue);
            } else if (new_packet.size < 500) {
                append_to_queue(new_packet, &prio_queue);
            } else {
                append_to_queue(new_packet, &normal_queue);
            }
        }
    }
    process_prio_queue(prio_queue);
    process_normal_queue(normal_queue);
    return 0;
}
