#include "DataTypes.h"

 int main()
   {
       char first_char = 'c';
       char second_char = 'Y';

       char_show(first_char, second_char);

       short first_sh = 123;
       short second_sh = 456;

       short_show(first_sh, second_sh);

       int first_int = -32768;
       int second_int = 32767;

       int_show(first_int, second_int);

       long first_long = -2100000000;
       long second_long = 2140000000;

       long_show(first_long, second_long);

       long long first_ll = -9200000000000000000;
       long long second_ll = 9200000000000000000;

       ll_show(first_ll, second_ll);

       float first_flo = 3.14159;
       float second_flo = 2.71828;

       float_show(first_flo, second_flo);

       double first_db = 3.141592653589793238;
       double second_db = 2.718281828459045;

       double_show(first_db, second_db);

       long double first_ld = 15.123456789123456789123456789;
       long double second_ld = 987.654321987654321987654321987;

       ld_show(first_ld, second_ld);
       return 0;
   }