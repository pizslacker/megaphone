megaphone: megaphone.c
	gcc -Wall -Wextra -O3 -o megaphone megaphone.c
	strip megaphone

clean:
	rm -f megaphone
