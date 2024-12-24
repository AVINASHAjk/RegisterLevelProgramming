#include<avr\io.h>
#define LED PB0
void timer0_init()   //initializing the timer0
{
//Timer0 Configuration
TCCR0A|=(1<<COM0A1)|(1<<COM0A0)|(1<<WGM01); //Ctc mode,set OC0A on compare match
TCCR0B|=(1<<CS02)|(1<<CS00); //1024 prescaler value
TCNT0=0;   //Timer counter making 0
OCR0A=31;   //2ms delay
}
void gpio_init()
{
//Port Configuartion
DDRB |=(1<<LED);    //set the direction as output
PORTB &=~(1<<LED); //set to low
}
void delay_500ms()  //(void multiple_10ms_delay(int temp)
{
for (int counter=0;counter<250;counter++)
{
while(!(TIFR0&(1<<OCF0A))); 
TIFR0|=(1<OCF0A);           //Clearing them bit
}
}
void toggle_led()
{
PORTB ^=(1<<LED); //toggle the led
}
int main()
{
gpio_init();
timer0_init();
while(1)
{ toggle_led();
delay_500ms();   //(multiple_10ms_delay(200);
}
}
