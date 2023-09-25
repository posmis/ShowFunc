#include <stdio.h>
#include <stdlib.h>

#include "base_parameters.h"
#include "dijkstra_algoritm.h"
#include "func_output.h"
#include "stack.h"

int main() {
    char str[MAX_STR_LEN];
    fgets(str, MAX_STR_LEN, stdin);
    struct stack_p *new = alg_dijkstra(str);
    output(new);
    stack_destroy(new);
    return 0;
}