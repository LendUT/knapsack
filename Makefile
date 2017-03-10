LIBS=$(wildcard libs/*)
INCLUDE_PATH=libs/

main: libraries
	gcc main.c libraries/* -I$(INCLUDE_PATH) -o mochila0-1

libraries:
	mkdir libraries/
	for dir in $(LIBS); do \
		cd $$dir; \
		gcc -c *.c -I../; \
		mv *.o ../../libraries; \
		cd -; \
	done

clean:
	rm -rf libraries/ main
