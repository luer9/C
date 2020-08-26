#include <stdio.h>


struct Complex{
    int real;
    int imag;
};

/* 你的代码将被嵌在这里 */
struct Complex Multiply(struct Complex x, struct Complex y){
    struct Complex z;
    int real = x.real*y.real - x.imag*y.imag;
    int imag = x.real*y.imag + x.imag*y.real;
    z.real = real; z.imag = imag;
    return z;
}
int main()
{
    struct Complex product, x, y;

    scanf("%d%d%d%d", &x.real, &x.imag, &y.real, &y.imag);
    product = Multiply(x, y);
    printf("(%d+%di) * (%d+%di) = %d + %di\n", 
            x.real, x.imag, y.real, y.imag, product.real, product.imag);

    return 0;
}


/*
3 4 5 6
(3+4i) * (5+6i) = -9 + 38i
3*5+3*6i+20i-24;
*/