/*You have been given an array/list 'ARR' consisting of 'N' integers. 
Your task is to find the majority element in the array. If there is no majority element present, print -1.
Note:
A majority element is an element that occurs more than floor('N' / 2) times in the array.*/
#include <bits/stdc++.h>

int findMajorityElement(int a[], int n) {
	// Write your code here.
	int count = 0, i, majorityElement;
        for (i = 0; i < n; i++) {
           if (count == 0)
              majorityElement = a[i];
           if (a[i] == majorityElement) 
                count++;
           else
              count--;
    }
    count = 0;
    for (i = 0; i < n; i++)
        if (a[i] == majorityElement)
            count++;
        if (count > n/2)
           return majorityElement;
    return -1;


}