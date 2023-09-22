#include "stack.h"

#include <stdlib.h>

struct stack_p *stack_init() {
    struct stack_p *new = malloc(sizeof(struct stack_p));
    new->act.numb = 0;
    new->act.oper = -1;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void stack_push(struct stack_p *root, double n, int o) {
    struct stack_p *p = root;
    struct stack_p *new = malloc(sizeof(struct stack_p));
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = new;

    new->act.numb = n;
    new->act.oper = o;
    new->prev = p;
    new->next = NULL;
}

struct alg_p stack_pop(struct stack_p *root) {
    struct alg_p elem;
    struct stack_p *p = root;

    while (p->next != NULL) {
        p = p->next;
    }
    if (p->prev != NULL) {
        elem.numb = p->act.numb;
        elem.oper = p->act.oper;
        struct stack_p *d = p->prev;
        d->next = NULL;
        free(p);
    } else {
        elem.oper = -1;
    }
    return elem;
}

void stack_destroy(struct stack_p *root) {
    if (root->next != NULL) {
        struct stack_p *p = root;
        while (p->next != NULL) {
            p = p->next;
        }
        free(p);
        stack_destroy(root);
    }
    free(root);
}