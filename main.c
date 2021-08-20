#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "double_linked_list.h"



int main(void) {
    dll_node * head = make_dll_node("0");

    dll_add(head, "1");
    dll_add(head, "2");
    dll_add(head, "3");
    dll_add(head, "4");
    dll_add(head, "5");
    dll_add(head, "6");
    dll_add(head, "7");
    dll_print(head, "%s");




    return EXIT_SUCCESS;
}