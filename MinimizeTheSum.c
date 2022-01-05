#include<stdio.h>
#include<math.h>

/*

Minimize the sum

Given an array of integers, perform atmost K operations so that the sum of elements of final array is minimum. An operation is defined as follows -

Consider any 1 element from the array, arr[i].

Replace arr[i] by floor(arr[i]/2).

Perform next operations on the updated array.

The task is to minimize the sum after utmost K operations.



Constraints

1 <= N, K <= 10^5.



Input

First line contains two integers N and K representing size of array and maximum numbers of operations that can be performed on the array respectively.

Second line contains N space separated integers denoting the elements of the array, arr.



Output

Print a single integer denoting the minimum sum of the final array.



Input

4 3

20 7 5 4



Output

17



Explanation

Operation 1 -> Select 20. Replace it by 10. New array = [10, 7, 5, 4]

Operation 2 -> Select 10. Replace it by 5. New array = [5, 7, 5, 4].

Operation 3 -> Select 7. Replace it by 3. New array = [5,3,5,4].

Sum = 17.



Possible Solution

Input:

4 3

20 7 5 4
*/



int max(int * a, int n)
{   int max = a[0];
    for(int i =1; i<n; i++){
        if(a[i]>max) max = a[i];
    }
    return max;
}

int* replaceMax(int *a,int n, int max)
{
    for(int i = 0; i<n; i++)
    {
        if(a[i]==max) a[i] = floor(a[i]/2);
    }
    return a;
}

int* replace(int * a, int n, int k){
    int sum=0;
    int *ar;
    for(int i = 0; i<k; i++)
    {
        ar = replaceMax(a, n, max(a, n));
    }
    return ar; 
}

int sum(int * a, int n)
{
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum= sum+a[i];
    }
    return sum;
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ar[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &ar[i]);
    }
    
    //printf("%d", max(ar, n));

    printf("%d", sum(replace(ar, n, k), n));

    return 0;
}