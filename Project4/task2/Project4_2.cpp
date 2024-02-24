#include "DoublyLinkedBag.h"
#include <iostream>
#include <fstream>
#include <string>

void populateDictionary(DoublyLinkedBag<std::string> &dictionary, const std::string &filename)
{
    std::ifstream file(filename);
    std::string word;

    while (file >> word)
    {
        dictionary.add(word);
    }

    file.close();
}

void spellCheck(DoublyLinkedBag<std::string> &dictionary, const std::string &filename)
{
    std::ifstream file(filename);
    std::string word;
    std::vector<std::string> misspelledWords;

    while (file >> word)
    {
        if (!dictionary.contains(word))
        {
            misspelledWords.push_back(word);
        }
    }

    file.close();

    if (!misspelledWords.empty())
    {
        std::cout << "the following words in the file \"" << filename << "\" are not spelled correctly:" << std::endl;
        for (const auto &word : misspelledWords)
        {
            std::cout << word << std::endl;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No misspelled words found" << std::endl;
    }
}

int main()
{
    DoublyLinkedBag<std::string> dictionary;
    std::string dictionaryFilename = "dictionary.txt";
    populateDictionary(dictionary, dictionaryFilename);

    std::cout << "enter the name of the file that contains the word to check:" << std::endl;
    std::string fileToCheck;
    std::cin >> fileToCheck;

    spellCheck(dictionary, fileToCheck);

    std::cout << "thanks for using the spell checker system!";

    return 0;
}