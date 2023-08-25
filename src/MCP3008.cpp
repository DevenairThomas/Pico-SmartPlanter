#include "MCP3008.h"

MCP3008::MCP3008(int clockpin, int mosipin, int misopin, int cspin, int SPI, int baudRate) {
    
    // define SPI outputs and inputs for bitbanging
    
    _cspin = cspin;
    _clockpin = clockpin;
    _mosipin = mosipin;
    _misopin = misopin;
    _spi = SPI;
    _baudRate = baudRate;

    gpio_init(_cspin);

    //gpio_set_function(_cspin,GPIO_FUNC_SPI);
    gpio_set_function(_clockpin,GPIO_FUNC_SPI);
    gpio_set_function(_mosipin,GPIO_FUNC_SPI);
    gpio_set_function(_misopin,GPIO_FUNC_SPI);

    initializeMCP();
    
    if(_spi == 0){spi = spi0;}
    if(_spi == 1){spi = spi1;}
}
void MCP3008::initializeMCP(){
    spi_init(spi,_baudRate);
}
void MCP3008::deinitializeMCP(){
    spi_deinit(spi);
}
uint16_t MCP3008::readADC(uint8_t channel) {
    if (channel > 7) return 0;  // Invalid channel

    uint8_t readBuffer[2];
    uint8_t writeBuffer[3];
    writeBuffer[0] = 0x01;
    writeBuffer[1] = (channel << 4);
    writeBuffer[2] = 0x00;

    gpio_pull_up(_cspin);
    gpio_pull_down(_cspin);

    spi_write_read_blocking(this->spi, writeBuffer,readBuffer, sizeof(writeBuffer));

    gpio_pull_up(_cspin);
    return (readBuffer[1]<<8| readBuffer[2]);
}
float MCP3008::calculate(float vin, float vref){
    return (1024 * vin)/vref;
}