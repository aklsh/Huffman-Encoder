# Huffman Coding

[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
[![Version](https://img.shields.io/badge/Version-1.0.0-orange.svg)](https://github.com/aklsh/huffman-coding)
[![Build status](https://img.shields.io/badge/Build-Passing-green.svg)](Makefile)
[![Downloads](https://img.shields.io/github/downloads/aklsh/huffman-coding/total.svg)](https://github.com/aklsh/huffman-coding/archive/master.zip)

This repository supplements my [blog post on huffman encoding](https://aklsh.me/Huffman-Encoding).

## Requirements
[![Language](https://img.shields.io/badge/Language-C++11-yellowgreen.svg)](https://en.wikipedia.org/wiki/C%2B%2B11)

This project is written in C++11. For user comfort, I have also included a makefile that uses g++ as the compiler. Install `g++` if you want to do an automatic compilation and running of the program.

## Install
* Clone this repository with `git clone https://github.com/aklsh/huffman-coding`
* You can also download this repository by clicking on the big green button near the top of this page.
![clone or download](/images/download.png)

## Usage
I have included a makefile that will automatically do all the compilation and running of the program. You have to only specify the input file and the output file to the program.
```bash
make input="<path of input file>" output="<path of output file>"
```
The files have to be *__TEXT FILES ONLY (.txt)__* .

## Organization of files
`main.cpp` - contains the `main()` for the program.  
`huffman.h` - contains declaration of all classes and functions.  
`huffman.cpp` - contains definitions for all functions (_including member functions of classes_) declared in `huffman.h`.  
`Makefile` - a bash script to automatically compile and run the program.  
`sample inputs/` - folder containing a few sample input text files.  

## Some example Outputs
![example file content](/images/example-content.png)
![example codes](/images/example-codes.png)
![example compressed file](/images/example-encoded-file.png)

## Contributing
![PRs-welcome](https://img.shields.io/badge/PullRequests-Welcome-green.svg)
Please feel free to submit pull requests to this repository!

## License
[MIT © Akilesh Kannan](LICENSE)
