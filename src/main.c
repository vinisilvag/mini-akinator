#include <stdio.h>

#include "../include/node.h"

int main(int argc, char* argv[])
{
  struct node_t* root = read_from_file();

  if (root == NULL) {
    printf("start from scratch\n");
  } else {
    printf("readed from file\n");
  }

  return 0;
}
