compileRunAndDelete:
	@clear
	@g++ -std=c++11 main.cpp huffman.cpp
	@./a.out ${input} ${output}
	@rm -f ./a.out ./codes.dat
