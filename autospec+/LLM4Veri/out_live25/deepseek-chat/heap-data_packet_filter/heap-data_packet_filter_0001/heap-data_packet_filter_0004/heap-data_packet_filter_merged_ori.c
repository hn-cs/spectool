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
ensures \separated(\result.payload, (void*)0) ==> \valid_read(\result.payload);
ensures \result.size >= 0;
ensures \result.prio == LOW || \result.prio == HIGH;
*/
Packet receive() {
    Packet packet;
    packet.size = unknown();
    packet.prio = unknown() ? LOW : HIGH;
    packet.payload = unknown();
    return packet;
}
/*@
requires \valid(p.payload) ==> \valid_read(p.payload);
ensures \true;
assigns \nothing;
*/
void send(struct packet p) { (void)p; }
/*@
void append_to_queue(Packet p, Node *q) {;
requires \valid(q);
node- > packet = p;
node- > next = *q;
ensures *q == \old(\let n = malloc(sizeof(*n)); n- > packet == p && n- > next == \old(*q));
assigns *q;
Node node = malloc(sizeof(*node));
*q = node;
*/
void append_to_queue(Packet p, Node *q) {
    Node node = malloc(sizeof(*node));
    node->packet = p;
    node->next = *q;
    *q = node;
}
void process_prio_queue(Node q) {
    /*@
    loop invariant node- > packet.prio == HIGH || node- > packet.size < 500;
    loop invariant node == \null ==> \valid(node);
    loop invariant \valid(node);
    loop invariant \let n = node; n;
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
