all: cheeky-led
cheeky-led: cheeky-led.c
	gcc -o cheeky-led cheeky-led.c -lusb-1.0 -I/usr/local/include/libusb-1.0
clean:	
	rm cheeky-led