#include <unistd.h>
//#define checkMemoryLeak

#include <stdio.h>
#include <stdlib.h>
#include "ReversePolishNotation.h"
#include "ExpressionTree.h"

//////////////////////////////////////////////////
void test(void);

//////////////////////////////////////////////////
int main(int argc, const char * argv[]) {

#ifdef checkMemoryLeak
    while (true) {
        test();
        sleep(1);
    }
#else
    test();
#endif
    
    return EXIT_SUCCESS;
}

void test() {
    char *expression = "f=(A+B*C)/(~D+E^F*G)";
    printf("Expression              : %s\n", expression);
    
    // check Reverse Polish Notation.
    char *rpn = convertToRPN(expression, "");
    printf("Reverse Polish Notation : %s\n", rpn);
    free(rpn);
    
    BTN_t *root = createExpressionTree(expression);
    printf("Expression Tree         :\n");
    viewExpressionTree(root);
    destroyExpressionTree(root);
}
