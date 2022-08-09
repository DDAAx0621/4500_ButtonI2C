#include <atmel_start.h>

uint8_t debugHOLD;

// STRUCTS FOR I2C IO
struct io_descriptor *i2c_bus_io;


#define GPIOX_1_ADDR	0x38 //AD0 -> GND | AD1 -> GND | AD2 -> GND | #NOTE THIS IS FOR PCA9674A
#define GPIOX_2_ADDR	0x39 //AD0 -> VCC | AD1 -> GND | AD2 -> GND | #NOTE THIS IS FOR PCA9674A
#define GPIOX_3_ADDR	0x3A //AD0 -> GND | AD1 -> VCC | AD2 -> GND | #NOTE THIS IS FOR PCA9674A
#define GPIOX_4_ADDR	0x3B //AD0 -> VCC | AD1 -> VCC | AD2 -> GND	| #NOTE THIS IS FOR PCA9674A
#define EEPROM_ADDR		0x50 //AD0 -> GND | AD1 -> GND | AD2 -> GND | 
#define AS5600_ADDR		0x6D // NOT USER SETTABLE

// MACROS FOR SETTING GPIOX PIN STATES
#define SET_BIT( val, pos) (val |= 1U << pos)
#define CLEAR_BIT(val, pos) (val &= (~(1U << pos)))


// DEFINING COMMANDS
	// PCA9674A COMMANDS
	#define PCA9674A_RST	0x00
	#define PCA9674A_SAO	0xFF
	#define PCA9674A_GID	0x7C
	#define PCA9674A_CLP	0x00
	
	// EEPROM COMMANDS
	
	void Read_EEPROM(uint16_t d_ADDR, uint16_t *data);
	//void Write_EEPROM(uint16_t d_ADDR, uint16_t *data);
	
	// AS5600 COMMANDS
	
// GENERAL I2C FUNCTIONS
void InitI2C_0();
void I2C_0_write(uint8_t address, uint8_t data, uint8_t *buffer, uint8_t buff_size);
void I2C_0_read(uint8_t address, uint8_t data, uint8_t *buffer, uint8_t buff_size);
void GPIOx_I2C_0_read(uint8_t address, uint8_t *data, uint16_t buff_size);
// PC9674A FUNCTIONS

// INTERRUPT RESULT
static void GpioX_INT_Triggered(void);

static void Hall_1_Trig(void);
static void Hall_2_Trig(void);
static void Hall_3_Trig(void);

// INTERRUPT FLAGS


// ACTION FUNCTIONS
void GPIOxInt_True();





bool gpioX_FLAG = false; 

// GPIOX RECIEVER VALUES

	//uint16_t gpioX_RX;
	
	uint8_t gpioX1_prev;
	uint8_t gpioX2_prev;
	uint8_t gpioX1_new;
	uint8_t gpioX2_new;
	uint8_t gpioX_int_CYC = 0;
	
	uint8_t dbgGPIOx_CNT = 0;





int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();
	
	
	//struct io_descriptor *I2C_0_io;
	uint8_t		command_data  = 0;
	
	uint8_t gpioX_POS = 0;
	uint8_t gpioX_VAL = 0;

	
	
	bool on_CYC = true;
	
	bool wifien_FLAG = false;
	bool press_FLAG1 = false;
	bool press_FLAG2 = false;
	bool press_FLAG3 = false;
	bool press_FLAG4 = false;
	bool press_FLAG5 = false;
	bool press_FLAG6 = false;
	
	uint16_t eeprom_DATA = 0xffff;
	
		
	InitI2C_0();
	
	
	
	I2C_0_write((uint8_t)GPIOX_1_ADDR, (uint8_t)PCA9674A_RST, (uint8_t)PCA9674A_RST,1);
	I2C_0_write((uint8_t)GPIOX_2_ADDR, (uint8_t)PCA9674A_RST, (uint8_t)PCA9674A_RST,1);
	I2C_0_write((uint8_t)GPIOX_2_ADDR, (uint8_t)PCA9674A_SAO, (uint8_t)PCA9674A_SAO,1);
	
	// INTERUPT HANDLER FUNCTION
	ext_irq_register(PIO_PA5_IDX, GpioX_INT_Triggered);
	ext_irq_register(PIO_PD7_IDX, Hall_3_Trig);
	ext_irq_register(PIO_PD8_IDX, Hall_2_Trig);
	ext_irq_register(PIO_PD9_IDX, Hall_1_Trig);
	ext_irq_register(PIO_PD0_IDX, Hall_1_Trig);
	
	

	/* Replace with your application code */
	while (1) 
	{
		
		Read_EEPROM(0x10, eeprom_DATA);
		
		debugHOLD++;
		
		dbgGPIOx_CNT = 0;
		/*
		if(gpio_get_pin_level(HALL_1) == true)
		{
			gpio_toggle_pin_level(WIFIEN);
		}
		*/
		
		
		if (gpioX2_new != 0xff)
		{
			//debugHOLD++;
			//Relay_Trip(gpioX2_new);
			
			uint8_t cmd  = 0xff ;
	
			switch (gpioX2_new)
			{
				case 0xff:
					break;
				case 0xfe:
					cmd = 0xdf;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					delay_ms(1000);
					cmd  =  0xff;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					break;
				case 0xf7:
					cmd = 0xdf;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					delay_ms(1000);
					cmd  =  0xff;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					break;
				case 0xfd:
					cmd = 0xdf;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					delay_ms(1000);
					cmd  =  0xff;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					break;
				case 0xfb:
					cmd = 0xdf;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					delay_ms(1000);
					cmd  =  0xff;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					break;
				case 0xbf:
					cmd = 0x7f;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					delay_ms(1000);
					cmd  =  0xff;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					break;
				case 0xef:
					cmd = 0x7f;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					delay_ms(1000);
					cmd  =  0xff;
					I2C_0_write((uint8_t)GPIOX_2_ADDR, cmd, cmd,1);
					break;
			}
			
			
			
			
			gpioX2_new = 0xff;
		}
		else
			;
		
		//debugHOLD++;
		
		if (gpioX_FLAG == true)
		{
			GPIOxInt_True();
			gpioX_FLAG = false;
		}
		else
			gpioX_int_CYC = 0;
		
		
		
		
		if (on_CYC == true)	
			gpioX_VAL = SET_BIT(gpioX_VAL,gpioX_POS);
		else
			gpioX_VAL  = CLEAR_BIT(gpioX_VAL,gpioX_POS);
			
		uint8_t buf_val = gpioX_VAL;
				 
		
		I2C_0_write((uint8_t)GPIOX_1_ADDR, gpioX_VAL, gpioX_VAL,1);
		
		delay_ms(100);
		//command_data[0] = 0x00;
			
		if (gpioX_POS < 8)
			gpioX_POS++;
		else
		{
			gpioX_POS = 0;
			
			if (on_CYC == true)
				on_CYC = false;
			else
				on_CYC = true;
		}
		
		
		
	}
}


