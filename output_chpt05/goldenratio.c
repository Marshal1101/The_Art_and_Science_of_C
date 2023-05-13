/**
 * @file goldenratio.c
 * @brief This constant is the golden ratio.
 *        ancient mathematicians believed this
 *        in the most beautiful ratio. exec 5-1
 * @date 2023-05-13
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double Pi;
    Pi = (1 + sqrt(5)) / 2;
    printf("golden ratio is %g", Pi);
    return 0;
}