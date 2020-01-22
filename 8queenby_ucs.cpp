#include <stdbool.h> 
#include <stdio.h> 
#define n 8

int possible_move(int a[n][n], int row, int col) 
{ 
	int i, j; 

	
	for (i = 0; i < col; i++) 
		if (a[row][i]) 
			return 0; 

	
	for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
		if (a[i][j]) 
			return 0; 

	
	for (i = row, j = col; j >= 0 && i < n; i++, j--) 
		if (a[i][j]) 
			return 0; 

	return 1; 
} 


int fun(int a[n][n], int col) 
{ 
	
	if (col >= n) 
		return 1; 

	
	for (int i = 0; i < n; i++) { 
		
		if (possible_move(a, i, col)) { 
			
			a[i][col] = 1; 

			
			if (fun(a, col + 1)) 
				return 1; 

			
			a[i][col] = 0;
		} 
	} 

	
	return 0; 
} 


int main() 
{ 



	int a[n][n]; 
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
        {
            a[i][j]=0;
        }

	
	}

	if (fun(a, 0) == 0) { 
		printf("solution not exit"); 
	
	} 

		for (int i = 0; i < n; i++)
		{ 
		        for (int j = 0; j < n; j++) 
			    printf(" %d ", a[i][j]); 
			    
			    
		printf("\n"); 
    	} 




	return 0; 
} 
