/**
  ******************************************************************************
  * ______  _                             ___  ___        _               
  * | ___ \(_)                            |  \/  |       | |              
  * | |_/ / _  _ __    __ _  _ __  _   _  | .  . |  __ _ | | __ ___  _ __ 
  * | ___ \| || '_ \  / _` || '__|| | | | | |\/| | / _` || |/ // _ \| '__|
  * | |_/ /| || | | || (_| || |   | |_| | | |  | || (_| ||   <|  __/| |   
  * \____/ |_||_| |_| \__,_||_|    \__, | \_|  |_/ \__,_||_|\_\\___||_|   
  *                                 __/ |                                 
  *                                |___/                                  
  *                                                                       
  * Copyright (C) 2019 Binary Maker - All Rights Reserved
  *
  * This program and the accompanying materials are made available
  * under the terms described in the LICENSE file which accompanies
  * this distribution.
  * Written by Binary Maker <https://github.com/binarymaker>
  ******************************************************************************
  */

#include "unity.h"
#include "mcu.h"

#include "mcu-cfg.h"
#include "gpio.h"

void
setUp()
{
  PORTB = 0x00;
}

void
tearDown()
{

}

/* -------------------------------------------------------------------------- */
void
test_PORTB_pin_direction_input()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_B0; pin_8u <= P_B7; pin_8u++)
  {
    /* Ensure known test state
     * Assign direction reg default high 
     */
    DDRB = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinDirection(pin_8u, GPIO_PIN_INPUT);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8( ~BIT(bit_pos), DDRB);

    bit_pos++;
  }
}

void
test_PORTC_pin_direction_input()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_C0; pin_8u <= P_C7; pin_8u++)
  {
    /* Ensure known test state */
    DDRC = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinDirection(pin_8u, GPIO_PIN_INPUT);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8( ~BIT(bit_pos), DDRC);

    bit_pos++;
  }
}

void
test_PORTD_pin_direction_input()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_D0; pin_8u <= P_D7; pin_8u++)
  {
    /* Ensure known test state */
    DDRD = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinDirection(pin_8u, GPIO_PIN_INPUT);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8( ~BIT(bit_pos), DDRD);

    bit_pos++;
  }
}

/* -------------------------------------------------------------------------- */

void
test_PORTB_pin_direction_output()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_B0; pin_8u <= P_B7; pin_8u++)
  {
    /* Ensure known test state */
    DDRB = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinDirection(pin_8u, GPIO_PIN_OUTPUT);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8(BIT(bit_pos), DDRB);

    bit_pos++;
  }
}

void
test_PORTC_pin_direction_output()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_C0; pin_8u <= P_C7; pin_8u++)
  {
    /* Ensure known test state */
    DDRC = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinDirection(pin_8u, GPIO_PIN_OUTPUT);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8(BIT(bit_pos), DDRC);

    bit_pos++;
  }
}

void
test_PORTD_pin_direction_output()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_D0; pin_8u <= P_D7; pin_8u++)
  {
    /* Ensure known test state */
    DDRD = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinDirection(pin_8u, GPIO_PIN_OUTPUT);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8(BIT(bit_pos), DDRD);

    bit_pos++;
  }
}
/* -------------------------------------------------------------------------- */

void
test_PORTB_pin_output_write_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_B0; pin_8u <= P_B7; pin_8u++)
  {
    /* Ensure known test state */
    PORTB = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinWrite(pin_8u, HIGH);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8(BIT(bit_pos), PORTB);

    bit_pos++;
  }
}

void
test_PORTC_pin_output_write_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_C0; pin_8u <= P_C7; pin_8u++)
  {
    /* Ensure known test state */
    PORTC = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinWrite(pin_8u, HIGH);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8(BIT(bit_pos), PORTC);

    bit_pos++;
  }
}

void
test_PORTD_pin_output_write_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_D0; pin_8u <= P_D7; pin_8u++)
  {
    /* Ensure known test state */
    PORTD = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinWrite(pin_8u, HIGH);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8(BIT(bit_pos), PORTD);

    bit_pos++;
  }
}

/* -------------------------------------------------------------------------- */

void
test_PORTB_pin_output_write_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_B0; pin_8u <= P_B7; pin_8u++)
  {
    /* Ensure known test state */
    PORTB = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinWrite(pin_8u, LOW);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8( ~BIT(bit_pos), PORTB);

    bit_pos++;
  }
}

