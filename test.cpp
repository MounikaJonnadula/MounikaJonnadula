#include <deepstate/DeepState.hpp>
#include "hungman.h"

using namespace deepstate;

// Function to generate a random secret word for testing
std::string generateRandomSecretWord() {
    const size_t maxLength = MAX_FRUIT_SIZE; // Assuming MAX_FRUIT_SIZE is defined in your header
    return DeepState_CStrUpToLen(maxLength);
}

// Test case for checkGuess function
TEST(HangmanLib, CheckGuess) {
    std::string secretWord = generateRandomSecretWord();
    
    // Test correct guess
    ASSERT_TRUE(checkGuess(secretWord[0], secretWord));
}

// Test case for fillOutputArray function
TEST(HangmanLib, FillOutputArray) {
    std::string secretWord = generateRandomSecretWord();
    std::string outputArray(secretWord.length(), '_');

    // Test filling output array with correct guess
    fillOutputArray(secretWord[0], secretWord, outputArray);
    ASSERT_EQ(secretWord[0], outputArray[0]);
}

// Test case for fillAttemptsArray function
TEST(HangmanLib, FillAttemptsArray) {
    std::string attempts = buildAttemptArray(1); // Easy difficulty
    
    // Test filling attempts array
    ASSERT_TRUE(fillAttemptsArray('a', attempts));
    
    // Test reaching maximum attempts
    for (int i = 0; i < ATTEMPTS_EASY - 1; ++i) { // One less than maximum attempts
        ASSERT_TRUE(fillAttemptsArray('a' + i, attempts));
    }
    ASSERT_FALSE(fillAttemptsArray('z', attempts));
}

// Test case for checkDefeat function
TEST(HangmanLib, CheckDefeat) {
    std::string attempts = "*****";

    // Test initial state
    ASSERT_FALSE(checkDefeat(attempts));

    // Test after using all attempts
    attempts = "aaaaaa"; // Max attempts reached
    ASSERT_TRUE(checkDefeat(attempts));
}

// Test case for secret word length
TEST(HangmanLib, SecretWordLength) {
    std::string secretWord = generateRandomSecretWord();
    ASSERT_LE(secretWord.length(), MAX_FRUIT_SIZE);
    ASSERT_GE(secretWord.length(), 1);
}

