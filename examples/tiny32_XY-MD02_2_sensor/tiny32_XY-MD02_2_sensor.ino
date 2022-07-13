/***********************************************************************
 * Project      :     tiny32_XY-MD02_2_sensor
 * Description  :     Get value from XY-MD02(SHT20) temperture and Humidity sensor
 * Hardware     :     tiny32_v3         
 * Author       :     Tenergy Innovation Co., Ltd.
 * Date         :     13/07/2022
 * Revision     :     1.0
 * website      :     http://www.tenergyinnovation.co.th
 * Email        :     admin@innovation.co.th
 * TEL          :     +66 82-380-3299
 ***********************************************************************/
#include <Arduino.h>
#include <tiny32_v3.h>

tiny32_v3 mcu; //define object

uint8_t id_1 = 1; //Address of XY-MD02 sensor module, You can change here if it differance 
uint8_t id_2 = 2; //Address of XY-MD02 sensor module, You can change here if it differance

float temperature, humidity;



void setup()
{
  Serial.begin(115200);
  Serial.printf("\r\n**** tiny32_XY-MD02_2_sensor ****\r\n");
  mcu.library_version();
  mcu.XY_MD02_begin(RXD2,TXD2);
  mcu.buzzer_beep(2); //buzzer 2 beeps
}

void loop()
{
  
  /*** ID: 1 ***/
  if(mcu.XY_MD02(id_1,temperature,humidity))
  {
    Serial.printf("Temperature[%d] => %.1f C\r\n",id_1,temperature);
    Serial.printf("Humidity[%d] => %.1f%c\r\n",id_1,humidity,37);
  }
  else
  {
    Serial.printf("Error: Can't get data from XY-MD02[%d] sensor!!!\r\n",id_1);
  }

  /*** ID: 2 ***/
  if(mcu.XY_MD02(id_2,temperature,humidity))
  {
    Serial.printf("Temperature[%d] => %.1f C\r\n",id_2,temperature);
    Serial.printf("Humidity[%d] => %.1f%c\r\n",id_2,humidity,37);
  }
  else
  {
    Serial.printf("Error: Can't get data from XY-MD02[%d] sensor!!!\r\n",id_2);
  }


  Serial.println("-------------------------------");
  vTaskDelay(1000);

}