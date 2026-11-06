debug:
	gcc src/main.c -o raxhtd -flto -masm=intel -nostdlib -ffreestanding ./lib/* -g -static

release:
	gcc src/main.c -o raxhtd -flto -masm=intel -nostdlib -ffreestanding ./lib/* -O3 -static