// GENERAL I2C FUNCTIONS
void InitI2C_0()
{
	i2c_m_sync_get_io_descriptor(&I2C_0, &i2c_bus_io);
	
	i2c_m_sync_enable(&I2C_0);
}

void I2C_0_write(uint8_t address, uint8_t data, uint8_t *buffer, uint8_t buff_size)
{
	i2c_m_sync_set_slaveaddr(&I2C_0, address, I2C_M_SEVEN);
	
	i2c_m_sync_cmd_write(&I2C_0,data, &buffer, buff_size);
	//delay_ms(1);	
}
//int32_t i2c_m_sync_cmd_write(struct i2c_m_sync_desc *i2c, uint8_t reg, uint8_t *buffer, uint8_t length)

void I2C_0_read(uint8_t address, uint8_t data, uint8_t *buffer, uint8_t buff_size)
{
	i2c_m_sync_set_slaveaddr(&I2C_0, address, I2C_M_SEVEN);
	
	i2c_m_sync_cmd_read(&I2C_0, data, &buffer, buff_size);
}

void GPIOx_I2C_0_read(uint8_t address, uint8_t *data, uint16_t buff_size)
{
	i2c_m_sync_set_slaveaddr(&I2C_0, address, I2C_M_SEVEN);
	
	//i2c_m_sync_cmd_read(&I2C_0, data, &buffer, buff_size);
	
	io_read(i2c_bus_io, &data, buff_size);
	
	//debugHOLD++;
	delay_ms(1);
}

//int32_t i2c_m_sync_cmd_read(struct i2c_m_sync_desc *i2c, uint8_t reg, uint8_t *buffer, uint8_t length)







// PCA9674 FUNCTIONS


// INTERUPT RESULT
static void GpioX_INT_Triggered(void)
{
	gpioX_FLAG = true;
	
}


void GPIOxInt_True()
{
	
		uint8_t buffer[2] ;
		for (int i = 0 ; i < 3 ; i++)
		{
			i2c_m_sync_set_slaveaddr(&I2C_0, GPIOX_1_ADDR, I2C_M_SEVEN);
			io_read(i2c_bus_io, &buffer[0], 1);
		
			if (gpioX_int_CYC == 0)
			{
				gpioX1_prev = gpioX1_new;
				gpioX1_new = buffer[0];
			}
			delay_ms(1);
		}
		
		//I2C_0_write((uint8_t)GPIOX_1_ADDR, (uint8_t)PCA9674A_RST, (uint8_t)PCA9674A_RST,1);
		//I2C_0_write((uint8_t)GPIOX_1_ADDR, (uint8_t)PCA9674A_SAO, (uint8_t)PCA9674A_SAO,1);
		
		
		for (int i = 0 ; i < 3 ; i++)
		{	
			
			i2c_m_sync_set_slaveaddr(&I2C_0, GPIOX_2_ADDR, I2C_M_SEVEN);
			io_read(i2c_bus_io, &buffer[1], 1);
		
			if (gpioX_int_CYC == 0)
			{
				gpioX2_prev = gpioX2_new;
				gpioX2_new = buffer[1];
			}
			delay_ms(1);

		}
			if (gpioX_int_CYC >= 1)
			{
				gpioX_int_CYC = 0;
			}
			else
			{
				gpioX_int_CYC++;
			}
	
}

static void Hall_1_Trig(void)
{
	gpio_toggle_pin_level(WIFIEN);
	debugHOLD++;
	
}

static void Hall_2_Trig(void)
{
	gpio_toggle_pin_level(WIFIEN);
	debugHOLD++;
}

static void Hall_3_Trig(void)
{
	gpio_toggle_pin_level(WIFIEN);
	debugHOLD++;
}

// EEPROM FUNCTIONS

void Read_EEPROM(uint16_t d_ADDR, uint16_t *data)
{	
	i2c_m_sync_set_slaveaddr(&I2C_0, EEPROM_ADDR, I2C_M_SEVEN);
	i2c_m_sync_cmd_read(&I2C_0, &data, &data, 1);
}
/*
void Write_EEPROM(uint16_t d_ADDR, uint16_t *data)
{
	i2c_m_sync_set_slaveaddr(&I2C_0, EEPROM_ADDR, I2C_M_SEVEN);
}
*/