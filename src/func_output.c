#include "func_output.h"

void str_converter(char *str) {
    char new_str[MAX_STR_LEN];
    for (int i = 0, j = 0; str[i] != '\0'; i++, j++) {
        if (i == 0 && str[i] == '-') {
            new_str[j] = '0';
            j++;
        }
        if (str[i] == '-' && (str[i - 1] == '(') && i != 0) {
            new_str[j] = '0';
            j++;
        }
        new_str[j] = str[i];
    }
    for (int i = 0; new_str[i] != '\0'; i++) {
        str[i] = new_str[i];
    }
}

void output(struct stack_p *root) {
    double x = DOMAIN_MIN;
    double x_p[SIZE_X];
    for (int i = 0; i < SIZE_X; x += (DOMAIN_MAX - DOMAIN_MIN) / SIZE_X, i++) {
        x_p[i] = pole_note_numb(root, x);
    }
    for (int i = -SIZE_Y / 2; i < SIZE_Y / 2; i++) {
        for (int j = 0; j < SIZE_X; j++) {
            if ((int)round(-x_p[j] * 10) == i)
                printf("*");
            else {
                if (j == SIZE_X / 2)
                    printf("|");
                else if (i == 0)
                    printf("_");
                else
                    printf(".");
            }
        }
        printf("\n");
    }
}