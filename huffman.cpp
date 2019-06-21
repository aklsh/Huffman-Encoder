#include <bits/stdc++.h>
#include "huffman.h"

using namespace std;

huffmanTreeNode::huffmanTreeNode(char x)
{
  data = x;
  left = NULL;
  right = NULL;
}

int countFreq(string text, char x)
{
  int count = 0;
  for(int i = 0;i < text.size();i++)
    if(text[i] == x)
      count++;
  return count;
}

vector<char> distinctCharacters(string sortedText)
{
  vector <char> distinct;

  for(int i = 0;i < sortedText.size();i++)
  {
    if(distinct[distinct.size()-1] != sortedText[i])
      distinct.push_back(sortedText[i]);
  }
  return distinct;
}

huffmanTreeNode* huffmanTree::formHuffmanTree(huffmanTreeNode *root, vector<char> characters)
