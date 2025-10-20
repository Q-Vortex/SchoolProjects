#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main() {
    list<int> nums;
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    // Да ёбаный в рот, этот list! Ну почему ты не можешь просто быть нормальным массивом, а? 
    // С каждым --it и ++it я словно в аду бьюсь с твоими идиотскими итераторами, 
    // которые ведут себя как капризные дети. Всё, что нужно — просто соседний элемент, 
    // а нет, придётся делать танцы с бубном, проверять begin(), end(), ещё раз begin(), 
    // и молиться на STL, чтобы он не выдал UB. Сука, ну почему это так сложно?!

    for (auto it = ++nums.begin(); it != nums.end();) {

        cout << endl << "This debug is the nums: ";
        for (const int& num : nums) 
            cout << num << " "; 
        cout << "   Now pos: " << *it << endl;

        if (nums.size() == 2) break;
        if (it == nums.begin()) ++it;

        auto prev = (it != nums.begin()) ? std::prev(it) : nums.end();
        auto next = std::next(it);

        if (*prev < *it) {
            it = nums.erase(prev);
            cout << "   After prev delete now pos: " << *it << endl;
        } else if (*next < *it) {
            it = nums.erase(next);
            cout << "   After next delete now pos: " << *it << endl;
        } else if (*it < *prev && *it < *next) {
            it = nums.erase(it);
            cout << "   After now delete now pos: " << *it << endl;
        } else {
            ++it;
        }
    }

    cout << endl << "This is the nums: ";
    for (const int& num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
}
