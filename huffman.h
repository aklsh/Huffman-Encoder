using namespace std;

typedef struct charWithFreq
{
  //data
  char ch;
  int freq;

  //functions
  charWithFreq();
} charWithFreq;

typedef struct huffmanTreeNode
{
  //data
  charWithFreq data;
	struct huffmanTreeNode *left, *right;

  //functions
  huffmanTreeNode(char ch, unsigned freq);
} huffmanTreeNode;

//for the priority_queue comparing function.
typedef struct heapCompare
{
  bool operator()(huffmanTreeNode* l, huffmanTreeNode* r);
} heapCompare;

class huffmanTree
{
public:
  //data
  huffmanTreeNode *root;

  //functions
  huffmanTree();
};

bool freqOrder(charWithFreq a, charWithFreq b);
vector<charWithFreq> distinctCharactersAndFrequency(string sortedText);
void printGraphviz(huffmanTreeNode *root);
