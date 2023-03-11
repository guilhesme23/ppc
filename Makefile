build: 
	@ g++ -o out.o -W -Wall -Wextra -std=c++17 -O2 ./$(code).cpp

clean:
	rm -rf ./out.o
	rm -rf ./result.txt