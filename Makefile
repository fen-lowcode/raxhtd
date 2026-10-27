make:
	gcc src/main.c -o raxhtd -flto -masm=intel -nostdlib -ffreestanding  ./lib/* -g
