#include <stdio.h>

/*
Problem Description

Question – :  Some prime numbers can be expressed as a sum of other consecutive prime numbers.

For example
5 = 2 + 3,
17 = 2 + 3 + 5 + 7,
41 = 2 + 3 + 5 + 7 + 11 + 13.
Your task is to find out how many prime numbers which satisfy this property are present in the range 3 to N subject to a constraint that summation should always start with number 2.
Write code to find out the number of prime numbers that satisfy the above-mentioned property in a given range.

Input Format: First line contains a number N

Output Format: Print the total number of all such prime numbers which are less than or equal to N.

Constraints: 2<N<=12,000,000,000
*/

int checkPrime(int n)
{
    for(int i = 2; i<=n/2; i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int checkPrimeIsASumOfOldPrimes(int n)
{
    int sum = 0, i = 2;
    while (sum<n)
    {
        if(checkPrime(i)==1) sum=sum+i;
        ++i;
    }
        if(sum==n) return 1;
        return 0;
}

int getNumberOfPrimesWhoIsSumOfOldPrimes(int n)
{
    int count=0;
    for(int i = 3; i<n; i++)
    {
        if(checkPrime(i)==1&&checkPrimeIsASumOfOldPrime(i)) ++count;   
    }

    return count;
}

void main()
{
    printf("%d", getNumberOfPrimeWhoIsSumOfOldPrimes(700));
}