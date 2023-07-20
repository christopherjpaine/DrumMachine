
/* == INCLUDES == */

/* == CONFIGURATION == */

/* Number of LEDS */
#define WS2812B_NUMBER_OF_LEDS 

/* == INTERFACE DEFINES/TYPES/MACROS == */

/* == INTERFACE FUNCTIONS == */

/* Sets up the timer peripheral and start DMA */
void ws2812b_init();

/* */
void ws2812b_set_pixel(uint8_t n, uint32_t grb, uint32_t mask);
