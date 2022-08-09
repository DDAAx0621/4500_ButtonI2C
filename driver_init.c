/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <hal_init.h>
#include <hpl_pmc.h>
#include <peripheral_clk_config.h>
#include <utils.h>

struct i2c_m_sync_desc I2C_0;

void HALL_IRQ_0_init(void)
{

	// Set pin direction to input
	gpio_set_pin_direction(Button_0, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(Button_0,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(Button_0, GPIO_PIN_FUNCTION_OFF);

	// Set pin direction to input
	gpio_set_pin_direction(HALL_3, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(HALL_3,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(HALL_3, GPIO_PIN_FUNCTION_OFF);

	// Set pin direction to input
	gpio_set_pin_direction(HALL_2, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(HALL_2,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(HALL_2, GPIO_PIN_FUNCTION_OFF);

	// Set pin direction to input
	gpio_set_pin_direction(HALL_1, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(HALL_1,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(HALL_1, GPIO_PIN_FUNCTION_OFF);
}

void GPIOX_INT_init(void)
{

	// Set pin direction to input
	gpio_set_pin_direction(nGPIOX_INT, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(nGPIOX_INT,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(nGPIOX_INT, GPIO_PIN_FUNCTION_OFF);
}

void I2C_0_PORT_init(void)
{

	gpio_set_pin_function(SCL0, MUX_PA4A_TWIHS0_TWCK0);

	gpio_set_pin_function(SDA0, MUX_PA3A_TWIHS0_TWD0);
}

void I2C_0_CLOCK_init(void)
{
	_pmc_enable_periph_clock(ID_TWIHS0);
}

void I2C_0_init(void)
{
	I2C_0_CLOCK_init();

	i2c_m_sync_init(&I2C_0, TWIHS0);

	I2C_0_PORT_init();
}

void delay_driver_init(void)
{
	delay_init(SysTick);
}

void system_init(void)
{
	init_mcu();

	_pmc_enable_periph_clock(ID_PIOA);

	_pmc_enable_periph_clock(ID_PIOD);

	/* Disable Watchdog */
	hri_wdt_set_MR_WDDIS_bit(WDT);

	/* GPIO on PA7 */

	// Set pin direction to input
	gpio_set_pin_direction(Button_2, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(Button_2,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(Button_2, GPIO_PIN_FUNCTION_OFF);

	/* GPIO on PA24 */

	// Set pin direction to input
	gpio_set_pin_direction(Button_4, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(Button_4,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(Button_4, GPIO_PIN_FUNCTION_OFF);

	/* GPIO on PD21 */

	gpio_set_pin_level(WIFIEN,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(WIFIEN, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(WIFIEN, GPIO_PIN_FUNCTION_OFF);

	/* GPIO on PD22 */

	// Set pin direction to input
	gpio_set_pin_direction(Button_5, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(Button_5,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(Button_5, GPIO_PIN_FUNCTION_OFF);

	/* GPIO on PD24 */

	// Set pin direction to input
	gpio_set_pin_direction(Button_3, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(Button_3,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(Button_3, GPIO_PIN_FUNCTION_OFF);

	/* GPIO on PD31 */

	// Set pin direction to input
	gpio_set_pin_direction(Button_1, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(Button_1,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(Button_1, GPIO_PIN_FUNCTION_OFF);

	HALL_IRQ_0_init();
	GPIOX_INT_init();

	I2C_0_init();

	delay_driver_init();

	ext_irq_init();
}
