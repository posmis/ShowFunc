#include <stdio.h>
#include <stdlib.h>

#include "dijkstra_algoritm.h"
#include "pol_note_count.h"
#include "stack.h"

#define MAX_STR_LEN 1000

int main() {
    char str[MAX_STR_LEN];
    fgets(str, MAX_STR_LEN, stdin);

    struct stack_p *new = alg_dijkstra(str);

    printf("-- %f --\n", pole_note_numb(new, 3));

    stack_destroy(new);
    return 0;
}