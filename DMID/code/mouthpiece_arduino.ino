// DISTANCE SENSOR //

// pin locations
const int trigPin = 9;  
const int echoPin = 10; 
// duration of pulse, distance measured
float duration, distance;  

// BUTTON SENSOR //
const int buttonPin_1 = 2;
const int buttonPin_2 = 4; 
const int buttonPin_3 = 7; 

// (OTHER SENSORS) //


void setup() {
  // start serial connection
  Serial.begin(115200); 

  // distance sensor initialization
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);
  pinMode(buttonPin_1, INPUT_PULLUP);
  pinMode(buttonPin_2, INPUT_PULLUP);
  pinMode(buttonPin_3, INPUT_PULLUP);
}

void loop() {
  /*
  OUTPUT:
  [
  distance (cm)   - float (xx)x.xx  - control tremolo + other continuous variables
  button_1 (0/1)  - bool            - control activation/spectral freeze recording
  button_2 (0/1)  - bool            - control triggers (require 1sec press to move on, i.e. 10 straight "1")
  button_3 (0/1)  - bool            - control control spectral freeze playback
  ]
  */

  // instruction to send out pulse 
  // NOTE: 10µsec electrical signal triggers 200 µsec transmitter pulse (8 cycles at 40k HZ)
  digitalWrite(trigPin, LOW);  
	delayMicroseconds(2);  
	digitalWrite(trigPin, HIGH);  
	delayMicroseconds(10);  
	digitalWrite(trigPin, LOW);  
  // read pulse duration (µsec), calculate distance (in cm), send distance back
  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print(distance);
  Serial.print(" ");
  // read and print button state 1 (1 is pressed, 0 is not pressed)
  int buttonState_1 = digitalRead(buttonPin_1);
  if (buttonState_1 == LOW) {
    Serial.print(0);
  }
  else {
    Serial.print(1);
  };
  Serial.print(" ");

  // read and print button state 2 (1 is pressed, 0 is not pressed)
  int buttonState_2 = digitalRead(buttonPin_2);
  if (buttonState_2 == LOW) {
    Serial.print(0);
  }
  else {
    Serial.print(1);
  };
  Serial.print(" ");

  // read and print button state 3 (1 is pressed, 0 is not pressed)
  int buttonState_3 = digitalRead(buttonPin_3);
  if (buttonState_3 == LOW) {
    Serial.println(0);
  }
  else {
    Serial.println(1);
  };
  

  // delay (arbitrary)
  delay(50);
}
