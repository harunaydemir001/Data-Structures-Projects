CXXFLAGS=	-I "./include"

basla: program1
	./bin/program1.exe
program1: BST.o Kisi.o node.o nodeBST.o Yigit.o YigitNode.o main.o
	g++ ./lib/BST.o ./lib/Kisi.o ./lib/node.o ./lib/nodeBST.o ./lib/Yigit.o ./lib/YigitNode.o ./lib/main.o -o ./bin/program1
	
BST.o:
	g++ $(CXXFLAGS) -c ./src/BST.cpp -o ./lib/BST.o 
Kisi.o:
	g++ $(CXXFLAGS) -c ./src/Kisi.cpp -o ./lib/Kisi.o 
node.o:
	g++ $(CXXFLAGS) -c ./src/node.cpp -o ./lib/node.o 
nodeBST.o:
	g++ $(CXXFLAGS) -c ./src/nodeBST.cpp -o ./lib/nodeBST.o
Yigit.o:
	g++ $(CXXFLAGS) -c ./src/Yigit.cpp -o ./lib/Yigit.o  
YigitNode.o:
	g++ $(CXXFLAGS) -c ./src/YigitNode.cpp -o ./lib/YigitNode.o  
main.o:
	g++ $(CXXFLAGS) -c ./src/main.cpp -o ./lib/main.o 





