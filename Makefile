debug:
	gcc src/main.c -o raxhtd -g -static

release:
	gcc src/main.c -o raxhtd -03 -static