#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int simpleParse(const char *exp);

int simpleParse(const char *exp) {
    int length = strlen(exp);
    int sum = 0, product = 1;
    char prevSumOp = '+', prevProdOp = '*';

    for (int i=0;i<length;i++) {
        if (exp[i] != '+' && exp[i] != '-' && exp[i] != '/' && exp[i] != '*' && exp[i] != '%' && exp[i] != ' ') {
            char *endptr;
            long int num = strtol(&exp[i],&endptr,10);
            i = endptr-exp-1;
            
            if (prevProdOp == '*') {
                product = product * num;
            } else if (prevProdOp ==  '/'){
                product = product / num;
            } else if (prevProdOp == '%'){
                product = product % num;
            }

        }
        else if ((exp[i] == '+' || exp[i] == '-') && exp[i] != ' ') {
            if (prevSumOp == '+') {
                sum = sum + product;
            } else {
                sum = sum - product;
            }
            product = 1;
            prevProdOp = '*';
            prevSumOp = exp[i];
        }
        else if ((exp[i] == '/' || exp[i] == '*' || exp[i] == '%') && exp[i] != ' ') {
            prevProdOp = exp[i];
        }
    }
    if (prevSumOp == '+') {
        sum = sum + product;
    } else if (prevSumOp == '-') {
        sum = sum - product;
    }
    return sum;
}


int main() {
    char exp1[] = "1 + 1";
    char exp2[] = "3 + 7 - 4 * 1";
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 % 97 + 3";
    printf("%s = %d\n", exp1, simpleParse(exp1));
    printf("%s = %d\n", exp2, simpleParse(exp2));
    printf("%s = %d\n", exp3, simpleParse(exp3));
}