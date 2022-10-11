#include <bits/stdc++.h>
using namespace std;
class trienode
{
public:
    char data;
    trienode *children[26];
    bool isterminal;
    trienode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminal = false;
    }
};
class trie
{
public:
    trienode *root;
    trie()
    {
        root = new trienode('\0');
    }
    void insertutil(trienode *root, string word)
    {
        // base case

        if (word.length() == 0)
        {
            root->isterminal = true;
            return;
        }
        trienode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            // character is present

            child = root->children[index];
        }
        else
        {
            child = new trienode(word[0]);
            root->children[index] = child;
        }
        insertutil(child, word.substr(1));
    }
    void insertword(string word)
    {
        insertutil(root, word);
    }
    bool searchutil(trienode *root, string word)
    {
        // base case

        if (word.length() == 0)
        {
            return root->isterminal;
        }
        trienode *child;
        int index = word[0] - 'a';
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return searchutil(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchutil(root, word);
    }
};
int main()
{
    trie *t = new trie;
    t->insertword("abcd");
    t->insertword("sampad");
    t->insertword("saikat");
    cout << t->search("abcdk") << endl;
    cout << t->search("sampad") << endl;
    cout << t->search("saikat") << endl;
    return 0;
}