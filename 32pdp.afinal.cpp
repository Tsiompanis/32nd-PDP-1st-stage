/* USER: 32pdpu17 
LANG: C++ 
TASK: erasmus*/
#include <stdio.h>      
#include <cstdio>      
#include <algorithm>      
#include <iostream>    
#include <array>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;
           
           
//vector and array declaration
int uni[1005];
int out[10005];
array<int, 15> data[10005];

int main()    
{    

	//declaring variables 
   	int n = 0;
   	int m = 0;
   	int help = 0;
	int j;
	
	
	//initializing freopen functions
	freopen("erasmus.in","r",stdin);      
    freopen("erasmus.out","w",stdout);    
      
	            
    //Scanning and storing the num. of students and the num. of the universities            
    scanf("%d",&n);    
    scanf("%d",&m); 
	      
		     
    //scanning the universities open positions and placing them in a 1D array
    for(int i=0;i<=n-1;i++)
    {
    	scanf("%d",&uni[i]);
    }

    //scanning the student-university data and placing them in a 2D array 
    for(int i=0;i<=m-1;i++) 
    {
    	scanf("%d",&data[i][0]);
    	scanf("%d",&help);
    	data[i][1] = help;
    	data[i][13] = i;
    	
    	for(int j=2;j<=help+1;j++)
    	{
    		scanf("%d",&data[i][j]);	 
		}
	}
	
	
	sort(data, data + m);	//Sorting the student-university data
	
	
	//deciding what student will go to what university
	for(int i = m-1; i >= 0; i--)
	{
		for(int x = 0; x <= data[i][1]-1; x++)
				{ 
					if (uni[data[i][x+2]-1] != 0)
					{
						data[i][12] = data[i][x+2];
						uni[data[i][x+2]-1]--;
						break;
					}
				}						
	}
	
 		//Managing the output data	
		for(int i = 0; i <= m-1; i++)
		{
			if (data[i][12] == 0)
			{
				out[data[i][13]] = 0;
			}
			else
			{
				out[data[i][13]] = data[i][12];
			}
		} 
		
		
		//printing output data
		for(int i = 0; i <= m-1; i++)
		{
			if (out[i] == 0)
			{
				printf("NONE\n");
			}
			else
			{
				printf("%d\n",out[i]);
			}
		} 
		return 0;
}
