#pragma once
#ifndef _LEETCODE0289
#define _LEETCODE0289

#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size() < 1)
            return;

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                int lives = countlive(board, i, j);
                if ((board[i][j] & 1) == 1)
                {
                    if (lives >= 2 && lives <= 3)
                    {
                        board[i][j] = 3;
                    }
                }
                else
                {
                    if (lives == 3)
                        board[i][j] = 2;
                }
            }
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                board[i][j] >>= 1;
            }
        }

    }
private:
    int countlive(vector<vector<int>>& b, int i, int j)
    {
        int count = 0;
        vector<vector<int>> dirs = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };
        for (auto dir : dirs)
        {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x<0 || x>b.size() - 1 || y<0 || y>b[0].size() - 1)
                continue;

            count += (b[x][y] & 1);
        }
        return count;
    }
};



#endif // !_LEETCODE0289

