#include <bits/stdc++.h>
#include "huffman.h"

using namespace std;

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
  printCodes(huffmanHeap.top(), "");
}

void printCodes(huffmanTreeNode* root, string str)
{
  ofstream codeFile("codes.dat", ios::binary | ios::out | ios::app);
	if (!root)
		return;

	if (root->data.ch != '~')
  {
    if(root->data.ch!= '\n')
    {
      cout << root->data.ch << ": " << str << endl;
      codeFile.write((char*) &(root->data), sizeof(root->data));
      //codeFile << root->data.ch << " " << str << endl;
    }
    else
    {
      cout << "\\n" << ": " << str << endl;
      /*codeFile<< "\\n" << " " << str << endl;*/
      codeFile.write((char*) &(root->data), sizeof(root->data));
    }
  }

	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
  codeFile.close();
}
