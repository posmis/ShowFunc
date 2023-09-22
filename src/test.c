#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    struct stack_p *alg = stack_init();
    //printf("%.2f %d %p", alg->numb, alg->oper, alg->next);
    int n = 5;
    double numb[5] = {2.2,3.3,4.4,7.7,8.8};
    for(int i = 0; i < n; i++){
        stack_push(alg,numb[i],0);
    };
    struct stack_p *p = alg;
    do {
        printf("%.2f %d %p\n", p->act.numb, p->act.oper, p->next);
        p = p->next;
    }while(p != NULL);
    printf("\n\n");

    struct alg_p output;
    do{
      output = stack_pop(alg);
      printf("%.2f %d\n", output.numb, output.oper);
    } while(output.oper != -1);
    free(alg);
    return 0;
}