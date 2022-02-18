#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

int locateMaximum(const string array[], int n)
{

    if (n <= 0)
        return -1;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] > array[max]) // makes int max take on the value of i if array i > array max as it goes throught the loop
            max = i;
    }
    return max;
}

int countFloatingPointValues(const string array[], int n)
{
    if (n <= 0)
        return -1;
    int value = 0;
    // string a = array[n];
    for (int i = 0; i < n; i++)
    {                            // checks all elements within the array, grabs one string
        string check = array[i]; // check is assigned the value of i as it goes through the loop

        bool isFloat = true; // checks all of the characters within the strings, sets a condition
        int amountdecimals = 0;
        for (int j = 0; j < check.size(); j++)
        { // checks each character within the string
            if (!(isdigit(check[j])) && check[j] != '.')
            {
                isFloat = false;
            }
            if (check[j] == '.' && check[j + 1] == '.')
            {
                isFloat = false;
            }
            if (check[j] == '.')
            {
                amountdecimals = amountdecimals + 1;
                if (amountdecimals >= 2)
                {
                    isFloat = false;
                }
            }

            /*if (isdigit(check[i])) {
                value = value + 1;
            }
            else if ('.') {
                value = value + 1;
            }*/
        }
        if (isFloat == true)
        { // if previous condition is not met
            value = value + 1;
        }
    }
    return value;
}

bool hasNoCapitals(const string array[], int n)
{
    if (n <= 0)
        return true;
    for (int i = 0; i < n; i++)
    { // checks each element within the array
        string check = array[i];
        for (int j = 0; j < check.size(); j++)
        { // checks each character within the string
            if (isupper(check[j]))
            {
                return false;
            }
        }
    }
    return true;
}

int shiftLeft(string array[], int n, int amount, string placeholder)
{
    if (n <= 0)
    {
        return -1;
    }
    if (amount < 0)
    {
        return -1;
    }
    int usesplaceholder = 0;
    if (amount > n || amount == n)
    {
        for (int i = 0; i < n; i++)
        {
            array[i] = placeholder;
            usesplaceholder = usesplaceholder + 1;
        }
    }

    if (amount < n)
    {
        for (int i = 0; i < n; i++)
        {
            array[i] = array[i + amount];
        }

        for (int j = 0; j < amount; j++)
        {
            array[n - 1 - j] = placeholder;
            usesplaceholder = usesplaceholder + 1;
        }
    }

    return usesplaceholder;
}

int main()
{
    cout << "hopefully I get an A in CS31!" << endl;

return 0;

}