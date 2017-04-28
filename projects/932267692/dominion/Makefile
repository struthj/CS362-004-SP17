CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

unittest1: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 unittest1.c rngs.c -o unittest1 -lm -g 

unittest2: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 unittest2.c rngs.c -o unittest2 -lm -g

unittest3: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 unittest3.c rngs.c -o unittest3 -lm -g 

unittest4: 
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 unittest4.c rngs.c -o unittest4 -lm -g 

cardtest1:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 cardtest1.c rngs.c -o cardtest1 -lm -g

cardtest2:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 cardtest2.c rngs.c -o cardtest2 -lm -g

cardtest3:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 cardtest3.c rngs.c -o cardtest3 -lm -g

cardtest4:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 cardtest4.c rngs.c -o cardtest4 -lm -g

cardtest5:
	gcc -fprofile-arcs -ftest-coverage -Wall -std=c99 cardtest5.c rngs.c -o cardtest5 -lm -g

unittestresults: unittest1 unittest2 unittest3 unittest4
	./unittest1 &> unittestresult.out
	./unittest2 >> unittestresult.out
	./unittest3 >> unittestresult.out
	./unittest4 >> unittestresult.out
	./cardtest1 >> unittestresult.out
	./cardtest2 >> unittestresult.out
	gcov dominion.c.gcov >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

all: playdom player testDrawCard testBuyCard badTestDrawCard

clean:
	rm -f *.o playdom.exe playdom test.exe test player player.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so
