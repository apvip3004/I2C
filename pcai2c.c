void sendI2C(void)
{
/* Set register MODE1 (default SLEEP = 1) */
I2C_start(I2C1, SLAVE_ADDRESS_LED<<1, I2C_Direction_Transmitter); 
I2C_write(I2C1, 0x00); // MODE1
I2C_write(I2C1, 0x00); // SLEEP = 0
I2C_stop(I2C1); 
/* Set Register LEDOUT0 to 10101010 */
I2C_start(I2C1, SLAVE_ADDRESS_LED<<1, I2C_Direction_Transmitter); 
I2C_write(I2C1, LEDOUT0); // LEDOUT
I2C_write(I2C1, 0xAA);
I2C_stop(I2C1);
/* Set register PWM0 to value 200 */
I2C_start(I2C1, SLAVE_ADDRESS_LED<<1, I2C_Direction_Transmitter);
I2C_write(I2C1, PWM0);
I2C_write(I2C1, 0xC8);
I2C_stop(I2C1);
}