#include "tree.h"

#include <stdlib.h>
#include <string.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

struct tree_node* new_tree_node(struct tree_node* parent) {
  struct tree_node* node = malloc(sizeof(struct tree_node));

  if (node == NULL) {
    fprintf(stderr, "error: could not allocate memory for new tree node\n");
    return NULL;
  }

  node->key_a = NULL;
  node->key_b = NULL;
  node->data_a = NULL;
  node->data_b = NULL;

  node->left = NULL;
  node->middle = NULL;
  node->right = NULL;

  node->parent = parent;

  return node;
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

static int tree_find_node(struct tree_node* node, char* key, struct tree_node** result) {
  if (node == NULL) {
    *result = NULL;
    return -1;
  }

  int cmp_a, cmp_b;
  
  if (node->key_a == NULL) {
    *result = NULL;
    return -1;
  }

  cmp_a = strcmp(key, node->key_a);

  if (node->key_b == NULL) {
    cmp_b = cmp_a;
  }
  else {
    cmp_b = strcmp(key, node->key_b);
  }

  if (cmp_a == 0) {
    *result = node;
    return 0;
  }
  if (cmp_b == 0) {
    *result = node;
    return 1;
  }
  if (node->left = NULL) {
    // leaf node
    *result = NULL;
    return 2;
  }
  
  if (cmp_a < 0) {
    return tree_find_node(node->left, key, result);
  }
  if (cmb_b > 0) {
    return tree_find_node(node->right, key, result);
  }
  // else a < key < b
  return tree_find_node(node->middle, key, result);
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void* tree_find(struct tree_node* root, char* key) {
  struct tree_node* node;
  int result_type = tree_find_node(root, key, &node);
  switch (result_type) {
  case 0:
    return node->data_a;
  case 1:
    return node->data_b;
  case 2:
    // flow down
  default:
    return NULL;
  }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int tree_insert(struct tree_node* root, char* key, void* data) {
  struct tree_node* node;
  int result_type = tree_find_node(root, key, &node);

  if (result_type != 2) {
    // key already present
    return -1;
  }

  // two-node
  if (node->key_b == NULL) {
    if (strcmp(key, node->key_a) < 0) {
      char* key_tmp = node->key_a;
      void* data_tmp = node->data_a;
      node->key_a = key;
      node->key_b = key_tmp;
      node->data_a = data;
      node->data_b = data_tmp;
    }
    else {
      node->key_b = key;
      node->data_b = data_tmp;
    }
    return 0;
  }

  // three-node
  char* carry;
  void* data_carry;

  struct tree_node* temp_node;
  
  while( node->key_b != NULL) {
    int cmp_a, cmp_b;
    cmp_a = strcmp(key, node->key_a);
    cmp_b = strcmp(key, node->key_b);

    if (cmp_a < 0) {
      carry = node->key_a;
      data_carry = node->data_a;
      node->key_a = 
