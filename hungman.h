#ifndef HANGMAN_H
#define HANGMAN_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <vector>
#include <limits>

#define FRUITS_LEN 104
#define ATTEMPTS_EASY 8
#define ATTEMPTS_MEDIUM 6
#define ATTEMPTS_HARD 4
#define MAX_FRUIT_SIZE 25
#define LEN_FRUITS 104

// Array of fruit names used in the Hangman game
const std::string FRUITS[104] = {"abiu",  "acai", "acerola", "akebi", "ackee", 
    "apple", "apricot", "araza", "avocado", "banana", "bilberry", "blackberry",
    "blackcurrant", "blueberry", "boysenberry", "breadfruit", "canistel",
    "cashew", "cempedak", "cherimoya", "cherry", "cloudberry", "coconut",
    "cranberry", "currant", "damson", "date", "dragonfruit", "pitaya", "durian",
    "elderberry", "feijoa", "fig", "gooseberry", "grape", "raisin",
    "grapefruit", "guava", "honeyberry", "huckleberry", "jabuticaba", "plinia",
    "jackfruit", "jambul", "jostaberry", "jujube", "kiwano", "kiwifruit",
    "kumquat", "lemon", "lime", "loganberry", "longan", "loquat", "lulo",
    "lychee", "mango", "mangosteen", "marionberry", "melon", "cantaloupe",
    "galia", "melon", "honeydew", "watermelon", "mulberry", "nance",
    "nectarine", "orange", "clementine", "mandarine", "tangerine", "papaya",
    "passionfruit", "pawpaw", "peach", "pear", "persimmon", "plantain", "plum", 
    "prune", "pineapple", "pineberry", "plumcot", "pluot", "pomegranate",
    "pomelo", "quince", "raspberry", "salmonberry", "rambutan", "redcurrant",
    "salak", "sapodilla", "sapote", "satsuma", "soursop", "strawberry",
    "tamarillo", "tamarind", "tangelo", "tayberry", "ximenia", "yuzu"};

// Array of fruit names used in the Hangman game
extern const std::string FRUITS[104];

// Function to initialize the random number generator
void initializeRandom();

// Function to get a random secret word and return its length
int getSecretWord(std::string& secretWord);

// Function to initialize the output array with underscores
void buildOutputArray(int size, std::string& outputArray);

// Function to dynamically allocate and initialize the attempts array
std::string buildAttemptArray(int difficulty);

// Function to check if a guessed letter is in the secret word
bool checkGuess(char guess, const std::string& secretWord);

// Function to fill in the output array with the guessed letter
bool fillOutputArray(char guess, const std::string& secretWord, std::string& outputArray);

// Function to fill in the attempts array with the guessed letter
bool fillAttemptsArray(char guess, std::string& attempts);

// Function to check if the player has won the game
bool checkVictory(const std::string& outputArray);

// Function to check if the player has lost the game
bool checkDefeat(const std::string& attempts);

// Function to display Hangman diagram based on incorrect guesses
void displayHangman(int incorrectGuesses);

// Function to play the Hangman game
void playHangman(const std::vector<std::string>& playerNames);

#endif // HANGMAN_H
