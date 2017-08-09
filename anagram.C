#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void permute(char *a, char *b, int f, int l)
{
int i;
if (f == l){
    int flag=1;
    for(int j=0;b[j]!='\0';j++){
        if(a[0]==b[j]){
            int x=strlen(a);
            
            for(int k=1;k<x;k++){
                if(a[k]!=b[j+k])
                flag=0;
            }
            if(flag==1){
                printf("S=%s T=%s Answer=TRUE\n",b,a);
                return ;
            }
        }
    }
    if(flag!=1){
        printf("S=%s T=%s Answer=FALSE\n",b,a);
    }
    
}
	
else
{
	for (i = f; i <= l; i++)
	{
		swap((a+f), (a+i));
		permute(a,b, f+1, l);
		swap((a+f), (a+i)); //backtrack
	}
}
}

int main()
{
  char S[] = "google";
  char T[] = "goo";
	int n = strlen(T);
	permute(T,S,0, n-1);
    return 0;
}
