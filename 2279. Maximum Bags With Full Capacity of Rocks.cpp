class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remaining(capacity.size(), 0);
        
        for (int i = 0; i < capacity.size(); i++) {
            remaining[i] = capacity[i] - rocks[i];
        }
        sort(begin(remaining), end(remaining));
        
        int count = 0;
        for (int r : remaining) {
            if (additionalRocks >= r) {
                count++;
                additionalRocks -= r;
            }
            else {
                break;
            }
        }
        return count;
    }
};
