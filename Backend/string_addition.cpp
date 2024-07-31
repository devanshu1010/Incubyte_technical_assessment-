#include<bits/stdc++.h>
using namespace std;

vector<string> getStrings(string& str, string& delimiter) {
    vector<string> strings;
    string token;
    int start = 0;
    int delimiterLength = delimiter.length();
    int end = 0;
    int n = str.length();

    while (end < n - delimiterLength) {
        
        // Find the delimiter in the string from start
        if (str.compare(end, delimiterLength, delimiter) == 0) {
            
            // Add the token (substring before the delimiter) to the result
            strings.push_back(str.substr(start, end - start - delimiterLength + 1));
            
            // Move `start` to the position after the delimiter
            start = end + 1;

            // incrementing end to point next
            end++;
        } else {
            end++;
        }
    }
    
    // Add the last token after the last delimiter
    strings.push_back(str.substr(start));

    return strings; // returning all separated string numbers
}

vector<string> splitByNewline(vector<string>& tokens) {
    vector<string> result;
    
    for (const auto& token : tokens) {
        int start = 0;
        int end = 0;

        int n = token.length();

        while(end < n)
        {
            if(token[end] == '\n') // if we find '\n' which we have to eliminate 
            {
                result.push_back(token.substr(start, end - start));// adding string number which is before '\n'
                start = end + 1;
            }
            end++;
        }
        
        // Add the last part after the last newline, if any
        result.push_back(token.substr(start));
    }
    
    return result;
}

int addStrings(vector<string>& strings)
{
    int sum = 0;
    vector<int> negativeNumbers; // to store negative numbers

    for (const auto& token : strings) {
        if (token.empty()) continue;

        try
        {
            int num = stoi(token);// converting string to int
            if (num < 0) {
                throw num; // negative number found
            } else {
                sum += num;
            }
            
        }
        catch(int num)
        {
            negativeNumbers.push_back(num);
        }
        
    }

    if (!negativeNumbers.empty()) {
        cout << "negative numbers not allowed : ";

        for(int i : negativeNumbers)
        {
            cout << i << ", ";
        }
        cout << endl;
    }

    return sum;
}

int stringAdditon(string numbers)
{
    int n = numbers.length(); // Getting the length of the n 
    // cout << n << endl;
    if(n == 0)
        return 0; // Handling Test Case :1 ""
    
    int sum =0; // Initializing sum with 0(zero)
    string delimiter = ",";

    string nums = numbers;

    if(numbers.substr(0, 2) == "//") // checking if we are changing delimeter or not
    {
        auto DelimiterPosition = numbers.find("\n");
        delimiter = numbers.substr(2, DelimiterPosition - 2);
        nums = numbers.substr(DelimiterPosition + 1);
    }

    vector<string> strings = getStrings(nums,delimiter); //separating all string numbers w.r.t. delimeter 

    vector<string> s = splitByNewline(strings); // removing and separating '\n' from string numbers 
    sum = addStrings(s); // finding sum of all string numbers

    return sum; // returning int sum (Addition of all numbers)
}

int main()
{
    string numbers,line,input;

    cout << "Enter string for which you want to do addition : ";

    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        input += line + "\n";  
    }

    // Remove unnecessary newline if any
    if (!input.empty() && input.back() == '\n') {
        input.pop_back();
    }
    
    // input = "12,2,3";
    // cout << "input " << input << endl;
    int result = stringAdditon(input);
    cout << "Sum: " << result <<  endl;
    // cout << "Sum of the string : " << sum << endl; // printing answer of function

    
    return 0;


}