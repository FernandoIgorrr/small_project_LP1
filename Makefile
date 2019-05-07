PROG	= main
CC		= g++
FLAGS	= -O0 -g -Wall
OBJS	= main.o command.class.o database.class.o employee.class.o company.class.o

$(PROG):$(OBJS)
	$(CC) -o $(PROG) $(OBJS)
main.o:
	$(CC) $(FLAGS) -c main.cpp
command.class.o: _classes/command.class.h
	$(CC) $(FLAGS) -c _classes/command.class.cpp
database.class.o: _classes/database.class.h
	$(CC) $(FLAGS) -c _classes/database.class.cpp
company.class.o: _classes/company.class.h
	$(CC) $(FLAGS) -c _classes/company.class.cpp
employee.class.o: _classes/employee.class.h
	$(CC) $(FLAGS) -c _classes/employee.class.cpp

cls:
	rm -f $(PROG) $(OBJS)


