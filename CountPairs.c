/*Given an array of integers A, and an integer K find number of happy elements.
*
*Element X is happy if there exists at least 1 element whose difference is less than K i.e. an element X is happy if there is another element in the range [X-K, X+K] other than X itself.
*
*
*
*Constraints
*
*1 <= N <= 10^5
*
*0 <= K <= 10^5
*
*0 <= A[i] <= 10^9
*
*
*
*Input
*
*First line contains two integers N and K where N is size of the array and K is a number as described above. Second line contains N integers separated by space.
*
*
*
*Output
*
*Print a single integer denoting the total number of happy elements.
*
*
*
*Example 1
*
*Input
*
*6 3
*
*5 5 7 9 15 2
*
*
*
*Output
*
*5
*
*
*
*Explanation
*
*Other than number 15, everyone has at least 1 element in the range [X-3, X+3]. Hence they are all happy elements. Since these five are in number, the output is 5.
*
*
*
*Example 2
*
*Input
*
*3 2
*
*1 3 5
*
*
*
*Output
*
*3
*
*
*
*Explanation
*
*All numbers have at least 1 element in the range [X-2, X+2]. Hence they are all happy elements. Since these three are in number, the output is 3.
*
*
*
*Possible Solution
*
*Input:
*
*3 2
*
*1 3 5
*/

#include<stdio.h>

bool searchWithinLimit(int x, int ul, int ll, int * a, int n)
{   //printf("%d %d %d\n", x, ul, ll);
    for(int i = 0; i<n; i++)
    {   //printf("%d\n", a[i]);
        if(a[i]!=x && (a[i]>=ll && a[i]<=ul)) return true; 
    }
    return false;
}

int check(int * a, int n, int k)
{   int count = 0;
    for(int i = 0; i<n; i++)
    {
        int ul = a[i]+k;
        int ll = a[i]-k;
        if(searchWithinLimit(a[i], ul, ll, a, n)==true) ++count;
    }
    return count;    
}

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for(int i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
  
    printf("%d",check(a, n, k));

  
return 0;
}
