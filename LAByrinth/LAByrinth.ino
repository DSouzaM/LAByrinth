extern "C" {
#include "OrbitBoosterPackDefs.h"
#include "led.h"
#include "button.h"
#include "switch.h"
}

void DeviceInit();

int i = 0;

void setup() {


	Serial.begin(9600);
	DeviceInit();


}
void loop() {
	
	delay(50);

}



void DeviceInit() {
	// See orbit_demo for explanation of expressions.
	//SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_4);

	SysCtlPeripheralEnable(	SYSCTL_PERIPH_GPIOA );
	SysCtlPeripheralEnable(	SYSCTL_PERIPH_GPIOB );
	SysCtlPeripheralEnable(	SYSCTL_PERIPH_GPIOC );
	SysCtlPeripheralEnable(	SYSCTL_PERIPH_GPIOD );
	SysCtlPeripheralEnable(	SYSCTL_PERIPH_GPIOE );
	SysCtlPeripheralEnable(	SYSCTL_PERIPH_GPIOF );
	
	GPIOPadConfigSet(SWTPort, SWT1 | SWT2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);
	/*GPIOPadConfigSet(BTN1Port, BTN1, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);
	GPIOPadConfigSet(BTN2Port, BTN2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPD);*/

	/*GPIOPadConfigSet(LED1Port, LED1, GPIO_STRENGTH_8MA_SC, GPIO_PIN_TYPE_STD);
	GPIOPadConfigSet(LED2Port, LED2, GPIO_STRENGTH_8MA_SC, GPIO_PIN_TYPE_STD);
	GPIOPadConfigSet(LED3Port, LED3, GPIO_STRENGTH_8MA_SC, GPIO_PIN_TYPE_STD);
	GPIOPadConfigSet(LED4Port, LED4, GPIO_STRENGTH_8MA_SC, GPIO_PIN_TYPE_STD);*/
	
	GPIOPinTypeGPIOInput(SWTPort, SWT1 | SWT2);

	GPIOPinTypeGPIOInput(BTN1Port, BTN1);
	GPIOPinTypeGPIOInput(BTN2Port, BTN2);

	GPIOPinTypeGPIOOutput(LED1Port, LED1);
	GPIOPinTypeGPIOOutput(LED2Port, LED2);
	GPIOPinTypeGPIOOutput(LED3Port, LED3);
	GPIOPinTypeGPIOOutput(LED4Port, LED4);

	SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
	GPIOPinTypeADC(AINPort, AIN);

	ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);
	ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_IE | ADC_CTL_END | ADC_CTL_CH0);
	ADCSequenceEnable(ADC0_BASE, 0);
	}


/*
  This is hacked from the example: Button
 
 * Note that switches and buttons use a pull up or down resistor in order to ensure a valid input is always given 
 
 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe
 modified Apr 27 2012
 by Robert Wessels
 modified July 6, 2015
 by Eric Praetzel
 
 This example code is in the public domain.
 
 Original Source: http://www.arduino.cc/en/Tutorial/Button
 

// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = PUSH2;     // the number of the pushbutton pin
const int ledPin =  GREEN_LED;      // the number of the LED pin
const int Orbit_LD1 = PC_6;    // Orbit LD1
const int Orbit_LD2 = PC_7;    // Orbit LD2
const int Orbit_LD3 = PD_6;    // Orbit LD3
const int Orbit_LD4 = PB_5;    // Orbit LD4

const int Orbit_SLIDE1 = PA_7;    // Orbit Slide Switch 1
const int Orbit_SLIDE2 = PA_6;    // Orbit Slide Switch 2

const int Orbit_BTN1 = PD_2;    // Orbit Button 1
const int Orbit_BTN2 = PE_0;    // Orbit Button 2

const int Orbit_POT = PE_3; // Potentiometer

//const int Orbit_ACCEL = PB_4; // Accelerometer

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int prevButtonState = 0;

void setup() {
  Serial.begin(9600);
  // initialize the LEDs pin as an output:
  pinMode(RED_LED, OUTPUT); 
  pinMode(BLUE_LED, OUTPUT);      
  pinMode(GREEN_LED, OUTPUT);      

  // init Orbit LEDs
  pinMode(Orbit_LD1, OUTPUT);      
  pinMode(Orbit_LD2, OUTPUT);      
  pinMode(Orbit_LD3, OUTPUT);      
  pinMode(Orbit_LD4, OUTPUT);      
  
  // initialize the pushbutton pins as an input:
  pinMode(PUSH1, INPUT_PULLUP);     
  pinMode(PUSH2, INPUT_PULLUP);     
  
  pinMode(Orbit_BTN1, INPUT);     
  pinMode(Orbit_BTN2, INPUT);     
  pinMode(Orbit_SLIDE1, INPUT_PULLDOWN);     // These need a pulldown resistor
  pinMode(Orbit_SLIDE2, INPUT_PULLDOWN);

  pinMode(Orbit_POT, INPUT); 
  pinMode(0x34, INPUT);


       
}

void loop(){
  // read the state of the pushbutton value:
  prevButtonState = buttonState;
  buttonState = analogRead(0x2D); //(analogRead(Orbit_BTN1)>100);
  delay(50);
  Serial.println(buttonState);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState && !prevButtonState) {     
    // turn LED on:    
    Serial.println("Button pressed.");
    digitalWrite(Orbit_LD4, HIGH);  
  } else if (!buttonState && prevButtonState) {
  	Serial.println("Button released.");
    // turn LED off:
    digitalWrite(Orbit_LD4, LOW); 
  }

    if (digitalRead(Orbit_SLIDE1) == HIGH) {     // turn LED on:    
      digitalWrite(Orbit_LD1, HIGH);  
    } else {    // turn LED off:
      digitalWrite(Orbit_LD1, LOW); 
    }
    if (digitalRead(Orbit_SLIDE2) == HIGH) {     // turn LED on:    
      digitalWrite(Orbit_LD2, HIGH);  
    } else {    // turn LED off:
      digitalWrite(Orbit_LD2, LOW); 
    }
    
}
*/