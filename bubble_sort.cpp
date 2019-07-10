#include <iostream>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>

std::vector<int> GenerateRandVec(int numberOfNums, int min, int max);
void BubbleSort(std::vector<int>& theVec);
std::string CaesarCipher(std::string theString, int key, bool encrypt);
void SolveForX(std::string equation);
std::vector<std::string> SplitStringToVector(std::string splitMe);
bool IsPrime(int num);
std::vector<int> GetPrimes(int num);


int main() {
    std::vector<int> values = GenerateRandVec(10, 5, 50);
    for(int x : values)
    {
        std::cout << x << "\n";
    }
    BubbleSort(values);
    std::cout << "And now sorted:" << "\n";
    for(int x : values)
    {
        std::cout << x << "\n";
    }


    std::string theString = "Make me secret";
    std::string encryptedStr = CaesarCipher(theString, 5, true);
    std::string decryptedString = CaesarCipher(encryptedStr, 5, false);
    std::cout << "Encrypted " << encryptedStr << "\n";
    std::cout << "Decrypted " << decryptedString << "\n";

    std::cout << "Enter an equation to solve ";
    std::string equation = "";
    getline(std::cin, equation);
    SolveForX(equation);

    int num = 0;
    std::cout << "Number to Check: ";
    std::cin >> num;
    std::cout.setf(std::ios::boolalpha);
    std::cout << "Is " << num << " Prime? " << IsPrime(num) << "\n";

    std::cout << "Generate Primes up to ";
    int maxPrime;
    std::cin >> maxPrime;
    std::vector<int> primeList = GetPrimes(maxPrime);
    for(int x : primeList)
    {
        std::cout << x << "\n";
    }

    return 0;
}

std::vector<int> GenerateRandVec(int numberOfNums, int min, int max)
{
    std::vector<int> result;
    // seed our rand()
    srand(time(NULL));

    int i = 0, randVal = 0;

    while(i < numberOfNums)
    {
        // here we call our rand using the seeded range provided above
        randVal = min + std::rand() % ((max + 1) - min);
        result.push_back(randVal);
        ++i;
    }
    return result;
}

void BubbleSort(std::vector<int>& theVec)
{
    int i = theVec.size() -1;
    while(i >= 1)
    {
        int j = 0;
        while(j < i)
        {

            if(theVec[j] >= theVec[j + 1])
            {
                int temp = theVec[j];
                theVec[j] = theVec[j + 1];
                theVec[j+1] = temp;
            }

            ++j;
        }
        --i;

    }
}

std::string CaesarCipher(std::string theString, int key, bool encrypt)
{
    std::string returnString = "";
    int charCode = 0;
    char letter;

    if(encrypt) key = key * -1;

    for(char& c: theString)
    {
        if(isalpha(c))
        {
            charCode = (int)c;
            charCode += key;

            if(isupper(c))
            {
                if(charCode > (int)'Z')
                {
                    charCode -= 26;
                } else if(charCode < (int)'A')
                {
                    charCode += 26;
                }
            } else {
                if(charCode > (int)'z')
                {
                    charCode -= 26;
                } else if(charCode < (int)'a')
                {
                    charCode += 26;
                }
            }
            letter = charCode;
            returnString += letter;
        } else
        {
            letter = c;
            returnString += letter;
        }
    }
    return returnString;
}

// this function is easy, but splitting a string is kind of tough, turns out
void SolveForX(std::string equation)
{
    std::vector<std::string> vecEquation = SplitStringToVector(equation);
    int x = std::stoi(vecEquation[2]);
    int y = std::stoi(vecEquation[4]);

    int xVal = y - x;
    std::cout << "x = " << xVal << "\n";
}

// iterate over each char and check if it is a delimiter (space, here)
std::vector<std::string> SplitStringToVector(std::string splitMe)
{
    std::string word = "";
    std::vector<std::string> result;
    for(char x : splitMe)
    {
        if(x == ' ') {
            result.push_back(word);
            word = "";
        } else
        {
            word = word + x;
        }
    }
    result.push_back(word);
    return result;
}

bool IsPrime(int num)
{
    if(num < 0)
    {
        return false;
    }

    if(num == 1)
    {
        return true;
    }

    int i = 2;
    for(i; i < num; i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }

    return true;
}

// has to be a vector, since we won't know the size of the output
std::vector<int> GetPrimes(int num)
{
    std::vector<int> v;
    for(int i = 1; i < num; i++)
    {
        if(IsPrime(i))
        {
            v.push_back(i);
        }

    }
    return v;
}