void
test_PORTC_pin_output_write_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_C0; pin_8u <= P_C7; pin_8u++)
  {
    /* Ensure known test state */
    PORTC = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinWrite(pin_8u, LOW);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8( ~BIT(bit_pos), PORTC);

    bit_pos++;
  }
}

void
test_PORTD_pin_output_write_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_D0; pin_8u <= P_D7; pin_8u++)
  {
    /* Ensure known test state */
    PORTD = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinWrite(pin_8u, LOW);

    /* Verify test results */
    TEST_ASSERT_EQUAL_INT8( ~BIT(bit_pos), PORTD);

    bit_pos++;
  }
}

/* -------------------------------------------------------------------------- */

void
test_PORTB_pin_output_read_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_B0; pin_8u <= P_B7; pin_8u++)
  {
    /* Ensure known test state */
    PINB = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    bool_et pin_value_b = GPIO_PinRead(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL(HIGH, pin_value_b);

    bit_pos++;
  }
}

void
test_PORTC_pin_output_read_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_C0; pin_8u <= P_C7; pin_8u++)
  {
    /* Ensure known test state */
    PINC = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    bool_et pin_value_b = GPIO_PinRead(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL(HIGH, pin_value_b);

    bit_pos++;
  }
}

void
test_PORTD_pin_output_read_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_D0; pin_8u <= P_D7; pin_8u++)
  {
    /* Ensure known test state */
    PIND = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    bool_et pin_value_b = GPIO_PinRead(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL(HIGH, pin_value_b);

    bit_pos++;
  }
}
/* -------------------------------------------------------------------------- */

void
test_PORTB_pin_output_read_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_B0; pin_8u <= P_B7; pin_8u++)
  {
    /* Ensure known test state */
    PINB = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    bool_et pin_value_b = GPIO_PinRead(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL(LOW, pin_value_b);

    bit_pos++;
  }
}

void
test_PORTC_pin_output_read_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_C0; pin_8u <= P_C7; pin_8u++)
  {
    /* Ensure known test state */
    PINC = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    bool_et pin_value_b = GPIO_PinRead(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL(LOW, pin_value_b);

    bit_pos++;
  }
}

void
test_PORTD_pin_output_read_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_D0; pin_8u <= P_D7; pin_8u++)
  {
    /* Ensure known test state */
    PIND = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    bool_et pin_value_b = GPIO_PinRead(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL(LOW, pin_value_b);

    bit_pos++;
  }
}

/* -------------------------------------------------------------------------- */

void
test_PORTB_pin_toggle_low_to_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_B0; pin_8u <= P_B7; pin_8u++)
  {
    /* Ensure known test state */
    PORTB = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinToggle(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL_UINT8( BIT(bit_pos), PORTB);

    bit_pos++;
  }
}

void
test_PORTB_pin_toggle_high_to_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_B0; pin_8u <= P_B7; pin_8u++)
  {
    /* Ensure known test state */
    PORTB = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinToggle(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL_UINT8( ~BIT(bit_pos), PORTB);

    bit_pos++;
  }
}

void
test_PORTC_pin_toggle_low_to_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_C0; pin_8u <= P_C7; pin_8u++)
  {
    /* Ensure known test state */
    PORTC = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinToggle(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL_UINT8( BIT(bit_pos), PORTC);

    bit_pos++;
  }
}

void
test_PORTC_pin_toggle_high_to_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_C0; pin_8u <= P_C7; pin_8u++)
  {
    /* Ensure known test state */
    PORTC = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinToggle(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL_UINT8( ~BIT(bit_pos), PORTC);

    bit_pos++;
  }
}

void
test_PORTD_pin_toggle_low_to_high()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_D0; pin_8u <= P_D7; pin_8u++)
  {
    /* Ensure known test state */
    PORTD = 0x00;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinToggle(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL_UINT8( BIT(bit_pos), PORTD);

    bit_pos++;
  }
}

void
test_PORTD_pin_toggle_high_to_low()
{
  uint8_t bit_pos;

  bit_pos = 0;
  for (uint8_t pin_8u = P_D0; pin_8u <= P_D7; pin_8u++)
  {
    /* Ensure known test state */
    PORTD = 0xFF;

    /* Setup expected function mock */

    /* Function under test */
    GPIO_PinToggle(pin_8u);

    /* Verify test results */
    TEST_ASSERT_EQUAL_UINT8( ~BIT(bit_pos), PORTD);

    bit_pos++;
  }
}