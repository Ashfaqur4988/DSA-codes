#include <iostream>
using namespace std;

bool isPossible(int arr[], int students, int books, int m)
{
    int studentCount = 1;
    int pageSum = 0;

    for (int i = 0; i < books; i++)
    {
        if (pageSum + arr[i] <= m)
        {
            pageSum = pageSum + arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > students || arr[i] > m)
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}

int allocation(int arr[], int students, int books)
{
    int s = 0;
    int sum = 0;
    for (int i; i < books; i++)
    {
        sum = sum + arr[i];
    }
    int e = sum;
    int m = s + (e - s) / 2;
    int ans = -1;

    while (s <= e)
    {
        if (isPossible(arr, students, books, m))
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
        m = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int books = 4;
    int arr[books] = {10, 20, 30, 40};
    int students = 2;

    int ans = allocation(arr, students, books);
    cout << ans << endl;

    return 0;
}