/*
Max = AND

Problem Statement

You are given an array A of length N. You can perform the below operation on the array A any number of times : 
Select an integer K>=1 such that there are at least 2 occurrences of K in the current array.
Replace all occurrences of K with some other integer P>=1 in the current array.
After performing operations the below condition should be satisfied by array A :
Bitwise AND of all elements of A = Maximum of all elements of A
Print “YES” if it is possible to satisfy the above condition after performing the given operation on the array any number of times, else print “NO”.

 

Input Format

•  First-line contains a single integer T, denoting the number of test cases.
•  The first line of every test case contains a single integer N, denoting the size of the array.
•  Next line of every test case contains N space-separated integers denoting the elements of array A.

Output Format
•  Print “YES” if it is possible to satisfy the above condition after performing the given operation on the array any number of times, else print “NO”.

Constraints
• 1<=T<=5
• 1<=N<=105
• 1<=Ai<=109

Sample Input
1
3
3 1 3

Sample Output
YES

Explanation of Sample

We can select K=3.
There are two occurrences of 3 in the given hence. Hence we can perform the operation.
Select P=1, and replace all occurrences of 3 in the array with 1.
Array becomes [1,1,1]

Now Bitwise AND of all elements of the array = 1
        Maximum of all elements of the array      = 1

Hence the answer is “YES’.
 */

import java.util.*;


class relevel {
    static int getCommon(int arr[]) {
        for (int i = 0; i < arr.length; i++) {
            int count = 1;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] == arr[j])
                    ++count;
            }
            if (count >= 2)
                return arr[i];
        }
        return -1;
    }

    static boolean checkIfUncommon(int arr[], int k) {
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == k)
                ++count;
        }
        if (count == 1)
            return true;
        return false;
    }

    static int[] replaceAllOccurences(int arr[], int k, int p) {
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == k)
                arr[i] = p;
        }
        return arr;
    }

    static int find_and(int arr[]) {

        int ans = arr[0];

        for (int i = 0; i < arr.length; i++) {
            ans = (ans & arr[i]);
        }
        return ans;
    }

    static int max(int arr[]) {
        int max = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < max)
                max = arr[i];
        }
        return max;
    }

    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for(int j = 0; j<t; j++)
        {
            int s = sc.nextInt();
            int arr[] = new int[s];
            for(int k = 0; k<s; k++){
                arr[k] = sc.nextInt();
            }

            int k = getCommon(arr);

            if(k!=-1){
        int p = 0;
        for (int i = 0; i < arr.length; i++) {
            if (checkIfUncommon(arr, arr[i]) == true) {
                p = arr[i];
                break;
            }
        }
        int repArr[] = replaceAllOccurences(arr, k, p);

        if(max(repArr)==find_and(repArr)) System.out.println("YES");
        else System.out.println("NO");
        }}
        
    }

}
