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

int dll_len(dll_node * head) {
    int index = 0;
    dll_node * temp = head;
    while (temp != NULL) {
        index++;
        temp = temp->next;
    }
    return index;

}

void dll_prepend(dll_node ** head_dp, void * value) {

    dll_node * newNode = (dll_node*) malloc(sizeof(dll_node)); // create the new node
    newNode->value = value;
    newNode->prev = NULL;
    // the new node points to head
    newNode->next = *head_dp;
    newNode->next->prev = newNode;
    *head_dp = newNode;

}


void dll_append(dll_node * head, void * value) {
    dll_node * np = make_dll_node(value);
    dll_node * tp = getTail(head);

    tp->next = np;
    np->prev = tp;

}

void dll_append_by_node(dll_node *head, dll_node *np) {
    dll_node * tp = getTail(head);
    tp->next = np;
    np->prev = tp;

}

void dll_print(dll_node * np, const char * format) {
    /*
    const char * format represents the type of data stored in each node as void * value
    */
    dll_node * temporary = np;
    while (temporary != NULL) {
        printf("%s\n", temporary->value);
        temporary = temporary->next;
    }
}

dll_node * dll_reverse(dll_node * head) {
    /*
    NULL - a - b - c - d - e - NULL
    NULL - e - d - c - b - a - NULL
    */





    dll_node * temp = getTail(head);
    dll_node * new_head = getTail(head);
    new_head->prev = NULL;
    new_head->next = NULL;
    temp->next = temp;
    unsigned int length = dll_len(head);
    while (temp != NULL) {
        dll_append_by_node(head, temp);
    }





}