#include <algorithm>

struct Item {
int value, weight;
};

// Comparator to sort items by value-to-weight ratio in descending order
bool cmp(Item a, Item b) {
double r1 = (double)a.value / (double)a.weight;
double r2 = (double)b.value / (double)b.weight;
return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
std::sort(arr, arr + n, cmp);

double finalValue = 0.0;

for (int i = 0; i < n; i++) {
if (arr[i].weight <= W) {
// Take the whole item
W -= arr[i].weight;
finalValue += arr[i].value;
} else {
// Take the fraction of the item that fits
finalValue += arr[i].value * ((double)W / (double)arr[i].weight);
break; // Knapsack is full
}
}
return finalValue;
}