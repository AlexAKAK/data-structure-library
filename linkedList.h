#include <stdlib.h>
#include <stdio.h>

struct node {
    char * value;
    struct node * next;
};

typedef struct node node_t;


node_t * makeLinkedList(char * value) {
    node_t * newNode = (node_t*)malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}


void printLinkedList(node_t * head) {
    node_t * temporary = head;
    while (temporary != NULL) {
        printf("%s\n", temporary->value);
        temporary = temporary->next;
    }
}

int len(node_t * head) {
    int index = 0;
    node_t * temp = head;
    while (temp != NULL) {
        index++;
        temp = temp->next;
    }
    return index;

}

node_t * getLastNodePointer(node_t * head) {
    node_t * temp = head;
    node_t * tempPrev = NULL;
    while (temp != NULL) {
        tempPrev = temp;
        temp = temp->next;
    }
    return tempPrev;
}

void append(node_t * head, char * value) {
    node_t * newNode = (node_t*) malloc(sizeof(node_t));
    newNode->value = value;
    newNode->next = NULL;
    getLastNodePointer(head)->next = newNode;
}

void append_by_node_p(node_t *head, node_t *node_p) {
    /*
    WARNING
    node_p->next MUST EQUAL NULL
    */
    getLastNodePointer(head)->next = node_p;
}

void prepend(node_t ** head_dp, char * value) {
    /*
    Here, head_dp is passed as a double pointer. The parameter is a pointer, pointing to the pointer of the head.
    When dereferenced, the pointer to the head is return
    When dereferenced twice, the head is returned.


    newNode -> head -> ....
    newNode will replace head. Then, newNode will point to head
    */
   
    node_t * newNode = (node_t*) malloc(sizeof(node_t)); // create the new node
    newNode->value = value;
    // the new node points to head
    newNode->next = *head_dp;
    *head_dp = newNode;

}

node_t * get_node_p(node_t * head, unsigned int index) {
    if (index > len(head) - 1) return NULL;
    node_t * temp = head;
    int i = 0;
    for (i; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

void add(node_t * head, char * value, unsigned int atIndex) {
    /*
    Adds a new node with value char * value to the linked list, where its index with be int atIndex

    head -> 2 -> 3 -> 4
            to

    head -> newNode -> 2 -> 3 -> 4

    The previous element will point to the newNode, and the newNode will point to the element it's replacing.
    */

    if (atIndex >= len(head) - 1) {
        append(head, value);
        return;
    }

    if (atIndex == 0) {
        prepend(&head, value);
        return;
    }

    // insert at one
    node_t * newNode = malloc(sizeof(node_t));
    newNode->value = value;
    node_t * replaced = get_node_p(head, atIndex);
    head->next = newNode;
    newNode->next = replaced;
}


node_t * reverse(node_t * head)
    {
        // Initialize current, previous and
        // next pointers
        node_t * current = head;
        node_t * prev = NULL, *next = NULL;
 
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
        return head;
    }




void pop(node_t ** head_dp, unsigned int index) {

    if (index >= len(*head_dp)) return;

    if (index == 0) {
        *head_dp =  get_node_p(*head_dp, index + 1); // the head becomes the element at index 1;
        return;
    }

    if (index == len(*head_dp) - 1) {
        get_node_p(*head_dp, len(*head_dp) - 2)->next = NULL;
        return;
    }

    node_t * prevNode = get_node_p(*head_dp, index - 1);
    free(get_node_p(*head_dp, index)); // dealocate the memory for the removed node

    node_t * nextNode = get_node_p(*head_dp, index + 1);

    prevNode->next = nextNode;

}
/*
a -- b
b -- c
c -- d
d -- e

Inserting f at index 1
a -- f
f -- b
b -- c

a is at index 0, and points to f
f points to b, which is now at index 2

*/