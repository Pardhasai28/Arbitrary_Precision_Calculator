#include "dll.h"

int compare_abs(char *a, char *b)
{
    if (*a == '+' || *a == '-')     // Skip sign character (+ or -) for string a
        a++;
    if (*b == '+' || *b == '-')         // Skip sign character (+ or -) for string b
        b++;

    while (*a == '0')       // Remove leading zeros from string a
        a++;
    while (*b == '0')       // Remove leading zeros from string b
        b++;

    if (*a == '\0')         // If a becomes empty after removing zeros, treat it as "0"
        a = "0";
    if (*b == '\0')         // If b becomes empty after removing zeros, treat it as "0"
        b = "0";

    int len1 = strlen(a);                 // Get length of processed string a
    int len2 = strlen(b);                // Get length of processed string b


    if (len1 > len2)                    // If length of a is greater, its absolute value is larger
        return 1;
    if (len1 < len2)                   // If length of b is greater, its absolute value is larger
        return -1;
    return strcmp(a, b);            // If lengths are equal, compare strings lexicographically
}