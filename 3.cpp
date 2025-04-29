#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n - i; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}
void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {3, 2, 8, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    printarr(arr, n);
}