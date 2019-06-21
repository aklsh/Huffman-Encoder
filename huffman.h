class huffmanTreeNode
{
public:
  char data;
  huffmanTreeNode *left;
  huffmanTreeNode *right;

  huffmanTreeNode(char x);
};

class huffmanTree
{
public:
  huffmanTreeNode *root;

  huffmanTree();
  huffmanTreeNode* formHuffmanTree(huffmanTreeNode *root, vector<char> characters);

};

vector<char> distinctCharacters(string sortedText);
int countFreq(string text, char x);
