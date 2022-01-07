app: build/menu.o build/main.o build/crypto.o
	g++ build/main.o build/menu.o build/crypto.o -o app.out
build/menu.o: src/menu/menu.cpp
	g++ -c src/menu/menu.cpp -o build/menu.o
build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o
build/crypto.o: src/crypto/crypto.cpp
	g++ -c src/crypto/crypto.cpp -o build/crypto.o
clean:
	rm build/* app.out