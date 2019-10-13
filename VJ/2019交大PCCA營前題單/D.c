#include<stdio.h>
#include<ctype.h>
#define swap(a,b) {int loli=a;a=b;b=loli;}
int arr[100];
char s[107];
int i,idx;
int read(int*,char*);
void sort(int*,int,int);
int main()
{

    while(fgets(s,sizeof(s),stdin))
    {
        idx = read(arr,s);
        sort(arr,0,idx-1);
        printf("%d",arr[0]);
        for(i=1;i<idx;i++)
            printf("+%d",arr[i]);
        puts("");
    }
    return 0;
}
void sort(int* arr,int start,int end)
{
    if(start>=end)
        return;
    swap(arr[((start+end)>>1)],arr[end]);
    int i,j;
    for(i=start,j=start;i<end&&j<end;i++)
    {
        while(arr[j]<arr[end]&&j<end) j++;
        if(i>j&&arr[i]<arr[end])
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[j],arr[end]);
    sort(arr,start,j-1);
    sort(arr,j+1,end);
    return;
}
int read(int arr[],char s[])
{
    int i,idx,tmp;
    for(i=0,idx=0;isprint(s[i]);i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            tmp = 0;
            while(s[i]>='0'&&s[i]<='9')
            {
                tmp = tmp*10  + s[i] - '0';
                i++;
            }
            arr[idx++] = tmp;
        }
    }
    return idx;
}
