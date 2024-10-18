class Solution {
private:
    bool isPossible(vector<int>& weights, int days, int value) {
        int count = 1, load = 0;
        for (int i = 0; i < weights.size(); i++) {
            load += weights[i];
            if (load > value) {
                count++;
                load = weights[i];
            }
        }
        
        return count <= days;
    }
    
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(begin(weights), end(weights));
        int high = accumulate(begin(weights), end(weights), 0), mid;
        
        while (low < high) {
            mid = low + (high - low) / 2;
            
            if (isPossible(weights, days, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        
        return low;
    }
};
