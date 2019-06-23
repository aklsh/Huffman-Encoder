#include <bits/stdc++.h>
#include <chrono>
#include "huffman.h"

using namespace std;

typedef long long int lli;
typedef long double ld;

int main()
{
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
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
  auto end = chrono::high_resolution_clock::now();
  double timeTaken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  timeTaken *= 1e-9; 
  cout << "Time taken by program is : " << fixed << timeTaken << setprecision(9); 
  cout << " sec" << endl; 
  return 0;
}
