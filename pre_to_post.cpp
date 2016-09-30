// Ashena Gorgan Mohammadi, 610394128

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> string_to_blocks(string pre){
    vector<string> blocks;
    for(int i = 0; i < pre.size(); i++){
        string str = "";
        str += pre[i];
        blocks.push_back(str);
    }
    return blocks;
}

bool isOperator(string a){
    if(a == "-" || a == "*" || a == "+" || a == "/" || a == "^")
        return true;
    return false;
}

vector<string> pre_to_post(vector<string> blockHolder){
    for(int i = blockHolder.size() - 3; i >= 0; i--){
        if(isOperator(blockHolder[i])){
            blockHolder[i + 1] += blockHolder[i + 2];
            blockHolder[i + 1] += blockHolder[i];
            blockHolder.erase(blockHolder.begin() + i + 2);
            blockHolder.erase(blockHolder.begin() + i);
            i = blockHolder.size();
        }
    }
    return blockHolder;
}

int main(){
    string pre = "-+/A^BC*DE*AC";
    vector<string> blocks;
    blocks = string_to_blocks(pre);
    blocks = pre_to_post(blocks);
    cout << blocks[0] << endl;
    return 0;
}