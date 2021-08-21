#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "double_linked_list.h"



int main(void) {
    dll_node * head = make_dll_node("0");

    dll_append(head, "1");
    dll_append(head, "2");
    dll_append(head, "3");
    dll_append(head, "4");
    dll_append(head, "5");
    dll_append(head, "6");
    dll_append(head, "7");
    dll_prepend(&head, "prepended element");
    dll_print(head, "%s");




    return EXIT_SUCCESS;
}