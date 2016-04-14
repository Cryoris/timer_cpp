all : main run

main : check.cpp 
	g++ $< -o $@ -lTimer -std=c++11

run : main
	./$<
