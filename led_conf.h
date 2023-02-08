int set_gpio(char pin, char led_stat);
int gpio_init();


static int GPIOExport(int pin);

static int GPIOUnexport(int pin);

static int GPIODirection(int pin, int dir);

static int GPIORead(int pin);

static int GPIOWrite(int pin, int value);


