#ifndef NODE_H
#define NODE_H

struct node_t {
  char* content;
  struct node_t* left;
  struct node_t* right;
};

struct node_t* read_from_file();

struct node_t* create_node(char* content);

#endif
