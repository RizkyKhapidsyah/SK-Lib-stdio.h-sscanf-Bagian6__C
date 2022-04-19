#pragma warning(disable:4996)

#define __STDC_WANT_LIB_EXT1__ 1

#include <stdio.h>
#include <stddef.h>
#include <locale.h>
#include <conio.h>

/*
    Source by CPPReference
    Modified For Learn by RK
    I.D.E : VS2019
*/

int main(void) {
    int i, j;
    float x, y;
    char str1[10], str2[4];
    wchar_t warr[2];
    setlocale(LC_ALL, "en_US.utf8");

    char input[] = "25 54.32E-1 Thompson 56789 0123 56ß水";
    int ret = sscanf(input, "%d%f%9s%2d%f%*d %3[0-9]%2lc", &i, &x, str1, &j, &y, str2, warr);

    printf("Converted %d fields:\ni = %d\nx = %f\nstr1 = %s\n"
        "j = %d\ny = %f\nstr2 = %s\n"
        "warr[0] = U+%x warr[1] = U+%x\n",
        ret, i, x, str1, j, y, str2, warr[0], warr[1]);

#ifdef __STDC_LIB_EXT1__
    int n = sscanf_s(input, "%d%f%s", &i, &x, str1, (rsize_t)sizeof str1);
    // writes 25 to i, 5.432 to x, the 9 bytes "thompson\0" to str1, and 3 to n.
#endif

    _getch();
    return 0;
}