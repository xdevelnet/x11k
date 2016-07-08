all:
	c99 x11k.c -o x11k -lX11 -Wall
musl:
	musl-gcc x11k.c -o x11k -lX11 -std=c99 -Wall
