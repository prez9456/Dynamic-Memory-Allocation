cc = gcc
OUT_EXE = Starter
FILES = Starter.c Executor.c
PAK = Executor.h README.txt
TAR_NAME = Andy-Donis_Paz-HW1.tar

build:
	$(cc) -o $(OUT_EXE) $(FILES)
package:
	tar cvzf $(TAR_NAME) $(FILES) $(PAK) Makefile
clean:
	rm -f $(OUT_EXE)
