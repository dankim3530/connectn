connectn.out: board.o game_play.o input_validation.o main.o win.o
	gcc -g -Wall -Werror -o connectn.out board.o game_play.o input_validation.o main.o win.o
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c
input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c
main.o: main.c game_play.h
	gcc -g -Wall -Werror -c main.c
game_play.o: game_play.c game_play.h board.h win.h
	gcc -g -Wall -Werror -c game_play.c
win.o: win.c win.h
	gcc -g -Wall -Werror -c win.c
clean:
	rm -rf *.o *.out
