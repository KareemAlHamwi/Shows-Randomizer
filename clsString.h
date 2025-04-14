#pragma once
#include <iostream>
#include <vector>
using namespace std;

class clsString {
   private:
    string value;

   public:
    clsString() {

    };

    clsString(string value) {
        this->value = value;
    };

    void setValue(string value) {
        this->value = value;
    }

    string getValue() {
        return value;
    }

    static short countWords(std::string S1) {
        string delim = " ";  // delimiter
        short Counter = 0;
        size_t pos = 0;  // use std::string::size_type for unsigned
        string sWord;    // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = S1.find(delim)) != std::string::npos) {
            sWord = S1.substr(0, pos);  // store the word
            if (sWord != "") {
                Counter++;
            }

            // erase() until position and move to next word.
            S1.erase(0, pos + delim.length());
        }

        if (S1 != "") {
            Counter++;  // it counts the last word of the string.
        }

        return Counter;
    }

    short countWords() {
        return countWords(value);
    };

    static short length(string S1) {
        return S1.length();
    };

    short length() {
        return value.length();
    };

    static string upperFirstLetterOfEachWord(string S1) {
        bool isFirstLetter = true;

        for (size_t i = 0; i < S1.length(); i++) {
            if (S1[i] != ' ' && isFirstLetter) {
                S1[i] = toupper(S1[i]);
            }

            isFirstLetter = (S1[i] == ' ' ? true : false);
        }

        return S1;
    }

    void upperFirstLetterOfEachWord() {
        // no need to return value , this function will directly update the object value
        value = upperFirstLetterOfEachWord(value);
    }

    static string lowerFirstLetterOfEachWord(string S1) {
        bool isFirstLetter = true;

        for (size_t i = 0; i < S1.length(); i++) {
            if (S1[i] != ' ' && isFirstLetter) {
                S1[i] = tolower(S1[i]);
            }

            isFirstLetter = (S1[i] == ' ' ? true : false);
        }

        return S1;
    }

    void lowerFirstLetterOfEachWord() {
        // no need to return value , this function will directly update the object value
        value = lowerFirstLetterOfEachWord(value);
    }

    static string upperAllString(string S1) {
        for (size_t i = 0; i < S1.length(); i++) {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void upperAllString() {
        value = upperAllString(value);
    }

    static string lowerAllString(string S1) {
        for (size_t i = 0; i < S1.length(); i++) {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void lowerAllString() {
        value = lowerAllString(value);
    }

    static char invertLetterCase(char char1) {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static string invertAllLettersCase(string S1) {
        for (size_t i = 0; i < S1.length(); i++) {
            S1[i] = invertLetterCase(S1[i]);
        }
        return S1;
    }

    void invertAllLettersCase() {
        value = invertAllLettersCase(value);
    }

    enum enWhatToCount { SmallLetters = 0,
                         CapitalLetters = 1,
                         All = 3 };

    static short countLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All) {
        if (WhatToCount == enWhatToCount::All) {
            return S1.length();
        }

        short Counter = 0;

        for (size_t i = 0; i < S1.length(); i++) {
            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;

            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;
        }

        return Counter;
    }

    static short countCapitalLetters(string S1) {
        short Counter = 0;

        for (size_t i = 0; i < S1.length(); i++) {
            if (isupper(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short countCapitalLetters() {
        return countCapitalLetters(value);
    }

    static short countSmallLetters(string S1) {
        short Counter = 0;

        for (size_t i = 0; i < S1.length(); i++) {
            if (islower(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short countSmallLetters() {
        return countSmallLetters(value);
    }

    static short countSpecificLetter(string S1, char Letter, bool MatchCase = true) {
        short Counter = 0;

        for (size_t i = 0; i < S1.length(); i++) {
            if (MatchCase) {
                if (S1[i] == Letter)
                    Counter++;
            } else {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }
        }

        return Counter;
    }

    short countSpecificLetter(char Letter, bool MatchCase = true) {
        return countSpecificLetter(value, Letter, MatchCase);
    }

    static bool isVowel(char Ch1) {
        Ch1 = tolower(Ch1);

        return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
    }

    static short countVowels(string S1) {
        short Counter = 0;

        for (size_t i = 0; i < S1.length(); i++) {
            if (isVowel(S1[i]))
                Counter++;
        }

        return Counter;
    }

    short countVowels() {
        return countVowels(value);
    }

    static vector<string> split(string Formate, string Delim) {
        vector<string> vString;

        size_t pos = 0;
        string sWord;  // define a string variable

        // use find() function to get the position of the delimiters
        while ((pos = Formate.find(Delim)) != std::string::npos) {
            sWord = Formate.substr(0, pos);  // store the word
            if (sWord != "") {
                vString.push_back(sWord);
            }

            Formate.erase(0, pos + Delim.length()); /* erase() until position and move to next word. */
        }

        if (Formate != "") {
            vString.push_back(Formate);  // it adds last word of the string.
        }

        return vString;
    }

    vector<string> split(string Delim) {
        return split(value, Delim);
    }

    static string trimLeft(string S1) {
        for (size_t i = 0; i < S1.length(); i++) {
            if (S1[i] != ' ') {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    void trimLeft() {
        value = trimLeft(value);
    }

    static string trimRight(string S1) {
        for (short i = S1.length() - 1; i >= 0; i--) {
            if (S1[i] != ' ') {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void trimRight() {
        value = trimRight(value);
    }

    static string trim(string S1) {
        return (trimLeft(trimRight(S1)));
    }

    void trim() {
        value = trim(value);
    }

    static string joinString(vector<string> vString, string Delim) {
        string S1 = "";

        for (string& s : vString) {
            S1 = S1 + s + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());
    }

    static string joinString(string arrString[], short Length, string Delim) {
        string S1 = "";

        for (short i = 0; i < Length; i++) {
            S1 = S1 + arrString[i] + Delim;
        }

        return S1.substr(0, S1.length() - Delim.length());
    }

    static string reverseWordsInString(string S1) {
        vector<string> vString;
        string S2 = "";

        vString = split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin()) {
            --iter;

            S2 += *iter + " ";
        }

        S2 = S2.substr(0, S2.length() - 1);  // remove last space.

        return S2;
    }

    void reverseWordsInString() {
        value = reverseWordsInString(value);
    }

    static string replaceWord(string S1, string StringToReplace, string sReplaceTo, bool MatchCase = true) {
        vector<string> vString = split(S1, " ");

        for (string& s : vString) {
            if (MatchCase) {
                if (s == StringToReplace) {
                    s = sReplaceTo;
                }

            } else {
                if (lowerAllString(s) == lowerAllString(StringToReplace)) {
                    s = sReplaceTo;
                }
            }
        }

        return joinString(vString, " ");
    }

    string replaceWord(string StringToReplace, string sReplaceTo) {
        return replaceWord(value, StringToReplace, sReplaceTo);
    }

    static string removePunctuations(string S1) {
        string S2 = "";

        for (size_t i = 0; i < S1.length(); i++) {
            if (!ispunct(S1[i])) {
                S2 += S1[i];
            }
        }

        return S2;
    }

    void removePunctuations() {
        value = removePunctuations(value);
    }
};