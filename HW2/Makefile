all: simple_main coins_main coin_menu

simple_main: simple_main.cpp Coins.h
	g++ simple_main.cpp -o simple_main
coins_main: coins_main.cpp Coins.h
	g++ coins_main.cpp -o coins_main
coin_menu: coin_menu.cpp Coins.h
	g++ coin_menu.cpp -o coin_menu
clean:
	rm simple_main coins_main coin_menu
