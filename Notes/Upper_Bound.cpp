Upper Bound in C++

upper_bound() is an STL function used with a sorted array/vector to find the first element that is greater than a given value.

Syntax
upper_bound(start_iterator, end_iterator, value);

It returns an iterator pointing to the first element strictly greater than value.
  
----------------------------------------------------------------------------------------------------------
Example
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 4, 5, 7};

    auto it = upper_bound(arr.begin(), arr.end(), 2);

    cout << *it;

    return 0;
}

Output: 4
-------------------------------------------------------------------------------------------------------------------
Find Index Using Upper Bound

int index = upper_bound(arr.begin(), arr.end(), 2) - arr.begin();

cout << index;

Output: 3
  
Because 4 is present at index 3.
--------------------------------------------------------------------------------------------------------------------
  
Quick Difference

lower_bound()
First element ≥ value

upper_bound()
First element > value

Remember: Upper bound = strictly greater.

--------------------------------------------------------------------------------------------------------------------

1. What does "returns an iterator" mean?

An iterator is like a pointer that points to an element in a container (such as a vector).

Example:

vector<int> arr = {1, 2, 2, 4, 5, 7};

auto it = upper_bound(arr.begin(), arr.end(), 2);

Here, it points to the element 4.

You can access the number using:

------>> cout << *it;

Output: 4

*it means value at the location where the iterator is pointing.

2. If you want the particular INDEX

Subtract arr.begin() from the iterator:

int index = upper_bound(arr.begin(), arr.end(), 2) - arr.begin();

cout << index;

Output:

3

Because 4 is at index 3.
--------------------------------------------------------------------------------------------------------------------
3. If you want the NUMBER

Simply dereference the iterator using *:

int num = *upper_bound(arr.begin(), arr.end(), 2);

cout << num;

Output: 4
------------------------------------------------------------------------------------------------------------------
4. Complete Example: Both Index and Number

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 2, 4, 5, 7};

    auto it = upper_bound(arr.begin(), arr.end(), 2);

    int index = it - arr.begin();
    int num = *it;

    cout << "Index: " << index << endl;
    cout << "Number: " << num << endl;

    return 0;
}

Output:

Index: 3
Number: 4
--------------------------------------------------------------------------------------------------------------------
