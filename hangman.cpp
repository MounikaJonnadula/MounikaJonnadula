
#include"hungman.h"

// Function to initialize the random number generator
void initializeRandom() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Function to get a random secret word and return its length
int getSecretWord(std::string& secretWord) {
    int index = std::rand() % FRUITS_LEN;
    secretWord = FRUITS[index];
    return secretWord.length();
}

// Function to initialize the output array with underscores
void buildOutputArray(int size, std::string& outputArray) {
    outputArray.assign(size, '_');
}

// Function to dynamically allocate and initialize the attempts array
std::string buildAttemptArray(int difficulty) {
    switch (difficulty) {
        case 1:
            return std::string(ATTEMPTS_EASY, '*');
        case 2:
            return std::string(ATTEMPTS_MEDIUM, '*');
        case 3:
            return std::string(ATTEMPTS_HARD, '*');
        default:
            return std::string(ATTEMPTS_MEDIUM, '*'); // Default to medium difficulty
    }
}

// Function to check if a guessed letter is in the secret word
bool checkGuess(char guess, const std::string& secretWord) {
    return secretWord.find(tolower(guess)) != std::string::npos;
}

// Function to fill in the output array with the guessed letter
bool fillOutputArray(char guess, const std::string& secretWord, std::string& outputArray) {
    bool filled = false;
    for (size_t i = 0; i < secretWord.length(); ++i) {
        if (tolower(secretWord[i]) == tolower(guess) && outputArray[i] == '_') {
            outputArray[i] = secretWord[i];
            filled = true;
        }
    }
    return filled;
}

// Function to fill in the attempts array with the guessed letter
bool fillAttemptsArray(char guess, std::string& attempts) {
    for (size_t i = 0; i < attempts.length(); ++i) {
        if (attempts[i] == '*') {
            attempts[i] = guess;
            return true;
        }
    }
    return false;
}

// Function to check if the player has won the game
bool checkVictory(const std::string& outputArray) {
    return outputArray.find('_') == std::string::npos;
}

// Function to check if the player has lost the game
bool checkDefeat(const std::string& attempts) {
    return attempts.find('*') == std::string::npos;
}

// Function to display Hangman diagram based on incorrect guesses
void displayHangman(int incorrectGuesses) {
    switch (incorrectGuesses) {
        case 0:
            std::cout << "  _________     \n";
            std::cout << " |/        |    \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << "|__          \n";
            break;
        case 1:
            std::cout << "  _________     \n";
            std::cout << " |/        |    \n";
            std::cout << " |        (_)   \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << "|__          \n";
            break;
        case 2:
            std::cout << "  _________     \n";
            std::cout << " |/        |    \n";
            std::cout << " |        (_)   \n";
            std::cout << " |         |    \n";
            std::cout << " |         |    \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << "|__          \n";
            break;
        case 3:
            std::cout << "  _________     \n";
            std::cout << " |/        |    \n";
            std::cout << " |        (_)   \n";
            std::cout << " |        \\|    \n";
            std::cout << " |         |    \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << "|__          \n";
            break;
        case 4:
            std::cout << "  _________     \n";
            std::cout << " |/        |    \n";
            std::cout << " |        (_)   \n";
            std::cout << " |        \\|/  \n";
            std::cout << " |         |    \n";
            std::cout << " |             \n";
            std::cout << " |             \n";
            std::cout << "|__          \n";
            break;
        case 5:
            std::cout << "  _________     \n";
            std::cout << " |/        |    \n";
            std::cout << " |        (_)   \n";
            std::cout << " |        \\|/  \n";
            std::cout << " |         |    \n";
            std::cout << " |        /    \n";
            std::cout << " |             \n";
            std::cout << "|__          \n";
            break;
        case 6:
            std::cout << "  _________     \n";
            std::cout << " |/        |    \n";
            std::cout << " |        (_)   \n";
            std::cout << " |        \\|/  \n";
            std::cout << " |         |    \n";
            std::cout << " |        / \\  \n";
            std::cout << " |             \n";
            std::cout << "|__          \n";
            break;
    }
}

// Function to play the Hangman game
void playHangman(const std::vector<std::string>& playerNames) {
    // Initialize the random number generator based on the system's current time
    initializeRandom();

    // Vector to store scores of players
    std::vector<int> scores(playerNames.size(), 0);

    // Main game loop
    bool playAgain = true;
    while (playAgain) {
        // Welcome message
        std::cout << "Welcome to Hangman!\n";

        // Difficulty level selection
        std::cout << "\nSelect Difficulty Level:\n";
        std::cout << "1. Easy\n";
        std::cout << "2. Medium\n";
        std::cout << "3. Hard\n";
        int difficulty;
        std::cin >> difficulty;

        while (difficulty < 1 || difficulty > 3) {
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> difficulty;
        }

        // Loop through each player
        for (const std::string& playerName : playerNames) {
            std::cout << "\nPlayer " << playerName << "'s turn!\n";

            // Get a random secret word and its length
            std::string secretWord;
            int wordLength = getSecretWord(secretWord);

            // Build output array and attempts array
            std::string outputArray(wordLength, '_');
            std::string attempts = buildAttemptArray(difficulty);

            // Hangman diagram variables
            int incorrectGuesses = 0;

            // Display number of letters in the secret word
            std::cout << "Number of Letters: " << wordLength << "\n";

            // Main gameplay loop
            while (!checkVictory(outputArray) && !checkDefeat(attempts)) {
                // Display current game state and Hangman diagram
                std::cout << "\nSecret Word: " << outputArray << '\n';
                std::cout << "Attempts Left: " << attempts << '\n';
                displayHangman(incorrectGuesses);

                // Player guesses a letter
                std::cout << "Guess a letter: ";
                char guess;
                std::cin >> guess;

                // Validate the guess
                while (!isalpha(guess)) {
                    std::cout << "Invalid input. Please enter a letter.\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> guess;
                }

                // Check if the guess is correct
                if (checkGuess(guess, secretWord)) {
                    std::cout << "Correct guess!\n";
                    if (!fillOutputArray(guess, secretWord, outputArray)) {
                        std::cout << "You've already guessed that letter.\n";
                    }
                } else {
                    std::cout << "Incorrect guess!\n";
                    if (!fillAttemptsArray(guess, attempts)) {
                        std::cout << "You've already used all your attempts!\n";
                    }
                    incorrectGuesses++;
                }
            }

            // End of game
            if (checkVictory(outputArray)) {
                std::cout << "\nCongratulations, " << playerName << ", you've won!\n";
                scores[&playerName - &playerNames[0]]++;
            } else {
                std::cout << "\nSorry, " << playerName << ", you've lost. The secret word was: " << secretWord << '\n';
            }
        }

        // Display scores
        std::cout << "\nCurrent Scores:\n";
        for (size_t i = 0; i < playerNames.size(); ++i) {
            std::cout << "Player " << playerNames[i] << ": " << scores[i] << '\n';
        }

        // Ask if players want to play again
        char playAgainChoice;
        std::cout << "\nDo you want to play again? (y/n): ";
        std::cin >> playAgainChoice;
        playAgain = (playAgainChoice == 'y' || playAgainChoice == 'Y');
    }

    std::cout << "\nThanks for playing Hangman!\n";
}

/*
int main() {
    // Vector of player names
    std::vector<std::string> playerNames = {"Alice", "Bob", "Charlie"};

    // Call the playHangman function to start the game
    playHangman(playerNames);

    return 0;
}*/