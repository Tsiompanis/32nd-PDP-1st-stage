#include<stdio.h>#include<cstdio>#include<algorithm>#include<iostream>#include<array>#include<vector>#include<bits/stdc++.h>
using namespace std;int data[1000005]; int main(){int n,k,help,current_sum;int out=0;int pointer1=0;int pointer2=0;scanf("%d %d",&n,&k);for(int i=1;i<=n;i++)
{scanf("%d",&help);data[i]=data[i-1]+help;}
while(pointer2<n)
{current_sum=data[pointer2+1]-data[pointer1];if(current_sum==k)
{if(pointer2-pointer1+1>out)
out=pointer2-pointer1+1;pointer2++;}
else if(current_sum<k)
pointer2++;else
{pointer1++;if(pointer1==pointer2)
pointer2++;}}
printf("%d\n",out);return 0;}
