main: main.o Employee.o workerManage.o
	g++ -g -Wall -std=c++11 -o main main.o Employee.o workerManage.o

main.o: main.cpp
	g++ -g -std=c++11 -c main.cpp 

Employee.o: Employee.cpp
	g++ -g -std=c++11 -c Employee.cpp 

WorkerManage.o: workerManage.cpp
	g++ -g -std=c++11 -g workerManage.cpp

clean:
	rm -f main main.o Employee.o workerManage.o
