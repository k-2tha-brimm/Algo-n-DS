#include <iostream>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <vector>
#include <string>


void bubbleSort(std::vector<int>& theVec);
std::string CaesarCipher(std::string theString, int key, bool encrypt);
void SolveForX(std::string equation);
std::vector<std::string> SplitStringToVector(std::string splitMe);



int main() {
    std::string theString = "Make me secret";
    std::string encryptedStr = CaesarCipher(theString, 5, true);
    std::string decryptedString = CaesarCipher(encryptedStr, 5, false);
    std::cout << "Encrypted " << encryptedStr << "\n";
    std::cout << "Decrypted " << decryptedString << "\n";

//    std::cout << "Enter an equation to solve ";
//    std::string equation = "";
//    getline(std::cin, equation);
//    SolveForX(equation);
    std::vector<std::string> splitString = SplitStringToVector("Hello this is a string.");
    for(std::string x : splitString)
    {
        std::cout << x << ' ';
    }

    return 0;
}

void bubbleSort(std::vector<int>& theVec)
{
    int i = theVec.size() -1;
    while(i >= 1)
    {
        int j = 0;
        while(j < i)
        {
            printf("\nIs %d > %d\n", theVec[j], theVec[j + 1]);

            if(theVec[j] >= theVec[j + 1])
            {
                std::cout << "Switch\n";
                int temp = theVec[j];
                theVec[j] = theVec[j + 1];
                theVec[j+1] = temp;
            } else
            {
                std::cout << "Don't switch\n";
            }

            ++j;

            for(auto k: theVec)
            {
                std::cout << k << ", ";
            }
        }
        std::cout << "\nEnd of Round\n";
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

void SolveForX(std::string equation)
{

}

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

