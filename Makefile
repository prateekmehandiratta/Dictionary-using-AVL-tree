all:sample

sample:main.o entryclassfunction.o nodeclassfunction.o avltreefunctions.o 
	g++ main.o entryclassfunction.o nodeclassfunction.o avltreefunctions.o -o sample

main.o: main.cpp
	g++ -c main.cpp

entryclassfunction.o: entryclassfunction.cpp
	g++ -c entryclassfunction.cpp

nodeclassfunction.o: nodeclassfunction.cpp
	g++ -c nodeclassfunction.cpp

avltreefunctions.o: avltreefunctions.cpp
	g++ -c avltreefunctions.cpp

clean:
	rm -f *o sample

