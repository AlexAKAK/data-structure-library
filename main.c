#include <stdio.h>
#include "linkedList.h"



int main(void) {
    node_t n1, n2, n3;
    node_t * head;
    n1.value = "1";
    n2.value = "2";
    n3.value = "3";

    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;

    //append(head, "hi");
    //prepend(&head, "souse");
    add(head, "added element", 1);
    printLinkedList(head);


    node_t * new_head = reverse(head);
    printf("\n\n\n\n\n\n\n\n");
    printLinkedList(new_head);



    getchar();
    return 0;
}