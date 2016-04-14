all : main run

main : check.cpp 
	g++ -I.. $< -o $@ -std=c++11

run : main
	./$<
