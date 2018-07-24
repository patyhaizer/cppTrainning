#include <iostream>
#include <vector>


void
quickSort(std::vector<int>& arr, int begin, int end) {
    std::cout << "Begin: " << begin << std::endl;
    std::cout << "End: " << end << std::endl;
    if (begin >= end) return;
    
    int left = begin;
    int rigth = end;
    int pivot = rigth;
    --rigth;
    
    while (left < rigth) {
        // This increments the letf pointer while the element
        // in that position is less then pivo
        // (which means the element is already in the rigth place)
        // or until it reaches the boundarie
        while ((left <= end) && arr[left] < arr[pivot]) { ++left; };
        // This decrements the rigth pointer while the element
        // in that position is greater then pivo
        // (which means the element is already in the rigth place)
        // or until it reaches the boundarie
        while ((rigth >=0) && arr[rigth] > arr[pivot]) { --rigth; };
        std::cout << "left is: " << left << " - rigth is: " << rigth << std::endl;
        if (left < rigth) {
            // Exchange the elemets and increment left and decrement rigth
            std::swap(arr[left++], arr[rigth--]);
        }
    }
    // Change pivot with left since left is guaranteed to be the first bigger element then pivot
    std::swap(arr[left], arr[pivot]);
    // Call quickSort again with the partitions
    quickSort(arr, begin, left - 1);
    quickSort(arr, left + 1, end);
}

void
testCode() {
    std::vector<int> test = {1,2,3,1,1};
    quickSort(test, 0, test.size() - 1);
    for (int i : test) {
        std::cout << i << " - ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Hello World!\n";
    testCode();
}
