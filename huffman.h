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
  huffmanTreeNode(charWithFreq temp);
} huffmanTreeNode;

typedef struct charWithCode
{
  //data
  char ch;
  string code;

  //functions
  charWithCode(char x = '~', string str = "");
} charWithCode;

//for the priority_queue comparing function.
typedef struct heapCompare
{
  //functions
  bool operator()(huffmanTreeNode* l, huffmanTreeNode* r);
} heapCompare;

void formHuffmanTree(vector<charWithFreq> contentDistinct);
bool freqOrder(charWithFreq a, charWithFreq b);
vector<charWithFreq> distinctCharactersAndFrequency(string sortedText);
void printCodes(huffmanTreeNode *root, string str);
//string getCode(char x, vector<charWithFreq> encode);
