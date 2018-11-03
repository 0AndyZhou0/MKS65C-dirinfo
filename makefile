compile : dirinfo.c
	gcc -o dirinfo dirinfo.c

run : 
	./dirinfo

check : dirinfo
	gcc -g dirinfo.c
	gdb ./a.out

clean :
	rm ./dirinfo ./a.out 
