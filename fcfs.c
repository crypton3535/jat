#include<stdio.h>


int main()
{
	int n , bur[100] , wait[100] , turn_ar[100] , i; 
	printf("Enter number of processes : ") ;
	scanf("%d" , &n) ;

	for(i = 0 ; i < n ; i++)
	{
		printf("Enter the burst time for process %d : " , i + 1) ;
		scanf("%d" , &bur[i]) ;
	}

	wait[0] = 0 ;
	turn_ar[0] = bur[0] ;
	int sumw = 0 , sumt = 0;

	for(i = 1 ; i < n ; i++)
	{
		wait[i] = bur[i-1] + wait[i-1] ;
		sumw = sumw + wait[i] ;
	}

	for(i = 0 ; i < n ; i++)
	{
		turn_ar[i] = wait[i] + bur[i] ;
		sumt = sumt + turn_ar[i] ;
	}

	printf("PROCESS\t\t        WAIT TIME\tTURN AROUND TIME\n\n") ;

	for(i = 0 ; i < n ; i++)
	{
		printf("process %d\t\t\t%d\t\t%d      \n" , i+1 , wait[i] , turn_ar[i]);
	}

	float avg_wait = (float)sumw/n ;
	float avg_ta = (float)sumt/n ;

	printf("process  completed....\n");
	printf("average waiting time : %f\n" , avg_wait) ;
	printf("average turn around time : %f\n" , avg_ta );

}