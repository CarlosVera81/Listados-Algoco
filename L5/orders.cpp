#include <bits/stdc++.h>

using namespace std;

// Initialize the input variables
int n, c[100], m;  // Maximum number of items and their costs
int dp[30001], itemTrace[30001];  // DP array and trace for solution reconstruction

void solveOrder(int s) {
    // Initialize DP and trace arrays
    fill(dp, dp + s + 1, 0);
    fill(itemTrace, itemTrace + s + 1, -1);
    dp[0] = 1;  // Base case: sum 0 can always be formed with no items

    // DP table computation
    for (int i = 0; i < n; ++i) {  // Iterate over items
        for (int j = c[i]; j <= s; ++j) {  // Iterate over possible sums
            if (dp[j - c[i]] > 0) {
                if (dp[j] == 0) {
                    dp[j] = dp[j - c[i]];
                    itemTrace[j] = i;  // Store the last item used
                } else {
                    dp[j] = 2;  // Mark as ambiguous
                }
            }
        }
    }

    // Output the result based on DP table
    if (dp[s] == 0) {
        printf("Impossible\n");
    } else if (dp[s] == 2) {
        printf("Ambiguous\n");
    } else {
        vector<int> result;
        int current = s;

        // Reconstruct the solution using the `itemTrace` array
        while (current > 0) {
            int item = itemTrace[current];
            result.push_back(item + 1);  // Store 1-based index of the item
            current -= c[item];
        }

        // Print the result in ascending order
        sort(result.begin(), result.end());
        for (int idx : result) {
            printf("%d ", idx);
        }
        printf("\n");
    }
}

int main() {
    // Input: number of items on the menu
    scanf("%d", &n);

    // Input: cost of each item
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // Input: number of orders
    scanf("%d", &m);

    // Process each order
    for (int i = 0; i < m; i++) {
        int s;
        scanf("%d", &s);
        solveOrder(s);  // Solve for the current order total
    }

    return 0;
}
