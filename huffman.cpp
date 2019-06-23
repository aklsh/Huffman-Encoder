#include <bits/stdc++.h>
#include "huffman.h"

using namespace std;
stringstream strCode;

charWithFreq::charWithFreq()
{
  ch = '~';
  freq = 0;
}

huffmanTreeNode::huffmanTreeNode(charWithFreq temp)
{

  left = right = NULL;
  this->data.ch = temp.ch;
  this->data.freq = temp.freq;
}

bool freqOrder(charWithFreq a, charWithFreq b)
{
  return (a.freq > b.freq);
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

void formHuffmanTree(vector<charWithFreq> contentDistinct)
{
  huffmanTreeNode *left, *right, *temp;
  priority_queue <huffmanTreeNode*, vector<huffmanTreeNode*>, heapCompare> huffmanHeap;
  for(int i = 0;i < contentDistinct.size();++i)
    huffmanHeap.push(new huffmanTreeNode(contentDistinct[i]));
  while(huffmanHeap.size() != 1)
  {
    left = huffmanHeap.top();
    huffmanHeap.pop();
    right = huffmanHeap.top();
    huffmanHeap.pop();

    charWithFreq idk;
    idk.freq = left->data.freq + right->data.freq;
    idk.ch = '~';
    temp = new huffmanTreeNode(idk);
    temp->left = left;
    temp->right = right;
    huffmanHeap.push(temp);
  }
  cout << printCodes(huffmanHeap.top(), "");
}

string printCodes(huffmanTreeNode* root, string str)
{
  strCode << str;
	if (!root)
		return "";

	if (root->data.ch != '~')
  {
    if(root->data.ch!= '\n')
      strCode << root->data.ch << ": " << str << "\n";
    else
      strCode << "\\n" << ": " << str << "\n";
  }

	strCode << printCodes(root->left, str + "0");
	strCode << printCodes(root->right, str + "1");
  string allCodes = strCode.str();
  strCode.clear();
  return allCodes;
}
