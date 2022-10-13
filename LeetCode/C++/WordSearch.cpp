class Solution
{
public:
    bool search(int i, int j, int n, int m, vector<vector<char>> &board, string word, int k)
    {
        if (k == word.size())
            return true;
        if (i < 0 || j < 0 || i == n || j == m || board[i][j] != word[k])
            return false;
        char ch = board[i][j];
        board[i][j] = '#';
        bool opt1 = search(i + 1, j, n, m, board, word, k + 1);
        bool opt2 = search(i, j + 1, n, m, board, word, k + 1);
        bool opt3 = search(i - 1, j, n, m, board, word, k + 1);
        bool opt4 = search(i, j - 1, n, m, board, word, k + 1);
        board[i][j] = ch;
        return opt1 || opt2 || opt3 || opt4;
    }
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (search(i, j, n, m, board, word, 0))
                    return true;
            }
        }
        return false;
    }
};