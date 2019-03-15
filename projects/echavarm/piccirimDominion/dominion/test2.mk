CFLAGS = -Wall -fpic -coverage -lm

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)

testdominion: dominion.o testdominion.c
	gcc -o testdominion testdominion.c -g dominion.o rngs.o $(CFLAGS)
	./testdominion 42 >> results.out
	echo "GCOV After Playing a Game" >> results.out
	gcov dominion.c >> results.out

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)


unittest: unittest1.c unittest2.c unittest3.c unittest4.c dominion.o
	gcc -o unittest1 unittest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unittest2 unittest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unittest3 unittest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o unittest4 unittest4.c -g dominion.o rngs.o $(CFLAGS)

cardtest:
	gcc -o cardtest1 cardtest1.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest2 cardtest2.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest3 cardtest3.c -g dominion.o rngs.o $(CFLAGS)
	gcc -o cardtest4 cardtest4.c -g dominion.o rngs.o $(CFLAGS)

unittestresults.out: unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 playdom
	./unittest1 >> unittestresults.out
	echo "GCOV After unittest1" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest2 >> unittestresults.out
	echo "GCOV After unittest2" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest3 >> unittestresults.out
	echo "GCOV After unittest3" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./unittest4 >> unittestresults.out
	echo "GCOV After unittest4" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	./cardtest1 >> unittestresults.out
	echo "GCOV After cardtest1 " >> unittestresults.out
	gcov -f dominion.c >> unittestresults.out

	./cardtest2 >> unittestresults.out
	echo "GCOV After cardtest2" >> unittestresults.out
	gcov -f dominion.c >> unittestresults.out

	./cardtest3 >> unittestresults.out
	echo "GCOV After cardtest3" >> unittestresults.out
	gcov -f dominion.c >> unittestresults.out

	./cardtest4 >> unittestresults.out
	echo "GCOV After cardtest4" >> unittestresults.out
	gcov -f dominion.c >> unittestresults.out

	./playdom 3 >> unittestresults.out
	echo "GCOV After Playing a Game" >> unittestresults.out
	gcov dominion.c >> unittestresults.out

randomtestcard1: randomtestcard1.c dominion.o
	gcc -o randomtestcard1 randomtestcard1.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o
	gcc -o randomtestcard2 randomtestcard2.c -g dominion.o rngs.o $(CFLAGS)

randomtestadventurer: randomtestadventurer.c dominion.o
	gcc -o randomtestadventurer randomtestadventurer.c -g dominion.o rngs.o $(CFLAGS)

randomtestcard1.out: randomtestcard1.c playdom
	./randomtestcard1 >> randomtestcard1.out
	echo "GCOV After randomtestcard1" >> randomtestcard1.out
	gcov -f dominion.c >> randomtestcard1.out

randomtestcard2.out: randomtestcard2.c playdom
	./randomtestcard2 >> randomtestcard2.out
	echo "GCOV After randomtestcard2" >> randomtestcard2.out
	gcov -f dominion.c >> randomtestcard2.out

randomtestadventurer.out: randomtestadventurer.c playdom
	./randomtestadventurer >> randomtestadventurer.out
	echo "GCOV After randomtestadventurer" >> randomtestadventurer.out
	gcov -f dominion.c >> randomtestadventurer.out

all: playdom player unittest cardtest unittestresults.out randomtestcard1 randomtestcard2 randomtestadventurer randomtestcard1.out randomtestcard2.out randomtestadventurer.out testdominion

clean:
	rm -f *.o playdom.exe playdom test.exe test player unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4 randomtestcard1 randomtestcard2 randomtestadventurer player.exe testdominion testdominion.exe testInit testInit.exe *.gcov *.gcda *.gcno *.so *.a *.dSYM
