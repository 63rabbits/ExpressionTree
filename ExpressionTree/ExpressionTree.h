#ifndef ExpressionTree_h
#define ExpressionTree_h

#include <stdbool.h>
#include "BinaryTree.h"

//////////////////////////////////////////////////
BTN_t *createExpressionTree(char *expression);
BTN_t *createExpressionTreeSlave(QUEUE_t *Q);
bool destroyExpressionTree(BTN_t *R);
int getTypeOfOperatorOnET(char *token);
void viewExpressionTree(BTN_t *R);

#endif
