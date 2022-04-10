#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

/*
 * To return the string from the function, you should either do static allocation or dynamic allocation
 *
 * For example,
 * char* return_string_using_static_allocation() {
 *     static char s[] = "static allocation of string";
 *
 *     return s;
 * }
 *
 * char* return_string_using_dynamic_allocation() {
 *     char* s = malloc(100 * sizeof(char));
 *
 *     s = "dynamic allocation of string";
 *
 *     return s;
 * }
 *
 */
char* timeConversion(char* s) {
    int *arr,x,rem = 0;
    static char *time;
    time =(char*) malloc(sizeof(char)*strlen(s));
    arr = (int *) malloc(sizeof(int)*strlen(s));
    for(int i = 0; i < strlen(s); i++){
        arr[i] = s[i] - 48;
        printf("%d ",arr[i]);
    }
    if(s[8] == 'P'){
        if(arr[0]*10 + arr[1] < 12){
            x = 12 + arr[0]*10 + arr[1];
            arr[1] = x % 10;
            arr[0] = x / 10;
        }
    }
    if(s[8] == 'A'){
        if(arr[0]*10 + arr[1] == 12){
            arr[1] = arr[0] = 0;
        }
    }
    for(int i = 0 ;i<strlen(s)-2; i++){
        time[i] = arr[i]+48;
    }
    return time;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* s = readline();

    char* result = timeConversion(s);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {
        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}



/*

Given a time in -hour AM/PM format, convert it to military (24-hour) time.

Note: - 12:00:00AM on a 12-hour clock is 00:00:00 on a 24-hour clock.
- 12:00:00PM on a 12-hour clock is 12:00:00 on a 24-hour clock.

Example

Return '12:01:00'.
Return '00:01:00'.

Function Description
Complete the timeConversion function in the editor below. It should return a new string representing the input time in 24 hour format.
timeConversion has the following parameter(s):

string s: a time in  hour format
Returns
string: the time in  hour format

Input Format
A single string  that represents a time in -hour clock format (i.e.:  or ).

Constraints
All input times are valid

Sample Input 0

07:05:45PM

Sample Output 0

19:05:45

*/