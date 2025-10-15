#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {

    cout << "PROGRAM:" << endl;
    list<int> nums;
    int k, n; 
    
    cin >> k >> n;

    for (int i = 0; i < n; ++i) {
        int input;
        cin >> input;
        nums.push_back(input);
    }

    
    int idx = 0;
    int smaller = *nums.begin();

    for (auto it = nums.begin(); it != nums.end(); ) {
        if (*it < smaller) {
            smaller = *it;
            it = nums.erase(it);
        } else {
            ++it;
        }
    }

    for (int& num : nums) {
        cout << num << " ";
    }
    cout << endl;
}
