#include <iostream>
#include <vector>
#include <random>

using namespace std;

int Partition(vector<int> &arr, int p, int r, int &comps) {
    int last = arr[r];
    int i = p - 1, j = p;
    for(; j < r; ++j) {
        ++comps;
        if(arr[j] < last) {
            ++i;
            if(i != j) {
                swap(arr[i], arr[j]);
            }
        }
    }
    if(i + 1 != r) {
        swap(arr[i+1], arr[r]);
    }
    return i + 1;
}

void QuickSort(vector<int> &arr, int p, int r, int &comps) {
    if (p >= r)
        return;
    int randPos = (rand() % (r - p)) + p;
    if(randPos != r) {
        swap(arr[randPos], arr[r]);
    }
    int q = Partition(arr, p, r, comps);
    QuickSort(arr, p, q - 1, comps);
    QuickSort(arr, q + 1, r, comps);
}

int select(vector<int> &arr, int p, int r, int idx) {
    if(p > r) {
        return -1;
    }
    int discard;
    int q = Partition(arr, p, r, discard);
    if(q == idx) {
        return arr[idx];
    } else if(q < idx) {
        return select(arr, q + 1, r, idx);
    } else {
        return select(arr, p, q - 1, idx);
    }
}

int main() {
    auto arr = vector{7,6,4,8,9,5,1,3,2,0};
    int comps = 0;

    // QuickSort(arr, 0, arr.size() - 1, comps);
    cout << select(arr, 0, arr.size() - 1, 4) << endl;
    for(auto item: arr) {
        cout << item << ", ";
    }
    cout << endl;

    cout << comps;
}