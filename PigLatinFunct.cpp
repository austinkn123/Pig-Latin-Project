#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "PigLatinFunct.h"
using namespace std;

vector<string> stringToVector(string sentenceWords)
{
    vector<string> stringVector;
    string wordTest = "";
    //This for loop separates a sentence into a string of vectors
    for (int i = 0; i < sentenceWords.length(); i++)
    {
        if (sentenceWords.at(i) != ' ')
        {
            wordTest += sentenceWords.at(i);
        }
        else if (sentenceWords.at(i) == ' ')
        {
            stringVector.push_back(wordTest);
            wordTest = "";
        }
        if (i == (sentenceWords.length() - 1))
        {
            stringVector.push_back(wordTest);
        }
    }

    return stringVector;
}

int firstVowel(string vowels)
{
    int count = 0;
    //This for loop returns the index of the first vowel, if there is no vowel it returns -1
    for (int i = 0; i < vowels.size(); i++)
    {
        if ((vowels.at(i) == 'a') || (vowels.at(i) == 'e') || (vowels.at(i) == 'i') || (vowels.at(i) == 'o') || (vowels.at(i) == 'u') || (vowels.at(i) == 'A') || (vowels.at(i) == 'E') || (vowels.at(i) == 'I') || (vowels.at(i) == 'O') || (vowels.at(i) == 'U'))
        {
            count = i;
            break;
        }
        else
        {
            count = -1;
        }
    }
    return count;
}

int constCounter(string constChecker)
{
    //This for loop counts the consonants before a vowel
    int counter = 0;
    for (int i = 0; i < constChecker.size(); i++)
    {
        if ((constChecker.at(i) == 'a') || (constChecker.at(i) == 'e') || (constChecker.at(i) == 'i') || (constChecker.at(i) == 'o') || (constChecker.at(i) == 'u') || (constChecker.at(i) == 'A') || (constChecker.at(i) == 'E') || (constChecker.at(i) == 'I') || (constChecker.at(i) == 'O') || (constChecker.at(i) == 'U'))
        {
            break;
        }
        else
        {
            counter++;
        }
    }
    return counter;
}

int firstY(string letterY)
{
    //This for loop sees if there is a 'y'
    for (int i = 0; i < letterY.size(); i++)
    {
        if ((letterY.at(i) == 'y') || (letterY.at(i) == 'Y'))
        {
            return i;
        }
    }

    //This for loop returns -1 if there is no 'y'
    for (int i = 0; i < letterY.size(); i++)
    {
        if ((letterY.at(i) != 'y') || (letterY.at(i) != 'Y'))
        {
            return -1;
        }
    }

}

int yCounter(string yChecker)
{
    int yCount = 0;
    //This for loop counts the letters before 'y'
    for (int i = 0; i < yChecker.size(); i++)
    {
        if ((yChecker.at(i) == 'y') || (yChecker.at(i) == 'Y'))
        {
            break;
        }
        else
        {
            yCount++;
        }
    }
    return yCount;
}

void toPigLatin(vector<string>& modStr)
{

    for (int i = 0; i < modStr.size(); i++)
    {
        //Checks of the word starts with a vowel
        if (firstVowel(modStr.at(i)) == 0)
        {
            modStr.at(i) = modStr.at(i) + "-yay";
        }
        //Checks if the word starts with a 'y'
        else if (firstY(modStr.at(i)) == 0)
        {
            modStr.at(i) = modStr.at(i) + "-" + modStr.at(i).substr(0, yCounter(modStr.at(i)) + 1) + "ay";
            modStr.at(i).replace(0, 1, "");
        }
        //Checks for consonant rule
        else if ((firstVowel(modStr.at(i)) == -1) || (constCounter(modStr.at(i)) < yCounter(modStr.at(i))))
        {
            //Checks the special rule for 'y', if it doesn't apply, follow the previous if-else statement
            if ((firstY(modStr.at(i)) >= 1) && (yCounter(modStr.at(i)) < constCounter(modStr.at(i))))
            {
                modStr.at(i) = modStr.at(i) + "-" + modStr.at(i).substr(0, yCounter(modStr.at(i))) + "ay";
                modStr.at(i).replace(0, yCounter(modStr.at(i)), "");
                continue;
            }
            modStr.at(i) = modStr.at(i) + "-" + modStr.at(i).substr(0, constCounter(modStr.at(i))) + "ay";
            modStr.at(i).replace(0, constCounter(modStr.at(i)), "");

        }
    }
}

void display(vector<string> showsVector)
{
    //This for loop outputs the modified vector
    for (int i = 0; i < showsVector.size() - 1; i++)
    {
        cout << showsVector.at(i) << " ";
    }
    cout << showsVector.at(showsVector.size() - 1) << endl;
}