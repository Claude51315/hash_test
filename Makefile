
N=100000
EXEC=gen_data md5 crc32_1 crc32_2 crc32_5 crc32_10 adler sha
CC=gcc
CFLAG= -g

all: ${EXEC}
gen_data: gen_data.c 
	${CC} $^ -o $@ -DN=${N}

crc32_1: main.c crc32_custom.c
	${CC} ${CFLAG}  main.c crc32_custom.c -DCRC32 -DN=${N} -DSTRIPE=1 -o $@
crc32_2: main.c crc32_custom.c
	${CC} ${CFLAG}  main.c crc32_custom.c -DCRC32 -DN=${N} -DSTRIPE=2 -o $@
crc32_5: main.c crc32_custom.c
	${CC} ${CFLAG}  main.c crc32_custom.c -DCRC32 -DN=${N} -DSTRIPE=5 -o $@
crc32_10: main.c crc32_custom.c
	${CC} ${CFLAG}  main.c crc32_custom.c -DCRC32 -DN=${N} -DSTRIPE=10 -o $@
md5: main.c md5_custom.c
	${CC} ${CFLAG}  main.c md5_custom.c -DMD5 -DN=${N} -o $@
adler: main.c adler_custom.c adler32.c
	${CC} ${CFLAG}  main.c adler_custom.c adler32.c -DADLER -DN=${N} -o $@
sha: main.c sha1.c sha1_custom.c
	${CC} ${CFLAG}  main.c sha1_custom.c sha1.c -DSHA1 -DN=${N} -o $@



.phony: clean test

clean: 
	rm ${EXEC} *.txt *.out

test: all
	./gen_data
	cat data.out | sort | uniq > data.txt
	@rm data.out
	./crc32_1 data.txt | sort | uniq -dc > crc1.out
	./crc32_2 data.txt | sort | uniq -dc > crc2.out
	./crc32_5 data.txt | sort | uniq -dc > crc5.out
	./crc32_10 data.txt | sort | uniq -dc > crc10.out
	./md5 data.txt | sort | uniq -dc > md5.out
	./adler data.txt | sort | uniq -dc > adler.out
	./sha data.txt | sort | uniq -dc > sha.out
	tail *.out
