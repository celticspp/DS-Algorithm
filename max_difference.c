#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
 
#define N 100

int max(int num1, int num2)
{
	return num1 > num2 ? num1 : num2;
}

int min(int num1, int num2)
{
	return num1 < num2 ? num1 : num2;
}

int max_difference(int *array, int n)
{
	int *max_left = (int*)malloc(sizeof(int) * n);
	int *min_left = (int*)malloc(sizeof(int) * n);
	int *max_right = (int*)malloc(sizeof(int) * n);
	int *min_right = (int*)malloc(sizeof(int) * n);
	
	//initialize
	int max_left_until = array[0];
	int min_left_until = array[0];
	max_left[0] = array[0];
	min_left[0] = array[0];
	
	//calculate max_left and min_left
	for(int i=1; i<n; i++)
	{
		if(max_left_until > 0)
			max_left_until += array[i];
		else
			max_left_until = array[i];
		
		if(min_left_until < 0)
			min_left_until += array[i];
		else
			min_left_until = array[i];
		
		max_left[i] = max(max_left[i-1], max_left_until);
		min_left[i] = min(min_left[i-1], min_left_until);
	}
	
	//print max_left and min_left
	printf("\n max_left = ");
	for(int i=0; i<n; i++)
	{
		printf("%d ", max_left[i]);
	}
	printf("\n min_left = ");
	for(int i=0; i<n; i++)
	{
		printf("%d ", min_left[i]);
	}
	
	//initialize
	int max_right_until = array[n-1];
	int min_right_until = array[n-1];
	max_right[n-1] = array[n-1];
	min_right[n-1] = array[n-1];
	
	//calculate max_right and min_right
	for(int i=n-2; i>=0; --i)
	{
		if(max_right_until > 0)
			max_right_until += array[i];
		else
			max_right_until = array[i];
			
		if(min_right_until < 0)
			min_right_until += array[i];
		else
			min_right_until = array[i];
			
		max_right[i] = max(max_right[i+1], max_right_until);
		min_right[i] = min(min_right[i+1], min_right_until);
	}
	
	//print max_right and min_right
	printf("\n max_right = ");
	for(int i=0; i<n; i++)
	{
		printf("%d ", max_right[i]);
	}
	printf("\n min_right = ");
	for(int i=0; i<n; i++)
	{
		printf("%d ", min_right[i]);
	}
	
	int max_diff = INT_MIN;
	for(int i=1; i<n; ++i)
	{
		int temp =  max(max_left[i-1] - min_right[i],
					max_right[i] - min_left[i-1]);
		
		if(temp > max_diff)
		max_diff = temp;
				
	}
	
	free(max_left);
	free(min_left);
	free(max_right);
	free(min_right);
	
	return max_diff;
}

int main(int argc, char **argv)
{
	//a = 7 2 -1 -2 1 -4 2 8
	int a[N];
	int n; //actual array size
	while(scanf("%d", &n) != EOF)
	{
		for(int i=0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		printf("\n max_difference = %d\n", max_difference(a, n));
	}	
	return 0;
} 

int max_sum(int* array, int n)
{
	assert(array != NULL);
	
	int max_sofar = array[0];
	int max_until = array[0];
	
	for(int i = 1; i < n; i++)
	{
		if(max_until > 0)
		{
			max_until += array[i];
		}
		else
		{
			max_until = array[i];
		}
		max_sofar = max(max_sofar, max_until);
	}
	return max_sofar;	
}
