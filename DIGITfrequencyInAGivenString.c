#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void frequency(char *str);
int main()
{
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char str[1000];
    gets(str);
    frequency(str);
    return 0;
}
void frequency(char *str)
{
    char i;
    int l,freq,j;
    l=strlen(str);
for(i='0';i<='9';i++)
 {   freq=0;
    
        for(j=0;j<l;j++)
        {
            if(*(str+j)==i)
            freq++;
        }
        printf("%d ",freq);
}
}

/*

Sample Input 0
a11472o5t6
Sample Output 0

0 2 1 0 1 1 1 1 0 0 
Explanation 0

In the given string:

 occurs two times.
 and  occur one time each.
The remaining digits  and  don't occur at all.
Sample Input 1

lw4n88j12n1
Sample Output 1

0 2 1 0 1 0 0 0 2 0 
Sample Input 2

1v88886l256338ar0ekk
Sample Output 2

1 1 1 2 0 1 2 0 5 0 

*/