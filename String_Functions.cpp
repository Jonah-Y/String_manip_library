#include <cstring>
#include <cctype>
#include <string>
#include <string.h>
#include <unordered_map>
#include <iostream>

using namespace std;

// Capitalize the first letter of every sentence
char* sentenceCapitalizer(char *sentence) {
    // create a temp and copy the argument to it
    char *temp = new char[strlen(sentence) + 1];
    strcpy(temp, sentence);

    // cycle through temp
    for (int i = 0; i < strlen(temp); ++i) {
        // if period followed by space then capitalize the next letter
        if (temp[i] == '.' && temp[i+1] == ' ') {
            i += 2;
            // increment past any extra spaces then capitalize
            while (isspace(temp[i])) ++i;
            temp[i] = toupper(temp[i]);
        }
    }
    return temp;
}

// Returns a string object of the char(s) that were most frequently used in the parameter
string mostFrequentChar(char* str) {
    unordered_map<char, int> listOfChars = {{str[0], 1}};
    int highestOccurrence = 0;
    string mostFrequent = "";
    
    // cycle through the string and update listOfChars with the count of each char
    for (int i = 1; i < strlen(str); ++i) {
        if (listOfChars.count(str[i])) listOfChars[str[i]]++;
        else listOfChars.insert(make_pair(str[i],1));
    }

    // find the number of occurences of the most common letter(s)
    for (auto element : listOfChars) {
        if (element.second > highestOccurrence)
            highestOccurrence = element.second;
    }

    // add all the letters tied for most common to a string
    for (auto element : listOfChars) {
        cout << element.first << element.second << endl;
        if (element.second == highestOccurrence) {
            mostFrequent += element.first;
        }
    }
    
    return mostFrequent;
}

// Convert a sentence to pig latin
char* pigLatinConverter(char *sentence) {
    char firstChar[2] = {'0', '\0'};
    char pigWord[50];
    char* word;
    //create a temp to copy the converted words to it NEED TO FIX SIZE DECISION
    char *temp = new char[strlen(sentence)*3]; // 3x the length allocated just in case
    temp[0] = '\0';

    word = strtok(sentence, " ,./!?");
    while (word != NULL) {
        // take off the first letter and add it to the back with "ay"
        firstChar[0] = word[0];
        word++;
        strcpy(pigWord, word);
        strcat(pigWord, firstChar);
        strcat(pigWord, "ay");

        // add the converted word to the temp sentence
        strcat(temp, pigWord);
        strcat(temp, " ");

        word = strtok(NULL, " ,./!?");// go to the next word
    }

    return temp;
}

// Replaces every sub1 with sub2 that is found in stringObj
string replaceSubstring(string stringObj, string sub1, string sub2) {
    int pos = 0;
    pos = stringObj.find(sub1, pos);
    while (pos >= 0) {
        stringObj.replace(pos, sub1.length(), sub2);
        ++pos;
        pos = stringObj.find(sub1, pos);
    }
    return stringObj;
}