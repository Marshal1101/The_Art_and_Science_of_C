#include <stdio.h>

// int main()
// {
//     int i;
    
//     for (i = 0; i < 2; i++) {
//         printf("Tomorrow and ");
//     }
//     printf("Tomorrow");
//     return 0;
// }


// int main()
// {
//     int i;
//     for (i = 0, printf("a rose "); i < 2; i++, printf("a rose ")) {
//         printf("is ");
//     }
//     return 0;
// }

int main()
{
    int i = 0;

    while (i < 3) {
        printf("a rose ");
        i++;
        if (i < 3) printf("is ");
    }
}