#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << "Enter vector elements (Ctrl+D or Ctrl+Z to end input): ";

    // Use istream_iterator to read integers from standard input until EOF
    std::istream_iterator<int> inputIt(std::cin);  // Reads first value
    std::istream_iterator<int> end;                // End of stream
    std::vector<int> vec(inputIt, end);            // Fill vector with all input

    cout << "\nPartial Sort:\n";

    // Define the number of smallest elements to sort and bring to the front
    int startingSortedValuesFromEntireVector = distance(vec.begin(), vec.begin() + 3);
    cout << "First " << startingSortedValuesFromEntireVector << " sorted elements are:\n";

    /*
     * std::partial_sort(first, middle, last)
     * - Rearranges elements in the range [first, last)
     * - After sorting: 
     *     - The smallest (middle - first) elements are placed in [first, middle), sorted.
     *     - The rest of the elements remain in unspecified order.
     * - Does not sort the entire container!
     */
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());

    // Print all elements to observe the effect
    for (auto el : vec)
        cout << el << " ";
    cout << endl;

    return 0;
}
