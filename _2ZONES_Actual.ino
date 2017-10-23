/* 2 zone read*/

//Define the moisture sensor pin
int analogPin = 0;  // delcare analog pin 0 for a soil moisture
int analogPin1 = 1; // declare analog pin 1 for a soil moisture

//define signal pin
int inputGateSignal = 7; // declare digital pin 7 as gate signal
int inputGateSignal1 = 8; //declare digital pin 8 as a gate signal

//variable moisture pins
int output_value = 0; //  initial value of moisture sensor 1
int output_value1 = 0;// initial value of moisture sensor 2

//other constants
//zone1
int moistureValue = 0;  //value of moisture measured at sensor 1
int moistureSum = 0; //computes the moistness for sensor 1
//zone2
int moistureValue1 = 0; // value of moisture measured at sensor 2
int moistureSum1 = 0; // value of moistness for sensor 2

//thresholds
int wetValue = 200 ; //wet threshold
int dryValue = 400 ; //dry threshold of air

void setup() {
  Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission, in this case 9600 bps
  pinMode(inputGateSignal, OUTPUT);// Sets gates for zone 1 as output
  pinMode(inputGateSignal1, OUTPUT);// sets gates for zone 2 as output
}

void loop() {
 //ZONE 1
  output_value = analogRead(analogPin); //read input of pin A0
  moistureSum = moistureSum + output_value; //computes moistness for zone 1
  moistureValue = map(output_value, dryValue, wetValue, 0, 100); //converts moisture of sensor 1 into percentages
//ZONE 2
  output_value1 = analogRead(analogPin1); // read input of pin A1 
  moistureSum1 = moistureSum1 + output_value1; // computes moistness for zone 2
  moistureValue1 = map(output_value1, dryValue, wetValue, 0, 100); // converts moisture of sensor 2 into percentages
  
 // print the results to the serial monitor:
 Serial.print("Moisture = " );
 Serial.print(moistureValue);
 Serial.print("%");
 Serial.print('\n');
 Serial.print("Moisture = " );
 Serial.print(moistureValue1);
 Serial.print("%");
 Serial.print('\n');
 //Zone 1
 
 if(moistureValue > 41 && moistureValue < 100) {
  digitalWrite(inputGateSignal, HIGH);
  delay(2000);
  }  else {
    digitalWrite(inputGateSignal, LOW);
    delay(6000);
  }
//ZONE 2
if(moistureValue1 > 41 && moistureValue1 < 100) {
  digitalWrite(inputGateSignal1, HIGH);
  delay(2000);
  }  else {
    digitalWrite(inputGateSignal1, LOW);
    delay(6000);
  }
 }
  


