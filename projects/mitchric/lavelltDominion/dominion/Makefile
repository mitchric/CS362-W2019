CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

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

feastTest: feastTest.c dominion.o rngs.o
	gcc -o feastTest -g feastTest.c dominion.o rngs.o $(CFLAGS)

adventurerTest: adventurerTest.c dominion.o rngs.o
	gcc -o adventurerTest -g adventurerTest.c dominion.o rngs.o $(CFLAGS)

smithyTest: smithyTest.c dominion.o rngs.o
	gcc -o smithyTest -g smithyTest.c dominion.o rngs.o $(CFLAGS)

treasureMapTest: treasureMapTest.c dominion.o rngs.o
	gcc -o treasureMapTest -g treasureMapTest.c dominion.o rngs.o $(CFLAGS)

randomSmithyTest: randomSmithyTest.c dominion.o rngs.o
	gcc -o randomSmithyTest -g randomSmithyTest.c dominion.o rngs.o $(CFLAGS)

randomTreasureMapTest: randomTreasureMapTest.c dominion.o rngs.o
	gcc -o randomTreasureMapTest -g randomTreasureMapTest.c dominion.o rngs.o $(CFLAGS)

tests.out: feastTest.c adventurerTest.c smithyTest.c treasureMapTest.c randomSmithyTest.c randomTreasureMapTest.c dominion.c rngs.c
	echo "Result for running Dominion tests:" > tests.out
	echo "feastTest.c:" >> tests.out
	gcc -o feastTest dominion.c feastTest.c rngs.c $(CFLAGS)
	./feastTest >> tests.out
	gcov feastTest.c >> tests.out
	echo "adventurerTest:" >> tests.out
	echo "adventurerTest.c:" >> tests.out
	gcc -o adventurerTest dominion.c adventurerTest.c rngs.c $(CFLAGS)
	./adventurerTest >> tests.out
	gcov adventurerTest.c >> tests.out
	echo "smithyTest:" >> tests.out
	echo "smithyTest.c:" >> tests.out
	gcc -o smithyTest dominion.c smithyTest.c rngs.c $(CFLAGS)
	./smithyTest >> tests.out
	gcov smithyTest.c >> tests.out
	echo "treasureMapTest:" >> tests.out
	echo "treasureMapTest.c:" >> tests.out
	gcc -o treasureMapTest dominion.c treasureMapTest.c rngs.c $(CFLAGS)
	./treasureMapTest >> tests.out
	gcov treasureMapTest.c >> tests.out
	echo "randomSmithyTest:" >> tests.out
	echo "randomSmithyTest.c:" >> tests.out
	gcc -o randomSmithyTest dominion.c randomSmithyTest.c rngs.c $(CFLAGS)
	./randomSmithyTest >> tests.out
	gcov randomSmithyTest.c >> tests.out
	echo "randomTreasureMapTest:" >> tests.out
	echo "randomTreasureMapTest.c:" >> tests.out
	gcc -o randomTreasureMapTest dominion.c randomTreasureMapTest.c rngs.c $(CFLAGS)
	./randomTreasureMapTest >> tests.out
	gcov randomTreasureMapTest.c >> tests.out 


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player 

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe
