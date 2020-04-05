vector_old: vector_old.cpp
	g++ -o vector_old vector_old.cpp
deque_old: deque_old.cpp
	g++ -o deque_old deque_old.cpp
vector1: vector_1_strat.cpp
	g++ -o vector_1_strat vector_1_strat.cpp
deque1: deque_1_strat.cpp
	g++ -o deque_1_strat deque_1_strat.cpp
vector2: vector_2_strat.cpp
	g++ -o vector_2_strat vector_2_strat.cpp
deque2: deque_2_strat.cpp
	g++ -o deque_2_strat deque_2_strat.cpp
vector2_alg: vector_2_alg.cpp
	g++ -o vector_2_alg vector_2_alg.cpp
clean:
	rm *.o *.cpp