class Solution {
public:
    string simplifyPath(string path) {
        string currentPath, result;
        vector<string> storage;
        
        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (currentPath.size()) {
                    if (currentPath == ".") {
                        currentPath.clear();
                        continue;
                    }
                    else if (currentPath == "..") {
                        if (storage.size()) {
                            storage.pop_back();
                        }
                    }
                    else {
                        storage.push_back(currentPath);
                    }
                }
                currentPath.clear();
            }
            else {
                currentPath += path[i];
            }
        }
        
        result = "/";
        for (int i = 0; i < storage.size(); i++) {
            result += storage[i];
            if (i != storage.size() - 1) {
                result += "/";
            }
        }
        return result;
    }
};
