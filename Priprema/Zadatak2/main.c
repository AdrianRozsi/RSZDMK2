#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include "../usart/usart.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>

int main(){


	int8_t counter;
	int8_t i;
	int8_t counter_str[32];
	usartInit(9600);
	int8_t str[32];
	int8_t input_len;
	int8_t flag;

	while (1)
	{
		i = 0;
		counter = 0;
		flag = 1;


		usartPutString("Unesi string:\r\n");
		while (!usartAvailable());
		_delay_ms(100);
		input_len = usartGetString(str);

		while (str[i] != '\0')
		{
					if(str[i] == 'a' || str[i] == 'e' || str[i] == 'u' || str[i] == 'i' || str[i] == 'o' )
					{
						counter++;
					}
					i++;
		}

		usartPutString("Slovo samoglasnici:");
		sprintf(counter_str, "%d\0", counter);
		usartPutString(counter_str);
		usartPutString("\r\n");
	 //ispis broj samoglasnika
	}

	return 0;
}
