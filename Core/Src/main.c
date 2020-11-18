// PE5 == Motion Sensor
// PE0 == LED

#include <main.h>

int main(void)
{
	HAL_Init();

	__HAL_RCC_GPIOE_CLK_ENABLE();

	GPIO_InitTypeDef motion_gpio, led_gpio;

	motion_gpio.Pin = GPIO_PIN_5;
	motion_gpio.Mode = GPIO_MODE_INPUT;
	motion_gpio.Speed = GPIO_SPEED_FAST;
	motion_gpio.Pull = GPIO_PULLDOWN;

	led_gpio.Pin = GPIO_PIN_0;
	led_gpio.Mode = GPIO_MODE_OUTPUT_PP;
	led_gpio.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOE, &motion_gpio);
	HAL_GPIO_Init(GPIOE, &led_gpio);

	while (1) {
		if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5)) {
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, SET);
		} else {
			HAL_GPIO_WritePin(GPIOE, GPIO_PIN_0, RESET);
		}
	}
}
