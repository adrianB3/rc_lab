server: server.o
	gcc server.o -o server
server.o: server.c
	gcc -c server.c -o server.o

client: client.o
	gcc client.o -o client
client.o: client.c
	gcc -c client.c -o client.o

clean:
	-rm -f server.o
	-rm -f server
	-rm -f client.o
	-rm -f client