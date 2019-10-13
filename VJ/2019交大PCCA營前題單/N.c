#include<stdio.h>
int n,m,i,ans;
int arr[107];
int tmp[107];
void sort(int*,int*,int,int);
int main()
{
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",arr+i);
    sort(arr,tmp,0,n-1);
    for(i=0,ans=0;i<m&&arr[i]<0;i++)
        ans += arr[i];
    printf("%d\n",-ans);
    return 0;
}
void sort(int arr[],int tmp[],int start,int end)
{
    if(start>=end)
        return;
    int mid = (start+end)>>1;
    int idx1 = start;
    int idx2 = mid+1;
    int idx  = start;
    sort(arr,tmp,idx1,mid);
    sort(arr,tmp,idx2,end);
    while(idx1<=mid&&idx2<=end)
    {
        if(arr[idx1]<arr[idx2])
            tmp[idx++] = arr[idx1++];
        else
            tmp[idx++] = arr[idx2++];
    }
    while(idx1<=mid)
        tmp[idx++] = arr[idx1++];
    while(idx2<=end)
        tmp[idx++] = arr[idx2++];
    for(idx=start;idx<=end;idx++)
        arr[idx] = tmp[idx];
}
