#include <stdlib.h>
#include <stdio.h>

struct dll_node_s {
    void * value;
    struct dll_node_s * prev;
    struct dll_node_s * next;
};

typedef struct dll_node_s dll_node;


dll_node * make_dll_node(void * value) {
    dll_node * np = (dll_node*)malloc(sizeof(dll_node));
    np->value = value;
    np->prev = NULL;
    np->next = NULL;

    return np;
}


dll_node * getTail(dll_node * np) {
    dll_node *temp = np;

    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;


}


void dll_add(dll_node * head, void * value) {
    dll_node * np = make_dll_node(value);
    dll_node * tp = getTail(head);

    tp->next = np;
    np->prev = tp;

}

void dll_print(dll_node * np) {
    dll_node * temporary = np;
    while (temporary != NULL) {
        printf("%s\n", temporary->value);
        temporary = temporary->next;
    }
}