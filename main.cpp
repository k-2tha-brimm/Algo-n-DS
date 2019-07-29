#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

int Factorial(int number);
int Fib(int number);
void PrintVec(std::vector<int>& vector);

int main() {

    std::vector<int> theVec = {10, 8, 2, 5, 9, 11, 6, 14};
    PrintVec(theVec);

    std::cout << "Factorial of 3 is " << Factorial(3) << "\n";

    std::cout << "Fib of 8 is " << Fib(8) << "\n";

    return 0;
}

int Factorial(int number)
{
    if(number == 1)
    {
        return 1;
    }
    else
    {
        int result = number * Factorial(number - 1);
        return result;
    }
}

int Fib(int number)
{
    int f[number + 1];
    int i;

    f[0] = 0;
    f[1] = 1;

    for(i = 2; i <=number; ++i)
    {
        f[i] = f[i - 1] + f[i - 2];
    }

    return f[number];
}

void PrintVec(std::vector<int>& vector)
{
    for(int i = 0; i < vector.size(); ++i)
    {
        printf("| %2d ", i);
    }
    std::cout << "|\n";
    for(int i = 0; i < vector.size(); ++i)
    {
        printf("| %2d ", vector[i]);
    }
    std::cout << "|\n";
}

// “AABAACAABAA”
// lps = [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5], len = 4, i = 9     pat[i] = A, pat[len] = A


void ComputeLPSArray(char* pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;

    // the first value of the array is ALWAYS 0
    lps[0] = 0;

    int i = 1;
    while(i < M)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else  // (pat[i] != pat[len])
        {
            if(len != 0)
            {
                len = lps[len-1];

                // we do not increment i here... why is that?
                // let's step through.
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}