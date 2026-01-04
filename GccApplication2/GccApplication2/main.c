

#include <avr/io.h>
#define F_CPU 16000000UL // Especifico la frecuencia de reloj del MCU en 16MHz
#include <util/delay.h> // Retardos por software – Macros: depende de F_CPU
#include <stdio.h>
#include <stdlib.h>
#define rebote 3000  // variable para deteccion de cambio de estado del pulsador


// variables globales
uint8_t secuencia = 1;
uint8_t inicializacion = 1;

void pulsador(); // funcion para chequear el pulsador

	int main(void)
	{
    
	  uint8_t aux;
	  uint8_t valor1; 
	  uint8_t valor2;
	  long int retardo = 0; 
	  DDRB = 0xFF;  // configurado PORTB como salida
	  DDRC &= ~(1<<PORTC0); //el bit0 de PORTC configurado como entrada
		while (1) // loop
		{
			pulsador(); // chequeo el pulsador
			
			
		  if (retardo == 0) { //si se acabo el tiempo de visualizacion
 			  retardo = 130000; // reinicio el tiempo de visualizacion

			  if (secuencia) {  // 1 = secuencia numero 1, 0 = secuencia numero 2
				 if (inicializacion == 1) { // si inicializacion es 1, significa que la secuencia comienza.
					 aux = 0; //inicializo el contador de la secuencia
					valor1 = 0b10000000; 
					valor2 = 0b00000001; 
					inicializacion = 0;
				 }
			  
				if (aux == 4) { // si aux es 4, se reinicia la secuencia
					aux = 0;
					valor1 = 0b10000000; 
					valor2 = 0b00000001; 
				}
				aux++;  //incremento  el contador de la secuencia
				PORTB = valor1 | valor2;  // Le asigno a PORTB el valor actual de la secuencia
				valor1 = (valor1 >> 1);  // desplazo un bit a derecha
				valor2 = (valor2 << 1); // desplazo un bit a izquierda
		
			  }
			  else { //secuencia numero 2
		  
				   if (inicializacion == 1) { // si inicializacion es 1, significa que la secuencia comienza.
					   aux = 0;
					   valor2 = 0b10000000; 
					   inicializacion = 0;
				   }
		   
				  if (aux == 8) { // si aux llega a 8 debe volver a empezar la secuencia
					  aux = 0;
					  valor2 = 0b10000000;
				  }
				   PORTB = valor2;  //le asigno a PORTB el valor actual de la secuencia
				  valor2 = (valor2 >> 1); // desplazo un bit a derecha
				  aux++; 
				  }
	
		
			} else {retardo--;} //decremento el tiempo de visualizacion
		
	
		}
	
		return 0;
	}



void pulsador(void) // funcion de chequeo del pulsador sin efecto rebote
 {
	 static uint8_t estado = 1; 
	 static uint16_t contador = 0;
	  
	  
	  uint8_t estado_actual = PINC & (1<<PINC0); //verificamos estado actual del pinc0

	if(estado_actual != estado){ 
		// se incrementa el contador hasta confirmar el cambio de estado
	  contador++;
	  if (contador == rebote){ // si el contador cumplio con el tiempo de chequeo del efecto rebote
		  estado = estado_actual;
		 
		  if (estado == 1) { // si estado es igual a 1 quiere decir que el pulsador dejo de estar presionado
	    secuencia = secuencia ? 0 : 1;	//cambio de secuencia
		inicializacion = 1; // inicializacion en 1 para la nueva secuencia
		contador = 0; //reinicio el contador
		  }
	  }
	   }
	   else {contador = 0;}// si no cumple contador == rebote, se reinicia a 0
	
}