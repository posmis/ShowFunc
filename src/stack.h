#ifndef STACK_H
#define STACK_H

struct alg_p{
    double numb;
    int oper;
};

struct stack_p{
    struct alg_p act;
    struct stack_p *next;
    struct stack_p *prev;
};

struct stack_p *stack_init();
void stack_push(struct stack_p *root, double n, int o);
struct alg_p stack_pop(struct stack_p *root);
void stack_destroy(struct stack_p *root);

#endif