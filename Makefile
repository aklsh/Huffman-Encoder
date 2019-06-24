compileRunAndDelete:
	@clear
	@rm -f codes.dat
	@g++ -std=c++11 main.cpp huffman.cpp
	@./a.out ${input}
	@rm -f ./a.out
