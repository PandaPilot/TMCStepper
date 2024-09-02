/**
 * Author Teemu Mäntykallio
 * Initializes the library and runs the stepper
 * motor in alternating directions.
 */

#include <TMCStepper.h>

#define EN_PIN           38 // Enable
#define DIR_PIN          55 // Direction
#define STEP_PIN         54 // Step

#define SERIAL_PORT uart1 // TMC2208/TMC2224 HardwareSerial port
#define DRIVER_ADDRESS1 0b00 // TMC2209 Driver address according to MS1 and MS2
#define DRIVER_ADDRESS2 0b00
#define DRIVER_ADDRESS3 0b00
// Define UART port and pins for the Raspberry Pi Pico
#define UART_ID          uart1
#define TX_PIN           40
#define RX_PIN           41
#define BAUD_RATE        115200

#define R_SENSE 0.11f // Match to your driver
                      // SilentStepStick series use 0.11
                      // UltiMachine Einsy and Archim2 boards use 0.2
                      // Panucatt BSD2660 uses 0.1
                      // Watterott TMC5160 uses 0.075

TMC2209Stepper driver1(UART_ID, R_SENSE, DRIVER_ADDRESS1);
TMC2209Stepper driver2(UART_ID, R_SENSE, DRIVER_ADDRESS2);
TMC2209Stepper driver3(UART_ID, R_SENSE, DRIVER_ADDRESS3);

void setup() {
    // Initialize UART
    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(RX_PIN, GPIO_FUNC_UART);

    // Initialize GPIO pins
    gpio_init(EN_PIN);
    gpio_set_dir(EN_PIN, GPIO_OUT);
    gpio_put(EN_PIN, 0);  // Enable driver

    gpio_init(STEP_PIN);
    gpio_set_dir(STEP_PIN, GPIO_OUT);

    gpio_init(DIR_PIN);
    gpio_set_dir(DIR_PIN, GPIO_OUT);

    // Initialize TMC2209Stepper driver
    driver1.begin();
    driver1.toff(5);
    driver1.rms_current(600);
    driver1.microsteps(16);
    driver1.pwm_autoscale(true);
    // Initialize TMC2209Stepper driver
    driver2.begin();
    driver2.toff(5);
    driver2.rms_current(600);
    driver2.microsteps(16);
    driver2.pwm_autoscale(true);
    // Initialize TMC2209Stepper driver
    driver3.begin();
    driver3.toff(5);
    driver3.rms_current(600);
    driver3.microsteps(16);
    driver3.pwm_autoscale(true);
}

bool shaft = false;

void loop() {
    // Run 5000 steps and switch direction
    for (uint16_t i = 5000; i > 0; i--) {
        gpio_put(STEP_PIN, 1);
        sleep_us(160);
        gpio_put(STEP_PIN, 0);
        sleep_us(160);
    }
    shaft = !shaft;
    driver1.shaft(shaft);
}

int main() {
    setup();
    while (true) {
        loop();
    }
}