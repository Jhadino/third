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

    for (int = 1; i < 4; i++) {
        int digit;
        do {
            digit = rand() % 10;
        } while (used[digit]);
        secret += to_string(digit);
        used[digit] = true;
    }
        return secret
}
