#pragma once
#include <iostream>
#include <vector>

using namespace std;

// Размер диапозона символов от A - z
#define ALPHABET_SIZE 94

struct TrieNode;
TrieNode* getNewNode(void);
void insert(TrieNode* root, string key);
// Поиск сужествования подстроки в префиксном дереве
bool substringSearch(TrieNode* root, string sub, vector<string>& res);
// Поиск слов содержащих введенную построку
void findWord(TrieNode* root, char buf[], int ind, vector<string>& res);

// Структура узла префиксного дерева
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord = false;
    int count = 0;
};
