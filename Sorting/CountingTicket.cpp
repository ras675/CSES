#include <iostream>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    multiset<int> tickets;

    // Input ticket prices
    for (int i = 0; i < n; ++i) {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    // Process customers
    for (int i = 0; i < m; ++i) {
        int max_price;
        cin >> max_price;

        // Check if there are any tickets left
        if (tickets.empty()) {
            cout << "-1\n";
            continue;
        }

        // Find the first ticket price that does not exceed the maximum price
        auto it = tickets.lower_bound(max_price);

        if (it == tickets.begin() && *it > max_price) {
            // No ticket available within the maximum price
            cout << "-1\n";
        } else {
            // Purchase the ticket and remove it from the available tickets
            if (it == tickets.end() || (*it > max_price && it != tickets.begin())) {
                --it;
            }
            cout << *it << "\n";
            tickets.erase(it);
        }
    }

    return 0;
}
