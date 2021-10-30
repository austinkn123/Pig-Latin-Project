/**
* Austin Nguyen
* Pig Latin
* * This program converts a sentence into pig latin.
**/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "PigLatinFunct.h"
using namespace std;


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

