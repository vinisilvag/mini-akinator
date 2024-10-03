#include "../include/node.h"

#include <stddef.h>

struct node_t* read_from_file() { return NULL; }

struct node_t* create_node(char* content)
{
  struct node_t* new_node = NULL;
  new_node->content = content;
  new_node->left = NULL;
  new_node->right = NULL;
  return new_node;
}
