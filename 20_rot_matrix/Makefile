CC = gcc
CFLAGS = -pedantic -std=gnu99 -Wall -Werror

rotate-matrix: rotate.o read-matrix.o
	$(CC) $(CFLAGS) -o rotate-matrix rotate.o read-matrix.o  # 正確的可執行文件名稱

rotate.o: rotate.c
	$(CC) $(CFLAGS) -c rotate.c -o rotate.o  # 正確編譯目標文件的命令

clean:
	rm -f *.o rotate-matrix  # 清理生成的文件
