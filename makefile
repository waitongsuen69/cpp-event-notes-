FLAGS = -std=c++11
test: test.cpp object.cpp object.h
	g++ test.cpp object.cpp -o test $(FLAGS)
tem: test_temp.cpp test.txt 
	g++ test_temp.cpp -o test $(FLAGS)