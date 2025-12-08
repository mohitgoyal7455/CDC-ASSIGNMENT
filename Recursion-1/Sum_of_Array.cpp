class Solution {
  public:
    // Recursive function to find sum of elements in array
    int arraySumHelper(vector<int>& arr, int index) {
        // Base case: if we’ve reached the end of the array
        if (index == arr.size())
            return 0;
        
        // Recursive case: current element + sum of rest
        return arr[index] + arraySumHelper(arr, index + 1);
    }

    // Wrapper function (as per problem structure)
    int arraySum(vector<int>& arr) {
        return arraySumHelper(arr, 0);
    }
};
