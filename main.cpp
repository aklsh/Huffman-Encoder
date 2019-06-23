#include <bits/stdc++.h>
#include "huffman.h"

using namespace std;

typedef long long int lli;
typedef long double ld;

int main()
{
  ifstream textFile("input.txt");
  string content((istreambuf_iterator<char>(textFile)), (istreambuf_iterator<char>()));
  string contentSorted = content;
  sort(contentSorted.begin(),contentSorted.end());
  vector<charWithFreq> contentDistinct;
  contentDistinct = distinctCharactersAndFrequency(contentSorted);

  cout << "Content in file:" << endl;
  cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << content;
  cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << endl;
  cout << endl;
  //debugging statements
  /*
  cout << "Sorted Content:";
  cout << contentSorted;
  cout << endl;
  cout << "\nDistinct Sorted Content:";
  for(int i = 0;i < contentDistinct.size();i++)
    cout << contentDistinct[i].ch << contentDistinct[i].freq << " ";
  cout << endl;
  */
  cout << "The huffman codes for the characters in the file are:"  << endl;
  cout << "----------------------------------------------------" << endl;
  formHuffmanTree(contentDistinct);
  cout << "----------------------------------------------------" << endl;
  textFile.close();
  return 0;
}
