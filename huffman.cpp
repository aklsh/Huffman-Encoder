#include <bits/stdc++.h>
#include "huffman.h"

using namespace std;

charWithFreq::charWithFreq()
{
  ch = '~';
  freq = 0;
}

huffmanTreeNode::huffmanTreeNode(char ch, unsigned freq)
{

  left = right = NULL;
  this->data.ch = ch;
  this->data.freq = freq;
}

huffmanTree::huffmanTree()
{
  root = nullptr;
}

bool heapCompare::operator()(huffmanTreeNode* l, huffmanTreeNode* r)
{
  return (l->data.freq > r->data.freq);
}

vector<charWithFreq> distinctCharactersAndFrequency(string sortedText)
{
  //sortedText contains text in sorted manner - for unique() to work
  string sortedTextCopy = sortedText;
  auto ip = unique(sortedTextCopy.begin(), sortedTextCopy.end());
  sortedTextCopy = string(sortedTextCopy.begin(), ip);
  vector<charWithFreq> distinct;
  charWithFreq temp;
  for(int i = 0;i < sortedTextCopy.size();i++)
  {
    temp.ch = sortedTextCopy[i];
    temp.freq = count(sortedText.begin(), sortedText.end(), temp.ch);
    distinct.push_back(temp);
  }
  return distinct;
}

void printGraphviz(huffmanTreeNode *root)
{
  //printing in dot form
  if (root)
	{
		if (root->left)
		{
			cout << '"' << root->data << '"';
			cout << " -> ";
			cout << '"' << root->left->data << '"';
      cout << " [ label = 0  ];"
			cout << endl;
			printGraphviz(root->left);
		}
		if (root->right)
		{
			cout << '"' << root->data << '"';
			cout << " -> ";
			cout << '"' << root->right->data << '"';
			cout << endl;
			printGraphviz(root->right);
		}
	}
}
