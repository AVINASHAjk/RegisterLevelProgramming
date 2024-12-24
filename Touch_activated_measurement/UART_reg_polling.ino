#include<avr/io.h>
int main()
{
  int i=0;
  char data[]="JAI SRI RAM";
    UCSR0B |= (1<<RXEN0) | (1<<TXEN0); 
    UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01);
    UBRR0L = 103; 

    while(1)
    {
        for (i=0;data[i]!=0;i++)
        {
            UDR0 = data[i]; // Send 'A'
            while(!(UCSR0A & (1<<UDRE0))); 
            
        }
         UDR0 = '\n';
        while(!(UCSR0A & (1<<UDRE0))); 
    }
}
