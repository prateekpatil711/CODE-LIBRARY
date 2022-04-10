#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int i,j;
    for(i = n - 1 ; i>0 && (strcmp(s[i-1],s[i]) >= 0) ; i--);
    if(i<=0)
    return 0;
    for(j = n - 1 ; strcmp(s[i-1] , s[j]) >= 0 ; j--);
    char *temp = s[i - 1];
    s[i - 1] = s[j];
    s[j] = temp;
    j = n - 1;
    
    for( ; i < j ; i++ , j--){
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return 1;
  
}


int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}

/*


Sample Input 0
2
ab
cd

Sample Output 0
ab cd
cd ab

Sample Input 1
3
a
bc
bc

Sample Output 1
a bc bc
bc a bc
bc bc a

*/