#define MQpin A0                    //MQ module pin is connected to analog pin A0 of NodeMCU

void setup()  //This executes only once in a Program Execution
{
  pinMode(MQpin, INPUT);      //MQ pin has made input in NodeMCU
  Serial.begin(115200);       //Serial Monitor starts with 115200 buad rate
}

void loop()
{
  float MQvoltage = (analogRead(MQpin) * (5.00 / 1023));   //To calculate the voltage read from ADC
  Serial.print("MQ - 05 Sensor = ");        
  Serial.print(MQvoltage);            //Printing the voltage value
  Serial.println("Volts");
  delay(1000);                        //Delay of 1 second
}
