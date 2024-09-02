#include "SERIAL_SWITCH.h"

SSwitch::SSwitch(const uint16_t pin1, const uint16_t pin2, const uint8_t address) :
    p1(pin1), p2(pin2), addr(address)
{
    gpio_init(p1);
    gpio_set_dir(p1, GPIO_OUT);
    
    gpio_init(p2);
    gpio_set_dir(p2, GPIO_OUT);
}

void SSwitch::active() {
    gpio_put(p1, addr & 0b01 ? 1 : 0);
    gpio_put(p2, addr & 0b10 ? 1 : 0);
}