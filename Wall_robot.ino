
#define echoPin 33 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 32 // attach pin D3 Arduino to pin Trig of HC-SR04
#define echoPinFront 36
#define trigPinFront 37
#define LM1 12
#define LM2 13
#define RM1 10
#define RM2 11
// defines variables
long duration;
int FirstDistance = 0;
int SecondDistance = 0;
double speed = 0;
int distance = 1;
float Time = 0.5;
float delayedtime = 1000 * Time;

long durationf;
int FirstDistancef = 0;
int SecondDistancef = 0;
double speedf = 0;
int distancef = 1;
float Timef = 0.5;
float delayedtimef = 1000 * Timef;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(trigPinFront, OUTPUT);
    pinMode(echoPinFront, INPUT);
    pinMode(LM1, OUTPUT);
    pinMode(LM2, OUTPUT);
    pinMode(RM1, OUTPUT);
    pinMode(RM2, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    if (GetDistance(1) < 25)
    {
      Serial.println("Right Full");
        TurnRight();
        delay(5);
    }
    else if (GetDistance(0) > 25)
    {
      Serial.println("Left Full");
        TurnLeft();
        delay(5);
    }
    else if (GetDistance(0) > 6)
    {
      Serial.println("Left");
        TurnLeft();
        delay(10);
    }
    else if (GetDistance(0) < 6)
    {
      Serial.println("Right");
        TurnRight();
        delay(10);
    }
    else
    {
        DriveForward();
        delay(10);
    }
}
void DriveForward()
{
    digitalWrite(LM1, HIGH);

    digitalWrite(LM2, LOW);

    digitalWrite(RM1, HIGH);

    digitalWrite(RM2, LOW);
}
void TurnLeft()
{
    digitalWrite(LM1, HIGH);

    digitalWrite(LM2, LOW);

    digitalWrite(RM1, LOW);

    digitalWrite(RM2, LOW);
}
void TurnRight()
{
    digitalWrite(LM1, LOW);

    digitalWrite(LM2, LOW);

    digitalWrite(RM1, HIGH);

    digitalWrite(RM2, LOW);
}

float GetDistance(int sensor)
{
    if (sensor == 0)
    {
        // Clears the trigPin
        digitalWrite(trigPin, LOW);
        delayMicroseconds(2);

        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPin, LOW);

        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(echoPin, HIGH);

        // calculating distance
        distance = duration * 0.034 / 2;

        // Prints the distance on the Serial Monitor
        Serial.print("Distance Left: ");
        Serial.println(distance);

        return distance;
    }
    else if (sensor == 1)
    {
        digitalWrite(trigPinFront, LOW);
        delayMicroseconds(2);

        // Sets the trigPin on HIGH state for 10 micro seconds
        digitalWrite(trigPinFront, HIGH);
        delayMicroseconds(10);
        digitalWrite(trigPinFront, LOW);

        // Reads the echoPin, returns the sound wave travel time in microseconds
        duration = pulseIn(echoPinFront, HIGH);

        // calculating distance
        distance = duration * 0.034 / 2;

        // Prints the distance on the Serial Monitor
        Serial.print("Distance Front: ");
        Serial.println(distance);

        return distance;
    }
}


// void GetSpeed(){

//    FirstDistance = GetDistance(); //get the first distance

//    delay(delayedtime); //waits 2 seconds depending on the time declared above ,, feel free to change the value dependng on the resolution of your sensor

//    SecondDistance = GetDistance(); //gets the second distance

//    speed = (FirstDistance - SecondDistance)/Time;  // now calculating the difference

// //printing the speed on the serial monitor
//   Serial.print("the speed (cm/s) is  :  ");
//   Serial.println(speed);

// }
