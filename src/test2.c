#include <stdio.h>
#include <stdlib.h>

#include "dijkstra_algoritm.h"
#include "stack.h"

int main() {
    char str[100] = {"1-2-3+4+5"};

    struct stack_p *new = alg_dijkstra(str);

    struct alg_p output;
    do {
        output = stack_pop(new);
        printf("%.2f %d\n", output.numb, output.oper);
    } while (output.oper != -1);

    stack_destroy(new);
    return 0;
}
