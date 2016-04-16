#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std ;

struct process
{
	int priority ;
	int burst ;
} ;

bool cmpfnc(process a , process b)
{
	if(a.priority < b.priority)
		return true ;
	else
		return false ;
}


main()
{
	process arr[1000] ;

	int i , n;
	printf("Enter number of processes : ") ;
	scanf("%d", &n) ;
	for(i = 0 ; i < n ; i++)
	{
		printf("Enter the priority and burst time of process %d" , i + 1 ) ;
		scanf("%d%d", &arr[i].priority , &arr[i].burst) ;
	}

	sort(arr, arr + n,cmpfnc) ;

	int wait[100] ;
	wait[0] = 0 ;

	for(i = 1 ; i < n ; i++)
	{
		wait[i] = wait[i-1] + arr[i-1].burst ;
	}

	int turn[100] ;

	turn[0] = arr[0].burst ;

	for(i = 1 ; i < n ; i++)
	{
		turn[i] = wait[i] + arr[i].burst ;
	}

	for(i = 0 ; i < n  ; i++)
	{
		printf("process %d   waiting time : %d     turnaround time : %d\n" , i + 1 , wait[i] , turn[i]) ;
	}

}
