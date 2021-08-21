#include <stdlib.h>
#include <stdio.h>

#define LEFT 0
#define RIGHT 1

struct bt_node_s {
    void * value;
    struct bt_node_s * left;
    struct bt_node_s * right;
};

typedef struct bt_node_s bt_node;

bt_node * bt_create_node(void * value, bt_node * left, bt_node * right) {
    bt_node * n = malloc(sizeof(bt_node));
    n->value = value;
    n->left = value;
    n->right = right;
    return n;
}

void bt_print(bt_node * head, const char * format) {
    
}

