#ifndef MBED_GPIO_API_H
#define MBED_GPIO_API_H

#include <stdint.h>
#include "device.h"
#include "PinNames.h"
#include "stm32f4xx.h"                  // Device header

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup hal_gpio GPIO HAL functions
 * @{
 */

/** Set the given pin as GPIO
 *
 * @param pin The pin to be set as GPIO
 * @return The GPIO port mask for this pin
 **/
uint32_t gpio_set(PinName pin);

/** Initialize the GPIO pin
 *
 * @param obj The GPIO object to initialize
 * @param pin The GPIO pin to initialize
 */
void gpio_init(GPIO_TypeDef *obj, PinName pin);

/** Set the input pin mode
 *
 * @param obj  The GPIO object
 * @param mode The pin mode to be set
 */
void gpio_mode(GPIO_TypeDef *obj, PinMode mode);

/** Set the pin direction
 *
 * @param obj       The GPIO object
 * @param direction The pin direction to be set
 */
void gpio_dir(GPIO_TypeDef *obj, PinDirection direction);

/** Set the output value
 *
 * @param obj   The GPIO object
 * @param value The value to be set
 */
void gpio_write(GPIO_TypeDef *obj, int value)
	{
	//return (int)arm_gpio_read(obj->, ARM_GPIO_ACCESS_PIN,
   //                               obj->pin_number);
}

/** Read the input value
 *
 * @param obj The GPIO object
 * @return An integer value 1 or 0
 */
int gpio_read(GPIO_TypeDef *obj);
// the following functions are generic and implemented in the common gpio.c file
// TODO: fix, will be moved to the common gpio header file

/** Init the input pin and set mode to PullDefault
 *
 * @param obj The GPIO object
 * @param pin The pin name
 */
void gpio_init_in(GPIO_TypeDef* gpio, PinName pin);

/** Init the input pin and set the mode
 *
 * @param obj  The GPIO object
 * @param pin  The pin name
 * @param mode The pin mode to be set
 */
void gpio_init_in_ex(GPIO_TypeDef* gpio, PinName pin, PinMode mode);

/** Init the output pin as an output, with predefined output value 0
 *
 * @param obj The GPIO object
 * @param pin The pin name
 * @return An integer value 1 or 0
 */
void gpio_init_out(GPIO_TypeDef* gpio, PinName pin);

/** Init the pin as an output and set the output value
 *
 * @param obj   The GPIO object
 * @param pin   The pin name
 * @param value The value to be set
 */
void gpio_init_out_ex(GPIO_TypeDef* gpio, PinName pin, int value);

/** Init the pin to be in/out
 *
 * @param obj       The GPIO object
 * @param pin       The pin name
 * @param direction The pin direction to be set
 * @param mode      The pin mode to be set
 * @param value     The value to be set for an output pin
 */
void gpio_init_inout(GPIO_TypeDef* gpio, PinName pin, PinDirection direction, PinMode mode, int value);

/**@}*/

#ifdef __cplusplus
}
#endif

#endif