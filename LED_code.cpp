#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "led_conf.h"

int main()
{
	 gpio_init();
	 while(1)
	 {
	 	set_gpio(1,1);
	 	set_gpio(2,0);
	 	sleep(1);
	 	set_gpio(1,0);
	 	set_gpio(2,1);
	 	sleep(1);
	 }
	
}
