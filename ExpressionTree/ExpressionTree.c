#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include "ReversePolishNotation.h"
#include "ExpressionTree.h"

//////////////////////////////////////////////////
BTN_t *createExpressionTree(char *expression) {
    // Reverse the order of the queues.
    Queue_t *Q = convertQueueToRPN(expression);
    Stack_t *S = createStack();
    while (!isEmptyQueue(Q)) {
        void *element = deQueue(Q);
        pushStack(S, element);
    }
    while (!isEmptyStack(S)) {
        void *element = popStack(S);
        enQueue(Q, element);
    }
    destroyStack(S, STACK_OPTION_WITH_ELEMENT);
    
    BTN_t *root = createExpressionTreeSlave(Q);
    destroyQueue(Q, QUEUE_OPTION_WITH_ELEMENT);
    return root;
}

BTN_t *createExpressionTreeSlave(Queue_t *Q) {
    if (isEmptyQueue(Q)) return NULL;
    
    char *token = deQueue(Q);
    int tokenType = getTypeOfOperatorOnET(token);
    BTN_t *node = createNodeBT((int)token[0], token);
    switch (tokenType) {
        case BINARY_OPERATOR:
            node->right = createExpressionTreeSlave(Q);
            node->left = createExpressionTreeSlave(Q);
            break;
        case UNARY_OPERATOR:
            node->right = createExpressionTreeSlave(Q);
            node->left = NULL;
            break;
        case OTHER_OPERATOR:    
            break;
        default:    // it is operand.
            break;
    }

    return node;
}

bool destroyExpressionTree(BTN_t *R) {
    return destroyNodeBT(R, BT_OPTION_WITH_ELEMENT);
}

int getTypeOfOperatorOnET(char *token) {
    int type = -1;
    int i = 0;
    while (operators[i].priority > 0) {
        if (strcmp(operators[i].token, token) == 0) {
            type = operators[i].type;
            break;
        }
        i++;
    }
    return type;
}

void viewExpressionTree(BTN_t *R) {
    viewBT(R, BT_OPTION_VIEW_CHAR);
}
