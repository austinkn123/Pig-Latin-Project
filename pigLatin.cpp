/**
* Austin Nguyen
* Pig Latin
* * This program converts a sentence into pig latin.
**/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;

/**
* stringToVector splits the sentence into individual words
* and stores the words into a vector of strings.
* @param sentenceWords The string which is the sentence.
* @return Returns a vector of strings which has all of the words in the sentence.
* @pre the sentence will always contain at least one word, that words in the
* sentence will always be separated by a single space, there will be no
* punctuation, and that there will be no whitespace before / after the sentence.
**/
vector<string> stringToVector(string sentenceWords);

/**
* firstVowel goes through the sentence to see if there is a vowel.
* @param vowels The string which is a sentence.
* @return Index where the vowel is, or -1 if there is no vowel.
* @pre The string must contain words.
**/
int firstVowel(string vowels);

/**
* constCounter goes through the sentence to to count the number of consonants
* before a vowel
* @param constChecker The string which is a sentence.
* @return A integer that counted the number of consts before a vowel.
* @pre The string must contain words.
**/
int constCounter(string constChecker);

/**
* firstY goes through the sentence to see if there is the letter 'Y'
* @param letterY The string which is a sentence.
* @return Index where the letter 'Y' is, or -1 if there is no 'Y'.
* @pre The string must contain words.
**/
int firstY(string letterY);

/**
* yCounter goes through the sentence to count the letters before the first 'Y'
*
* @param yChecker The string which is a sentence.
* @return A integer that counted the number letters before a 'Y'.
* @pre The string must contain words.
**/
int yCounter(string yChecker);

/**
* toPigLatin converts a english string of vectors into pig latin
* @param modStr A string of vectors.
* @return Returns a modified vector that is now pig latin.
* @pre The vector must contain strings.
**/
void toPigLatin(vector<string>& modStr);

/**
* display outputs the modified pig latin string of vectors
* @param showsVector A modified pig latin string of vectors.
* @return Returns a modified pig latin string of vectors.
* @pre The vector must contain strings.
* correctly.
**/
void display(vector<string> showsVector);

int main()
{
    vector<string> words;
    string userWords;

    getline(cin, userWords);

    stringToVector(userWords);

    words = stringToVector(userWords);

    toPigLatin(words);

    display(words);

    return 0;
}
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

/**
* Austin Nguyen
* Pig Latin
* * This program converts a sentence into pig latin.
**/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstdlib>
using namespace std;


vector<string> stringToVector(string sentenceWords);
int firstVowel(string vowels);
int constCounter(string constChecker);
int firstY(string letterY);
int yCounter(string yChecker);
void toPigLatin(vector<string>& modStr);
void display(vector<string> showsVector);

int main()
{
    vector<string> words;
    string userWords;

    getline(cin, userWords);

    cout << userWords << endl;

    stringToVector(userWords);

    words = stringToVector(userWords);

    toPigLatin(words);




    return 0;
}

vector<string> stringToVector(string sentenceWords)
{
    vector<string> stringVector;
    string wordTest = "";
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
    for (int i = 0; i < letterY.size(); i++)
    {
        if ((letterY.at(i) == 'y') || (letterY.at(i) == 'Y'))
        {
            return i;
        }
    }

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
        if (firstVowel(modStr.at(i)) == 0)
        {
            modStr.at(i) = modStr.at(i) + "-yay";
        }
        else if (firstY(modStr.at(i)) == 0)
        {
            modStr.at(i) = modStr.at(i) + "-" + modStr.at(i).substr(0, yCounter(modStr.at(i)) + 1) + "ay";
            modStr.at(i).replace(0, 1, "");
        }
        else if ((firstVowel(modStr.at(i)) == -1) || (constCounter(modStr.at(i)) < yCounter(modStr.at(i))))
        {
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
    display(modStr);
}

void display(vector<string> showsVector)
{
    for (int i = 0; i < showsVector.size() - 1; i++)
    {
        cout << showsVector.at(i) << " ";
    }

    cout << showsVector.at(showsVector.size() - 1) << endl;
}