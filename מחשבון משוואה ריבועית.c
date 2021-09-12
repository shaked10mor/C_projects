#include <assert.h>
#include <math.h>
#include <stdio.h>

#define SIGN_CHAR(x) (x > 0 ? '+' : '-')

void print_quadratic(double a, double b, double c)
{
if ((a==0) && (b==0) && (c==0))
    printf("%d",0);
if ((a!=1) && (a!=-1) && (a!=0))
    printf ("%gx^2", a);
if (a==-1)
    printf("-x^2");
if (a==1)
    printf ("x^2");
if ((b!=1) && (b!=-1) && (b!=0)){
    if (a!=0){
    double y = b;
    if (b<0){
        y = (-b);
        }
    printf("%c%gx", SIGN_CHAR(b), y);
    }
    else
        printf ("%gx", b);
    }
if (b==-1)
    printf("-x");
if (b==1){
    if (a!=0)
    printf("+x");
    else
        printf("x");
}
if (c!=0){
    if ((b!=0) || (a!=0)){
    double k = c;
    if (c<0){
        k = (-c);
    }
    printf("%c%g", SIGN_CHAR(c), k);
}
else
    printf("%g", c);
}
}

int find_roots(double a, double b, double c, double* p1, double* p2)
{
    double d = (b*b-4*a*c);
    if ((a==0) && (b==0) && (c==0))
        return -1;
    if ((a==0) && (b==0) && (c!=0))
        return 0;
    if (d<0)
        return 0;
    if ((a==0) && (b!=0) && (c!=0)){
        *p1 = ((-1*c)/b);
        return 1;
    }
    if ((a==0) && (b!=0) && (c==0)){
        *p1 = 0;
        return 1;
    }
    if (d==0){
        *p1 = (((-1)*b) / (2*a));
        if(*p1==(-0))
            *p1 = 0;
        return 1;
    }
    if (d>0){
        *p1 = (((-1)*b)+sqrt(d))/(2*a);
        *p2 = (((-1)*b)-sqrt(d))/(2*a);
        return 2;
    }

}

int main()
{
    double a, b, c;
    printf("Please enter three numbers:\n");
    scanf("%lf%lf%lf", &a, &b, &c);

    double r1, r2;
    int n = find_roots(a, b, c, &r1, &r2);

    print_quadratic(a, b, c);
    printf(" = 0 has ");

    switch (n) {
    case 0:
        printf("no real roots\n");
        break;
    case 1:
        printf("one real root: %g\n", r1);
        break;
    case 2:
        printf("two real roots: %g and %g\n", r1, r2);
        break;
    case -1:
        printf("infinite real roots\n");
        break;
    default:
        printf("%d roots? impossible!\n", n);
    }

    return 0;
}