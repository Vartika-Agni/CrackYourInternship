class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        // std::sort(std::begin(arr), std::end(arr));
        // Your code here
        for (int i = 0; i + 1 < n; i += 2)
            swap(arr[i], arr[i + 1]);
            
    }
};