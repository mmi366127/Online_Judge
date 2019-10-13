#include<stdio.h>
#define swap(a,b) {int loli=a;a=b;b=loli;}
int arr[3007];
int n,i,v,ans;
void sort(int,int);
int abs(int a){return (a<0) ? -a : a;}
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    sort(0,n-1);
    ans = 0;
    for(i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1])
        {
            arr[i]++;
            ans++;
        }
        else if(arr[i]<arr[i-1])
        {
            ans += (arr[i-1] - arr[i]);
            arr[i] = arr[i-1];
            arr[i]++; ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
void sort(int start,int end)
{
    if(start>=end)
        return;
    swap(arr[(start+end)>>1],arr[end]);
    int i,j;
    for(i=start,j=start;j<end&&i<end;i++)
    {
        while(arr[j]<arr[end]&&j<end) j++;
        if(i>j&&arr[i]<arr[end])
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
    swap(arr[j],arr[end]);
    sort(start,j-1);
    sort(j+1,end);
}