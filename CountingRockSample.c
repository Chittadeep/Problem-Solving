#include<stdio.h>

/*Problem Description

Question – : Juan Marquinho is a geologist and he needs to count rock samples in order to send it to a chemical laboratory. He has a problem: The laboratory only accepts rock samples by a range of its size in ppm (parts per million).

Juan Marquinho receives the rock samples one by one and he classifies the rock samples according to the range of the laboratory. This process is very hard because the number of rock samples may be in millions.

Juan Marquinho needs your help, your task is to develop a program to get the number of rocks in each of the ranges accepted by the laboratory.

Input Format: An positive integer S (the number of rock samples) separated by a blank space, and a positive integer R (the number of ranges of the laboratory); A list of the sizes of S samples (in ppm), as positive integers separated by space R lines where the ith line containing two positive integers, space separated, indicating the minimum size and maximum size respectively of the ith range.

Output Format: R lines where the ith line contains a single non-negative integer indicating the number of the samples which lie in the ith range.

Constraints:

10 <= S <= 10000
1 <= R <= 1000000
1<=size of Sample <= 1000
Example 1

Input: 10 2
345 604 321 433 704 470 808 718 517 811
300 350
400 700
Output: 2 4

Explanation:

There are 10 samples (S) and 2 ranges ( R ). The samples are 345, 604,811. The ranges are 300-350 and 400-700. There are 2 samples in the first range (345 and 321) and 4 samples in the second range (604, 433, 470, 517). Hence the two lines of the output are 2 and 4

Example 2

Input: 20 3
921 107 270 631 926 543 589 520 595 93 873 424 759 537 458 614 725 842 575 195
1 100
50 600
1 1000
Output: 1 12 20

Explanation:

There are 20 samples and 3 ranges. The samples are 921, 107 195. The ranges are 1-100, 50-600 and 1-1000. Note that the ranges are overlapping. The number of samples in each of the three ranges are 1, 12 and 20 respectively. Hence the three lines of the output are 1, 12 and 20.
*/

int countSamples(int s, int * ar, int r1, int r2)
{
    int count = 0;

    for(int i = 0; i<s; i++)
    {
        if(ar[i]>=r1&&ar[i]<=r2) ++count;
    }
    return count;
}

void main(){
    int S, R;
    scanf("%d %d", &S, &R);
    //printf("%d %d", S, R);
    int ar[S];
    for(int i = 0; i<S; i++)
    {
        //printf("%d", i);
        scanf("%d", &ar[i]);
        
    }

    int result[R];

    for(int i = 0; i<R; i++)
    {
        int r1, r2;
        scanf("%d %d", &r1, &r2);
        result[i]=countSamples(S, ar, r1, r2);
    }

    for(int i = 0; i<R; i++)
    {
        printf("%d ", result[i]);
    }
}