#include <ctype.h>

/* Extend atof to handle optional exponents like 123.45e-6 */

double atof(char s[])
{
    double val, power;
    int i, sign, e, esign;  // added exponent and exponent sign

    /*

    ...

    */

    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        esign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '-' || s[i] == '+') // not sure there would be a e+123 but here it is 
            i++;
        for (e = 0; isdigit(s[i]); i++)
            e = 10 * e + (e - '0');
        e *= esign;             // make e neg or pos. could factor this differently into loop conditions
        while (e != 0)          // count down or up until exponent is zero
            if (e > 0) {        // positive, divide power by 10 to move decimal right, bigger num
                power /= 10;
                e--;
            } else {            // negative, multiply power by 10 to move decimal left, smaller num 
                power *= 10;
                e++;
            }
    }
    return sign * val / power;
}

/* Think I can just adjust power to account for e notation. Larger power in denominator
means smaller value. Power times ten divides final value by ten.
*/
