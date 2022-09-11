run: Test
	./Test

Test: Test.o 
	clang++ -o Test Test.o

Test.o: Test.cc Test.hh
	clang++ -std=c++11 -c Test.cc