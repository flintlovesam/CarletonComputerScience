OBJ = main.o date.o bankaccount.o

myApp: $(OBJ)
	g++ -o myApp $(OBJ)

main.o:	main.cpp vector.h
	g++ -c main.cpp

bankaccount.o:	bankaccount.cpp bankaccount.h
	g++ -c bankaccount.cpp

date.o:	date.cpp date.h
	g++ -c date.cpp
	
clean:
	rm -f $(OBJ) myApp

