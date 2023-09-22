#ifndef DIJKSTRA_ALGORITM_H
#define DIJKSTRA_ALGORITM_H

int operator_priority(int oper);
struct stack_p *alg_dijkstra(char *str);

void push_all_operators(struct stack_p *pol_note, struct stack_p *oper_stack);

void search_numb(struct stack_p *root, char *str, int *i);
void search_base_operators(struct stack_p *pol_note, struct stack_p *oper_stack, char elem);

#endif