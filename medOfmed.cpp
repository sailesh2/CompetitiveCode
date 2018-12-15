#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
	int a[15]={4,1,2,3,-1,-2,101,123,14,155,178,100,78,89,90};
	int k=3;
    int value = 0;
    int n = a.Length;
    int c = 5;  // Constant used to divide the array into columns

    while (true)
    {

        // Extract median of medians and take it as the pivot
        int pivot = FindPivot(a, n, c);

        // Now count how many smaller and larger elements are there
        int smallerCount = 0;
        int largerCount = 0;
        CountElements(a, n, pivot, out smallerCount, out largerCount);

        // Finally, partition the array
        if (k < smallerCount)
        {
            Partition(a, ref n, pivot, true);
        }
        else if (k < n - largerCount)
        {
            value = pivot;
            break;
        }
        else
        {
            k -= n - largerCount;
            Partition(a, ref n, pivot, false);
        }

    }
    cout<<value;
    getch();
    return 0;

}

int FindPivot(int[] a, int n, int c)
{

    while (n > 1)
    {

        int pos = 0;
        int tmp = 0;

        for (int start = 0; start < n; start += c)
        {

            int end = start + c;
            if (end > n)    // Last column may have
                end = n;    // less than c elements

            // Sort the column
            for (int i = start; i < end - 1; i++)
                for (int j = i + 1; j < end; j++)
                    if (a[j] < a[i])
                    {
                        tmp = a[i];
                        a[i] = a[j];
                        a[j] = tmp;
                    }

            // Pick the column's median and promote it
            // to the beginning of the array
            end = (start + end)  2;    // Median position
            tmp = a[end];
            a[end] = a[pos];
            a[pos++] = tmp;

        }

        n = pos;    // Reduce the array and repeat recursively

    }

    return a[0];    // Last median of medians is the pivot

}

void Partition(int[] a, ref int n, int pivot, bool extractSmaller)
{
    int pos = 0;
    for (int i = 0; i < n; i++)
        if ((extractSmaller && a[i] < pivot) ||
            (!extractSmaller && a[i] > pivot))
        {
            int tmp = a[i];
            a[i] = a[pos];
            a[pos++] = tmp;
        }
    n = pos;
}
