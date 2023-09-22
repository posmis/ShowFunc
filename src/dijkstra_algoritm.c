#include "dijkstra_algoritm.h"

#include <stdlib.h>

#include "operators.h"
#include "stack.h"

int operator_priority(int oper) {
    int prior = -1;
    if (oper == PLUS || oper == MINUS) {
        prior = 1;
    }
    return prior;
}

struct stack_p *alg_dijkstra(char *str) {
    struct stack_p *pol_note = stack_init();
    struct stack_p *oper_stack = stack_init();
    int i = 0;
    while (str[i] != '\0') {
        search_numb(pol_note, str, &i);
        search_base_operators(pol_note, oper_stack, str[i]);
        i++;
    }
    push_all_operators(pol_note, oper_stack);
    stack_destroy(oper_stack);
    return pol_note;
}

void search_numb(struct stack_p *pol_note, char *str, int *i) {
    if ((str[*i] > 47 && str[*i] < 58) || str[*i] == '.') {
        stack_push(pol_note, atof(&str[*i]), NO_OPERATOR);
        do {
            (*i) += 1;
        } while ((str[*i] > 47 && str[*i] < 58) || str[*i] == '.');
        (*i) -= 1;
    }
}

void search_base_operators(struct stack_p *pol_note, struct stack_p *oper_stack, char elem) {
    int operator= NO_OPERATOR;
    if (elem == '+') operator= PLUS;
    if (elem == '-') operator= MINUS;
    if (operator!= NO_OPERATOR) {
        struct alg_p temp = stack_pop(oper_stack);
        while(operator_priority(operator) <= operator_priority(temp.oper)){
            stack_push(pol_note, 0, temp.oper);
            temp = stack_pop(oper_stack);
        }
        stack_push(oper_stack, 0, operator);
    }
}

void push_all_operators(struct stack_p *pol_note, struct stack_p *oper_stack){
    struct alg_p temp;
    do{
        temp = stack_pop(oper_stack);
        if(temp.oper != -1){
            stack_push(pol_note, 0, temp.oper);
        }
    }while(temp.oper != -1);
}