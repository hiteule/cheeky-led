all: cheeky-led
cheeky-led: cheeky-led.c
ifeq ($(shell uname), Linux)
	gcc -o cheeky-led cheeky-led.c -lusb-1.0 -I/usr/include/libusb-1.0
else
	gcc -o cheeky-led cheeky-led.c -lusb-1.0 -I/usr/local/include/libusb-1.0
endif
clean:
	rm cheeky-led