#pragma once
#include <iostream>
#include <vector>

using namespace std;

// ������ ��������� �������� �� A - z
#define ALPHABET_SIZE 94

struct TrieNode;
TrieNode* getNewNode(void);
void insert(TrieNode* root, string key);
// ����� ������������� ��������� � ���������� ������
bool substringSearch(TrieNode* root, string sub, vector<string>& res);
// ����� ���� ���������� ��������� ��������
void findWord(TrieNode* root, char buf[], int ind, vector<string>& res);

// ��������� ���� ����������� ������
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord = false;
    int count = 0;
};
