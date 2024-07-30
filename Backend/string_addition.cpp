#include<bits/stdc++.h>
using namespace std;

int stringAdditon(string numbers)
{
    int n = numbers.length(); // Getting the length of the n 

    if(n == 0)
        return 0; // Handling Test Case :1 ""

    int sum =0; // Initializing sum with 0(zero)

    for(int i = 0 ;i< n ;i++)
    {
        if(numbers[i] >= '0' && numbers[i]<='9') // Allowing only 0-9 in the block for addition
        {
            sum += numbers[i] - '0'; // converting char to int
        }
    }

    return sum; // returning int sum (Addition of all numbers)
}

int main()
{
    string numbers;

    cout << "Enter string for which you want to do addition : ";
    cin >> numbers; // Taking input from the user

    int sum = stringAdditon(numbers); // calling function

    cout << "Sum of the string : " << sum << endl; // printing answer of function
    return 0;
}