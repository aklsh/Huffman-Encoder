#include <bits/stdc++.h>
#include <chrono>
#include "huffman.h"

using namespace std;

//change the destination of the output file here. Use absolute path
#define outputFile "/Users/akileshkannan/Desktop/compressed.txt"

int main(int argc, char *argv[])
{
  //timing analysis
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);

  //reading from input file
  ifstream textFile(argv[1]);
  string content((istreambuf_iterator<char>(textFile)), (istreambuf_iterator<char>()));
  textFile.close();

  //finding out the distinct characters and their frequency of appearance in file
  string contentSorted = content;
  sort(contentSorted.begin(),contentSorted.end());
  vector<charWithFreq> contentDistinct;
  contentDistinct = distinctCharactersAndFrequency(contentSorted);

  //displaying input file contents
  char userResponse;
  cout << "Do you want to display the input file contents (y/N)? ";
  cin >> userResponse;
  if(userResponse == 'y')
  {
    system("clear");
    cout << "Content in file:" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << content << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Press c to continue...";
    //pause func
    do
    {
      for(int i = 0; i < 10; i++);
    }while(cin.get() != 'c');
  }

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

  //forming and displaying the huffman codes
  system("clear");
  cout << "The huffman codes for the characters in the file are:"  << endl;
  cout << "----------------------------------------------------" << endl;
  formHuffmanTree(contentDistinct);
  cout << "----------------------------------------------------" << endl;

  //checking codes.dat content
  /*
  charWithCode crap;
  ifstream crapFile("codes.dat", ios::binary);
  while(crapFile.read((char*) &crap, sizeof(crap)))
  {
    if(crap.ch != '\n')
      cout << crap.ch << " " << crap.code << endl;
    else
      cout << "\\n" << " " << crap.code << endl;
  }
  crapFile.close();
  */

  cout << endl;
  cout << "The output file has been generated." << endl;
  cout << endl;

  //reading from codes.dat
  vector<charWithCode> encoding;
  charWithCode crap2;
  ifstream crapFile2("codes.dat", ios::binary);
  while(crapFile2.read((char*) &crap2, sizeof(crap2)))
    encoding.push_back(crap2);
  crapFile2.close();

  //writing to compressed file
  ofstream encodeFile(outputFile);
  for(int i = 0;i < content.size();i++)
    encodeFile << getCode(content[i], encoding);
  encodeFile.close();

  //timing analysis
  auto end = chrono::high_resolution_clock::now();
  double timeTaken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
  timeTaken *= 1e-9;
  cout << "Time taken by program is : " << fixed << timeTaken << setprecision(9);
  cout << " sec" << endl;

  return 0;
}
