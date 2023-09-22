#include "dijkstra_algoritm.h"
#include "operators.h"
#include "stack.h"
#include <stdlib.h>

int operator_priority(int oper){
    int prior = -1;
    if(oper == 1 || oper == 2){

    }
    return prior;
}

struct stack_p *alg_dijkstra(char *str){
    struct stack_p *pol_note = stack_init();
    struct stack_p *oper_stack = stack_init();
    int i = 0;
    while(str[i] != '\0'){
        if(str[i] > 47 && str[i] < 58){
            double temp = atof(str[i]);
        }
        i++;
    }
    return pol_note;
}

