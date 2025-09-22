#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

string generateSecretNumber(){
    string secret = "";
    bool used [10] = {false};
    srand(time(0));

    int firstDigit = rand() % 9 + 1;
    secret += to_string(firstDigit);
    used[firstDigit] = true;

    for (int i = 1; i < 4; i++) {
        int digit;
        do {
            digit = rand() % 10;
        } while (used[digit]);
        secret += to_string(digit);
        used[digit] = true;
    }
        return secret;
}
pair<int, int> countBAC(const string& secret, const string& guess){
    int bulls = 0;
    int cows = 0;

    for (int i = 0; i < 4; i++) {
        if (guess[i] == secret[i]) {
            bulls++;
        } else {
            for (int j = 0; j < 4; j++)
                {
                    if (i != j && guess[i] == secret[j]) {
                        cows++;
                        break;
                    }
                }
            }
    }
    return make_pair(bulls, cows);
}
bool isValidGuess(const string& guess)
{
    if (guess.length() !=4 ) return false;
    set<char> uniqueChars;
    for (char c : guess) {
        if (!isdigit(c)) return false;
        uniqueChars.insert(c);
    }
    return uniqueChars.size() == 4;
}
int main() {
    cout << "Welcome in game 'BAC'"<< endl;
    cout << " The computer ordered a 4-digit number with different numbers" << endl;
    string secret = generateSecretNumber();
    int attemps = 0;
    string guess;

    while (true) {
        cout <<"enter your guess" << endl;
        cin >> guess;
        if (!isValidGuess(guess)){
            cout << "ERROR" << endl;
            continue;
        }
        attemps++;
        auto result = countBAC(secret, guess);
        int bulls = result.first;
        int cows = result.second;

        if (bulls == 4) {
            cout << "CONGRATS YOU WIN " << secret << "For " << attemps << "attemps" << endl;
            break;



        }
        cout << bulls << "bulls and " << cows << "cows" << endl;

    }
    return 0;
}
