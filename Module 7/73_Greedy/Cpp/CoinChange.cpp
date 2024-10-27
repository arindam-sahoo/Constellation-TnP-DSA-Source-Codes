#include <iostream>
#include <vector>

void coinChange(const std::vector<int>& deno, int amt) {
    std::vector<int> nums(deno.size(), 0);
    for (int i = deno.size() - 1; i >= 0; i--) {
        while (amt >= deno[i]) {
            amt -= deno[i];
            nums[i]++;
        }
    }
    std::cout << "The Denominations are:\n";
    for (int i = deno.size() - 1; i >= 0; i--) {
        if (nums[i] > 0) {
            std::cout << nums[i] << " x " << deno[i] << "\n";
        }
    }
}

int main() {
    std::vector<int> deno = {1, 2, 5, 10, 20, 50, 100, 200, 500};
    int amt = 2898;

    coinChange(deno, amt);
    return 0;
}
