compileRunAndDelete:
	@clear
	@g++ -std=c++11 main.cpp huffman.cpp
	@./a.out inputs/${input}
	@rm -f ./a.out ./codes.dat
