#ifndef MCP3008_h
#define MCP3008_h

#include "pico/stdlib.h"
#include "hardware/spi.h"

class MCP3008
{
  public:
    MCP3008(int clockpin, int mosipin, int misopin, int cspin,int spi, int baudrate);
    uint16_t readADC(uint8_t channel);
    void initializeMCP();
    void deinitializeMCP();
    float calculate(float vin, float vref);
  private:
      int _clockpin, _mosipin, _misopin, _cspin, _spi;
      int _baudRate;
      spi_inst_t *spi;
};


#endif