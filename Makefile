compileRunAndDelete:
	@clear
	@g++ -std=c++11 main.cpp huffman.cpp
	@./a.out
	@rm -f ./a.out
