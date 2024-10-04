#include <stdio.h>
#include <stdlib.h>

#include "../include/node.h"

void traverse(struct node_t* root)
{
  char *object = malloc(sizeof(char) * 256),
       *correct_ans = malloc(sizeof(char) * 256),
       *question = malloc(sizeof(char) * 256);
  int ans;

  if (root == NULL) {
    printf("object: ");
    fgets(object, 256, stdin);
    root = create_node(object);
  } else {
    if (is_leaf(root)) {
      printf("%s is the answer? (0 - no, 1 - yes)", root->content);
      scanf("%d", &ans);

      if (ans == 0) {
        printf("what were you thinking? ");
        fgets(correct_ans, 256, stdin);

        printf(
          "what question differs %s from %s? ", correct_ans, root->content
        );
        fgets(question, 256, stdin);

        char* temp = root->content;
        root->content = question;
        root->right = create_node(correct_ans);
        root->left = create_node(temp);
      } else {
        printf("I won!!!!\n");
      }
    } else {
      printf("%s (0 - no, 1 - yes)", root->content);
      scanf("%d", &ans);

      if (ans == 0)
        traverse(root->left);
      else
        traverse(root->right);
    }
  }

  free(object);
  free(correct_ans);
  free(question);
}

int main(int argc, char* argv[])
{
  struct node_t* root = read_from_file();
  int play_again = 0;

  do {
    struct node_t* aux = root;
    traverse(aux);

    printf("play again? (0 - no, 1 - yes)\n");
    scanf("%d", &play_again);
  } while (play_again == 1);

  free(root);

  return 0;
}
