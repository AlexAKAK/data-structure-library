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


dll_node * dll_get_node(dll_node * head, unsigned int index) {
    if (index > dll_len(head) - 1) return NULL;
    dll_node * temp = head;
    int i = 0;
    for (i; i < index; i++) {
        temp = temp->next;
    }
    return temp;
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

dll_node * dll_reverse(dll_node * head)
    // This is the standard procedure for reversing a normal linked list.
    {
        // Initialize current, previous and
        // next pointers
        dll_node * current = head;
        dll_node * prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        // assign the prev pointers

        


        return head;
    }