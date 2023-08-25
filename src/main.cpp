#include <stdio.h>
#include "pico/stdlib.h"
#include "MCP3008.h"

MCP3008 mcp(2, 3, 4, 5,0, 1350000);

int main() {
    stdio_init_all();
    const uint led_pin = 19; 

    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);

    mcp.initializeMCP();

    float calc = mcp.calculate(3.3,3.3);
    while (true)
    {
        uint8_t channel0 = 0;
        uint8_t channel1 = 1;
        uint16_t read0 = mcp.readADC(channel0);
        sleep_ms(500);
        uint16_t read1 = mcp.readADC(channel1);

        float voltageChannel_0 =( read0/calc);
        float voltageChannel_1 =( read1/calc);
        
        //printf("ON!\n");
        printf("0 = %f, 1= %f\n", voltageChannel_0, voltageChannel_1);
        //printf("0 = %d, 1 =%d\n", read0,read1);
        //gpio_put(led_pin,true);
        //sleep_ms(1000);
        //printf("OFF!\n");
        //gpio_put(led_pin,false);
        sleep_ms(100);
    }
}