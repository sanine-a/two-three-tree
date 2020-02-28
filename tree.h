#ifndef TWO_THREE_TREE_H
#define TWO_THREE_TREE_H

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct tree_node;

struct tree_node {
  char* key_a, key_b;
  void* data_a, data_b;
  struct tree_node* left, middle, right, parent;
};

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct tree_node* new_tree_node(struct tree_node* parent);
void* tree_find(struct tree_node* node, char* key);
int tree_insert(struct tree_node* node, char* key, void* data);
