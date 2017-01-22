#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <string.h>
#include <inttypes.h>
#include <fstream>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

using std::string;
using namespace std;

#include "serial.h"
Serial_jh *serial;
Serial_jh *serial_quit;
void quit_handler( int sig );

int main(void)
{
char buff[256];
int ret;
cout<<"teststrart";
Serial_jh serial("/dev/ttyUSB0",57600);
serial_quit = &serial;
signal(SIGINT,quit_handler);
serial.start();
cout<<"check";
while(1)
{
//serial.write_("a123");
sleep(1);
ret=serial.read_(buff,sizeof(buff));
		if (ret <= 0) {
			printf("No data available \r\n");
		} else {
			printf("Serial data received:\r\n");
			printf("%s\r\n", buff);
		}
}
serial.stop();

}
void
quit_handler( int sig )
{
        printf("\n");
        printf("TERMINATING AT USER REQUEST\n");
        printf("\n");

        // serial port
        try {
                serial_quit->handle_quit(sig);
        }
        catch (int error){}

        // end program here
        exit(0);

}

