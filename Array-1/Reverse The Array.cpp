void reverseArray(vector<int> &arr, int m) {
    int s = m + 1;              // start index for reversal
    int e = arr.size() - 1;     // end index

    while (s <= e) {
        swap(arr[s], arr[e]);   // swap elements at both ends
        s++;
        e--;
    }
}
