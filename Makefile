vector_old: vector_old.cpp
	g++ -o vector_old vector_old.cpp
class: class.cpp
	g++ -o class class.cpp
clean:
	rm *.o *.cpp
class1: class.cpp
	g++ -O1 class.cpp -o class1
class2: clas.cpp
	g++ -O2 class.cpp -o class2
class3: class.cpp
	g++ -O3 class.cpp -o class3