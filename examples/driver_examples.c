/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

static void button_on_PD0_pressed(void)
{
}
static void button_on_PD7_pressed(void)
{
}
static void button_on_PD8_pressed(void)
{
}
static void button_on_PD9_pressed(void)
{
}

/**
 * Example of using HALL_IRQ_0
 */
void HALL_IRQ_0_example(void)
{
	ext_irq_register(PIO_PD0_IDX, button_on_PD0_pressed);
	ext_irq_register(PIO_PD7_IDX, button_on_PD7_pressed);
	ext_irq_register(PIO_PD8_IDX, button_on_PD8_pressed);
	ext_irq_register(PIO_PD9_IDX, button_on_PD9_pressed);
}

static void button_on_PA5_pressed(void)
{
}

/**
 * Example of using GPIOX_INT
 */
void GPIOX_INT_example(void)
{
	ext_irq_register(PIO_PA5_IDX, button_on_PA5_pressed);
}

void I2C_0_example(void)
{
	struct io_descriptor *I2C_0_io;

	i2c_m_sync_get_io_descriptor(&I2C_0, &I2C_0_io);
	i2c_m_sync_enable(&I2C_0);
	i2c_m_sync_set_slaveaddr(&I2C_0, 0x12, I2C_M_SEVEN);
	io_write(I2C_0_io, (uint8_t *)"Hello World!", 12);
}

void delay_example(void)
{
	delay_ms(5000);
}
