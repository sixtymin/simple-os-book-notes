
mbr.o: mbr.S
	as -o mbr.o mbr.S

mbr: mbr.o
	ld --oformat binary -N -e start -Ttext 0x7c00 -o mbr mbr.o

run: mbr
	qemu-system-i386 -boot a -fda mbr

debug: mbr
	qemu-system-i386 -boot a -fda mbr -S -s
	sleep 2
	gdb -gui -x dbginit

clean:
	rm mbr.o mbr

