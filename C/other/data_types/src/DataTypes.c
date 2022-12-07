#include <stdlib.h>
#include <stdio.h>

 void char_show(char first_var, char second_var)
{
    printf("The two single character values passed are %c and %c\n", first_var, second_var);
}

 void short_show(short first_var, short second_var)
{
    printf("Short is 2 bytes so has 65536 values it can take. \n");
    printf("The values we receives are: %hi and %hi.\n", first_var, second_var);

}

 void int_show(int first_var, int second_var)
{
    printf("Int is at least 2 bytes so has at least 65536 values it can take. \n");
    printf("The values we receives are: %i and %i.\n", first_var, second_var);
}

 void long_show(long first_var, long second_var)
{
    printf("Long int is at least 4 bytes so has at least 4,294967294 values centered on 0. \n");
    printf("The values we receives are: %li and %li.\n", first_var, second_var);
}

 void ll_show(long long first_var, long long second_var)
{
    printf("Long long int is at least 8 bytes so has at least a large quintillion value centered on 0. \n");
    printf("The values we receives are: %lli and %lli.\n", first_var, second_var);
}

 void float_show(float first_var, float second_var)
{
    printf("Floating point(single-precision) is unspecified, most systems are 8 bytes with 754 precision binary. \n");
    printf("The values we receives are: %f and %f.\n", first_var, second_var);
}

 void double_show(double first_var, double second_var)
{
    printf("Floating point(double-precision) is unspecified, most systems are 16 bytes with 754 double-precision binary. \n");
    printf("The values we receives are: %lf and %lf.\n", first_var, second_var);
}

 void ld_show(long double first_var, long double second_var)
{
    printf("Floating point(extended-precision) is unspecified, can be 10 bytes, 12, 16. \n");
    printf("The values we receives are: %Lf and %Lf.\n", first_var, second_var);
}