#include "dijkstra_algoritm.h"

#include <stdlib.h>

#include "operators.h"
#include "stack.h"

int operator_priority(int oper) {
    int prior = -1;
    if (oper == PLUS || oper == MINUS) prior = 1;
    if (oper == MULTI || oper == DIVID) prior = 2;
    if (oper == SINUS || oper == COSINUS || oper == TANGENT || oper == COTANGENT) prior = 3;
    if (oper == PARENT) prior = 0;
    return prior;
}

struct stack_p *alg_dijkstra(char *str) {
    struct stack_p *pol_note = stack_init();
    struct stack_p *oper_stack = stack_init();
    int i = 0;
    while (str[i] != '\0') {
        search_numb(pol_note, str, &i);
        search_base_operators(pol_note, oper_stack, str[i]);
        search_operators(oper_stack, str, &i);
        search_parents(pol_note, oper_stack, str, &i);
        i++;
    }
    push_all_operators(pol_note, oper_stack);
    stack_destroy(oper_stack);
    return pol_note;
}

void search_numb(struct stack_p *pol_note, const char *str, int *i) {
    if (str[*i] == 'x') stack_push(pol_note, 0, PARAMETR);
    if ((str[*i] > 47 && str[*i] < 58) || str[*i] == '.') {
        stack_push(pol_note, atof(&str[*i]), NO_OPERATOR);
        do {
            (*i) += 1;
        } while ((str[*i] > 47 && str[*i] < 58) || str[*i] == '.');
        (*i) -= 1;
    }
}

void search_parents(struct stack_p *pol_note, struct stack_p *oper_stack, const char *str, int *i) {
    if (str[*i] == '(') {
        (*i)++;
        stack_push(oper_stack, 0, PARENT);
        while (str[*i] != ')') {
            search_numb(pol_note, str, i);
            search_base_operators(pol_note, oper_stack, str[*i]);
            search_operators(oper_stack, str, i);
            search_parents(pol_note, oper_stack, str, i);
            (*i)++;
        }
        struct alg_p temp = stack_pop(oper_stack);
        while (temp.oper != PARENT) {
            stack_push(pol_note, 0, temp.oper);
            temp = stack_pop(oper_stack);
        }
    }
}

void search_base_operators(struct stack_p *pol_note, struct stack_p *oper_stack, char elem) {
    int operator= NO_OPERATOR;
    if (elem == '+') operator= PLUS;
    if (elem == '-') operator= MINUS;
    if (elem == '*') operator= MULTI;
    if (elem == '/') operator= DIVID;
    if (operator!= NO_OPERATOR) {
        struct alg_p temp = stack_pop(oper_stack);
        while (operator_priority(operator) <= operator_priority(temp.oper)) {
            stack_push(pol_note, 0, temp.oper);
            temp = stack_pop(oper_stack);
        }
        if ((operator_priority(operator) > operator_priority(temp.oper)) && temp.oper != -1) {
            stack_push(oper_stack, 0, temp.oper);
        }
        stack_push(oper_stack, 0, operator);
    }
}

void search_operators(struct stack_p *oper_stack, const char *str, int *i) {
    int operator= NO_OPERATOR;
    if (str[*i] == 's' && str[(*i) + 1] == 'i' && str[(*i) + 2] == 'n') operator= SINUS;
    if (str[*i] == 'c' && str[(*i) + 1] == 'o' && str[(*i) + 2] == 's') operator= COSINUS;
    if (str[*i] == 't' && str[(*i) + 1] == 'a' && str[(*i) + 2] == 'n') operator= TANGENT;
    if (str[*i] == 'c' && str[(*i) + 1] == 't' && str[(*i) + 2] == 'g') operator= COTANGENT;
    if (str[*i] == 'l' && str[(*i) + 1] == 'o' && str[(*i) + 2] == 'g') operator= LOGUS;
    if (str[*i] == 's' && str[(*i) + 1] == 'q' && str[(*i) + 2] == 'r' && str[(*i) + 3] == 't')
        operator= SQUREROOT;
    if (operator!= NO_OPERATOR) {
        //(*i) += 2;
        stack_push(oper_stack, 0, operator);
    }
}

void push_all_operators(struct stack_p *pol_note, struct stack_p *oper_stack) {
    struct alg_p temp;
    do {
        temp = stack_pop(oper_stack);
        if (temp.oper != -1) {
            stack_push(pol_note, 0, temp.oper);
        }
    } while (temp.oper != -1);
}