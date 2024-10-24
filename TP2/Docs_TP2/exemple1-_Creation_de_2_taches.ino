//--Exemple 1 - Création de deux tâches-------
#include <Arduino_FreeRTOS.h>

// define two Tasks 
void Task1( void *pvParameters );
void Task2( void *pvParameters );

// the setup function runs once when you press reset or power the board
void setup() {    
              // initialize serial communication at 9600 bits per second:
              Serial.begin(9600);
              
              while (!Serial) {
                                 ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
                               }
           
  // Now set up two Tasks to run independently wirh the same priority.
  xTaskCreate(
                Task1
                ,  "Task 1"  // A name just for humans
                ,  128  // This stack size can be checked & adjusted by reading the Stack Highwater
                ,  NULL //Parameters for the task
                ,  1  // Priority 1, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
                ,  NULL ); //Task Handle

  xTaskCreate(
                Task2
                ,  "Task 2" // A name just for humans
                ,  128  // Stack size
                ,  NULL //Parameters for the task
                ,  1  // Priority
                ,  NULL ); //Task Handle

    vTaskStartScheduler(); //Start Scheduler
  }

void loop()
{
  // Empty. Things are done in Tasks.   
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void Task1( void *pvParameters  )  // This is a Task 1.
  {
   // prints Tache 1 to the serial monitor
   volatile uint32_t cnt ;
     for (;;) // A Task shall never return or exit.
        {   
          //Serial.print(millis()); 
          Serial.println(" Tache 1");
          //delay(1000); 
          for(cnt=0;cnt<=2400000;cnt++);
        }  
  }

void Task2 (void *pvParameters  )  // This is a Task 2.
  {
   // prints Tache 2 to the serial monitor
   volatile uint32_t cnt ;
     for (;;) // A Task shall never return or exit.
        {       
          //Serial.print(millis()); 
          Serial.println(" Tache 2");
          //delay(500);
          for(cnt=0;cnt<=1200000;cnt++);
        }  
  }
