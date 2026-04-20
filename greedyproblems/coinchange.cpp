#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int coinChange(vector<int> &coins, int amount) {
    int inf = amount + 1;
    vector<int> dp(amount + 1, inf);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[amount] > amount) ? -1 : dp[amount];
}

int main() {
    int n;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter target amount: ";
    cin >> amount;

    int result = coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;

    return 0;
}