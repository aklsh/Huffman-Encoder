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
  sort(contentDistinct.begin(), contentDistinct.end(), freqOrder);

  //debugging statements
  /**/
  cout << "Content in file:";
  cout << content;
  cout << endl;
  cout << "Sorted Content:";
  cout << contentSorted;
  cout << endl;
  cout << "\nDistinct Sorted Content:";
  for(int i = 0;i < contentDistinct.size();i++)
    cout << contentDistinct[i].ch << contentDistinct[i].freq << " ";
  cout << endl;
  /**/

  textFile.close();
  return 0;
}
