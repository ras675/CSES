#include <iostream>
#include <string>
using namespace std;

int main() {
    string sequence;
    cin >> sequence;

    int max_repetition = 1; // At least one character exists
    int current_repetition = 1;

    // Iterate through the sequence to find repetitions
    for (int i = 1; i < sequence.length(); ++i) {
        // If the current character is the same as the previous one, increase repetition count
        if (sequence[i] == sequence[i - 1]) {
            current_repetition++;
            // Update max_repetition if the current repetition is longer
            if (current_repetition > max_repetition) {
                max_repetition = current_repetition;
            }
        } else {
            // Reset current repetition count if the current character is different
            current_repetition = 1;
        }
    }

    cout << max_repetition << endl;

    return 0;
}
