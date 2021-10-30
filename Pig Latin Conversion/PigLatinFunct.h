#ifndef PIGLATINFUNCT_H
#define PIGLATINFUNCT_H

#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//Header title has to be the exact same as cpp function file

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


#endif // !1
