#include "Trie.h"

TrieNode* getNewNode(void)
{
    struct TrieNode* pNode = new TrieNode;
    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}

void insert(TrieNode* root, string key)
{
    TrieNode* node = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - '!';
        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
        node->count++;
    }
    node->isEndOfWord = true;
}

bool substringSearch(TrieNode* root, string sub, vector<string>& res)
{
    TrieNode* node = root;
    for (int i = 0; i < sub.size(); i++) {
        int ind = sub[i] - '!';
        if (node->children[ind])
            node = node->children[ind];
        else
            return false;
    }

    char buf[1024] = { "" };
    int ind = 0;
    findWord(node, buf, ind, res);
    return true;
}

void findWord(TrieNode* root, char buf[], int ind, vector<string>& res)
{
    if (!root)
        return;
    if (root->isEndOfWord) {
        buf[ind] = '\0';
        res.push_back(buf);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i])
        {
            char buf1[1024];
            for (int k = 0; k < 1024; k++)
                buf1[k] = buf[k];
            buf1[ind] = i + '!';
            findWord(root->children[i], buf1, ind + 1, res);
        }
    }
}