app: build/menu.o build/main.o build/crypto.o build/path.o
	g++ build/main.o build/menu.o build/crypto.o build/path.o -o app.out -lncurses
build/menu.o: src/menu/menu.cpp
	g++ -std=c++17 -c src/menu/menu.cpp -o build/menu.o 
build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o
build/crypto.o: src/crypto/crypto.cpp
	g++ -std=c++17 -c src/crypto/crypto.cpp -o build/crypto.o 
build/path.o: src/path/path.cpp
	g++ -std=c++17 -c src/path/path.cpp -o build/path.o 
clean:
	rm build/* app.out