#include <stdio.h>
#include <stdlib.h>

#include "base_parameters.h"
#include "dijkstra_algoritm.h"
#include "func_output.h"
#include "stack.h"

int main() {
    char str[MAX_STR_LEN];
    fgets(str, MAX_STR_LEN, stdin);
    str_converter(str);
    printf("%s\n", str);
    struct stack_p *new = alg_dijkstra(str);
    struct stack_p *p = new;
    while (p != NULL) {
        printf("%.2f ^ %d\n", p->act.numb, p->act.oper);
        p = p->next;
    }
    output(new);
    stack_destroy(new);
    return 0;
}