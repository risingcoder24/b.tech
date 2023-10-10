#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>  // Include for std::istringstream

std::vector<std::string> englishWords;

void loadEnglishWords() {
    std::ifstream wordFile("english_words.txt");
    std::string word;

    while (std::getline(wordFile, word)) {
        englishWords.push_back(word);
    }
}

std::string caesar_decrypt(std::string ciphertext, int shift) {
    std::string decryptedText = "";
    
    for (char charIn : ciphertext) {
        if (std::isalpha(charIn)) {
            char asciiOffset = std::islower(charIn) ? 'a' : 'A';
            char decryptedChar = (char)((charIn - asciiOffset - shift + 26) % 26 + asciiOffset);
            decryptedText += decryptedChar;
        } else {
            decryptedText += charIn;
        }
    }
    
    return decryptedText;
}

bool isMeaningfulWord(std::string word) {
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    return std::find(englishWords.begin(), englishWords.end(), word) != englishWords.end();
}

std::string decryptWithMeaningfulText(std::string ciphertext) {
    for (int shift = 0; shift < 26; ++shift) {
        std::string decryptedText = caesar_decrypt(ciphertext, shift);
        std::istringstream iss(decryptedText);
        std::string word;
        bool allWordsAreMeaningful = true;
        
        while (iss >> word) {
            if (!isMeaningfulWord(word)) {
                allWordsAreMeaningful = false;
                break;
            }
        }

        if (allWordsAreMeaningful) {
            return decryptedText;
        }
    }
    
    return "";
}

int main() {
    loadEnglishWords();
    
    std::string encryptedText = "KGVT";
    std::string decryptedAnswer = decryptWithMeaningfulText(encryptedText);

    if (!decryptedAnswer.empty()) {
        std::cout << "\nDecrypted answer: " << decryptedAnswer << "\n\n";
    } else {
        std::cout << "No valid decryption found.\n";
    }

    return 0;
}
