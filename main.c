#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"


int main(void) {
    node_t * head = makeLinkedList("Hello!");
    append(head, "what's up");
    pop(&head, 1);    
 


    printLinkedList(head);

    return EXIT_SUCCESS;
}