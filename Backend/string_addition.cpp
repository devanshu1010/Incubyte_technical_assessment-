#include<bits/stdc++.h>
using namespace std;

int stringAdditon(string numbers)
{
    int n = numbers.length(); // Getting the length of the n 

    if(n == 0)
        return 0; // Handling Test Case :1 ""

    int sum =0; // Initializing sum with 0(zero)
    char delimiter = ',';
    
    if(n >= 5)
    {
        //;\n1
        cout << numbers[3]  << endl;
        if(numbers[0] == '/'&& numbers[1] == '/' && !(numbers[2] >= '0' && numbers[2]<='9') && numbers[3] == '\\' && numbers[4] =='n' && (numbers[5] >= '0' && numbers[5]<='9') )
        {
            delimiter = numbers[2];
            cout << "delimeter changed : "<<delimiter << endl;
        }
    }

    vector<int> negative_num;

    for(int i = 0 ;i< n ;i++)
    {
        try
        {
            int j =i;
            string temp = "";
            while ( numbers[i] != delimiter && numbers[j] >= '0' && numbers[j]<='9')
            {
                temp += numbers[j];
                j++;
                i = j-1;
            }
            
            if(temp != "") // Allowing only 0-9 in the block for addition
            {
                sum += stoi(temp); // converting string to int
            }
            else if(numbers[i] == '-')
            {
                throw (numbers[i+1] - '0');
            }
            

        }
        catch(int num)
        {
            negative_num.push_back(num);
            i++;
        }
        
    }

    int size = negative_num.size();

    if(size>0)
    {
        cout << "negative numbers not allowed : ";

        for(int i : negative_num)
        {
            cout << "-"<< i << ",";
        }
        cout << endl;
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