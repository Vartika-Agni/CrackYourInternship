struct compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // if frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
 
        // insert elements in the priority queue on the basis of
        // decreasing order of frequencies
        return p1.second < p2.second;
    }
};
 
// function to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int n, int k)
{
    // unordered_map 'um' implemented as frequency hash table
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++)
        um[arr[i]]++;
 
     
 
    // priority queue 'pq' implemented as max heap on the basis
    // of the comparison operator 'compare'
    // element with the highest frequency is the root of 'pq'
    // in case of conflicts, larger element is the root
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                compare>
        pq(um.begin(), um.end());
 
    // display the top k numbers
    cout << k << " numbers with most occurrences are:\n";
    for (int i = 1; i <= k; i++) {
        cout << pq.top().first << " ";
        pq.pop();
    }
}