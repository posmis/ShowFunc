#include "pol_note_count.h"

double pole_note_numb(struct stack_p *pole_note, double x) {
    struct stack_p *p = pole_note;
    struct stack_p *digits = stack_init();
    while (p != NULL) {
        if (p->act.oper == NO_OPERATOR)
            stack_push(digits, p->act.numb, NO_OPERATOR);
        else if (p->act.oper == PARAMETR)
            stack_push(digits, x, NO_OPERATOR);
        else if (p->act.oper == PLUS || p->act.oper == MINUS || p->act.oper == MULTI ||
                 p->act.oper == DIVID) {
            double temp;
            struct alg_p numb1, numb2;
            numb2 = stack_pop(digits);
            numb1 = stack_pop(digits);
            switch (p->act.oper) {
                case PLUS:
                    temp = numb1.numb + numb2.numb;
                    break;
                case MINUS:
                    temp = numb1.numb - numb2.numb;
                    break;
                case MULTI:
                    temp = numb1.numb * numb2.numb;
                    break;
                case DIVID:
                    temp = numb1.numb / numb2.numb;
                    break;
            }
            stack_push(digits, temp, NO_OPERATOR);
        } else {
            double temp;
            struct alg_p numb;
            numb = stack_pop(digits);
            switch (p->act.oper) {
                case SINUS:
                    temp = sin(numb.numb);
                    break;
                case COSINUS:
                    temp = cos(numb.numb);
                    break;
                case TANGENT:
                    temp = tan(numb.numb);
                    break;
                case COTANGENT:
                    temp = cos(numb.numb) / sin(numb.numb);
                    break;
                case LOGUS:
                    temp = log(numb.numb);
                    break;
                case SQUREROOT:
                    temp = sqrt(numb.numb);
                    break;
            }
            stack_push(digits, temp, NO_OPERATOR);
        }
        p = p->next;
    }
    struct alg_p result = stack_pop(digits);
    free(digits);
    return result.numb;
}