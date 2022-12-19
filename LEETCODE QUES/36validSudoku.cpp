#include<bits/stdc++.h>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector <set<int>> rows(9) ,cols(9) ,boxes(9);
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int current = board[i][j]-'0';
                    int k=(i/3)*3 + j/3;
                    if(rows[i].count(current)  || cols[j].count(current)  || boxes[k].count(current)){
                        return false;
                    } 
                    rows[i].insert(current);       
                    cols[j].insert(current);       
                    boxes[k].insert(current);       
                }
                
            }
        }
     return true;
    }
};