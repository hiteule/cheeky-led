#ifndef H_CHEEKY_LED
#define H_CHEEKY_LED

#define VENDOR 0x1d34
#define PRODUCT 0x0013
#define SHM_SIZE 1024
#define SHM_KEY "cheekyled_key"
#define LEDSX 21
#define LEDSY 7
#define FONTX 5
#define FONTY 7

struct ledpkt {
    unsigned char brightness;
    unsigned char row;
    unsigned char data1[3];
    unsigned char data2[3];
};

struct ledfont {
    int dispwidth;
    int dispheight;
    char data[256][FONTY];
};

struct ledscreen {
    libusb_device_handle *handle;
    int brightness;
    int scrolldelay;
    int led[LEDSX][LEDSY];
    struct ledfont *font;
};

struct ledfont *initfont(void);

void send_screen(struct ledscreen *disp);
void clear_screen(struct ledscreen *disp);
int open_usbdev(struct ledscreen *disp);
void close_usbdev(struct ledscreen *disp);
void scroll(struct ledscreen *disp);
void printchar(struct ledscreen *disp, char c, int xloc);
void scrollchar(struct ledscreen *disp, char ch);
void scrollmsg(struct ledscreen *disp, char* buf);
char *get_message();
struct ledfont *initfont();

#endif