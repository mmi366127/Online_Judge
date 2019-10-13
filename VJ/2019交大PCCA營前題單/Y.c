#include<stdio.h>
#include<string.h>
#define maxn 5007
int sg[maxn];
char s[maxn];
char bo[maxn];
int i,len;

int getsg(int);
int getans(int,int);
int main(){
	memset(sg,-1,sizeof(sg));
	sg[0]=0,sg[1]=1;
	for (i=2;i<maxn;i++) if (sg[i]==-1) sg[i]=getsg(i);
	for (i=0;i<=10;i++) { printf("%d",sg[i]); }
	while (scanf("%s",s)!=EOF){
		char sec=1;
		for (i=1,len=strlen(s);i<len-1;i++){
			if (s[i-1]!=s[i+1]) continue;
			if (getans(0,i-1)^getans(i+1,len-1)) continue;
			printf("First\n%d\n",i+1),sec=0;break;
		}
		if (sec) puts("Second");
	}
	return 0;
}
int getsg(int len){
	if (sg[len]!=-1) return sg[len];
	memset(bo,0,sizeof(bo));
	bo[getsg(len-2)]=1;
	int i;
	for (i=1;i+i<len;i++) bo[getsg(i-1)^getsg(len-i-2)]=1;
	for (i=0;i<maxn;i++) if (!bo[i]) return sg[len]=i;
}
int getans(int l,int r){
	int i,sum=0;
	for (i=l+1;i<=r-1;i++)
		if (s[i+1]==s[i-1]){
			int len=0;
			while (s[i+1]==s[i-1]&&i<=r-1) i++,len++;
			sum^=sg[len];
			//printf("%d\n",len);
		}
	return sum;
}
