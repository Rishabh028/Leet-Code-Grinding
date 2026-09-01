class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens;
        string token;
        int index = 0;
            while(findNextToken(path, index, token)){
                if(token == ".."){
                    if(!tokens.empty()) tokens.pop_back();
                } else if(token != "."){
                    tokens.push_back(token);
                }
            }

        string canonicalPath = "";
        for(const string& token : tokens){
            canonicalPath += "/";
            canonicalPath += token;
        }
        if(canonicalPath == "") return "/";
        return canonicalPath;
    }

    bool findNextToken(string& path, int& index, string& token){
        int n = path.size();
        while(index < n && path[index] == '/') index++;
        if(index == n) return false;

        token = "";
        while(index < n && path[index] != '/'){
            token += path[index];
            index++;
        }

        return true;
    }
};