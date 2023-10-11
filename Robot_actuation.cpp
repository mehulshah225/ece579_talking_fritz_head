/* Author: Mehul Shah
   This code is used to take input from python in the form of
   estimated time and emotions in order for the robot to replicate
   it.*/

#include <Servo.h>
// Set up servo motor and pin
Servo servo_lefteyebrow;
Servo servo_righteyebrow;
Servo servo_leftLip;
Servo servo_rightLip;
Servo servo_verticalEye_left;
Servo servo_verticalEye_right;
Servo servo_horizontalEye_left;
Servo servo_horizontalEye_right;
Servo servo_lefteyelid;
Servo servo_righteyelid;
Servo servo_jaw;
Servo servo_nod;

void setup() {
  // Start serial communication with Python
  Serial.begin(9600);

      // Attach servo motor to pin
      servo_lefteyebrow.attach(2);
      servo_righteyebrow.attach(3);

      servo_leftLip.attach(10);
      servo_rightLip.attach(11);

      servo_verticalEye_left.attach(8);
      servo_verticalEye_right.attach(9);

      servo_horizontalEye_left.attach(6);
      servo_horizontalEye_right.attach(7);
      
      servo_lefteyelid.attach(4);
      servo_righteyelid.attach(5);
      
      servo_jaw.attach(12);
      servo_nod.attach(13);
  
}

void loop() {
  // Check if there is any incoming serial data
  if (Serial.available() > 0) {
    // Read the incoming data as a string
    String input = Serial.readString();

    // Move the servo motor based on the input
    // FEAR FACE
    if (input == "1") {
      servo_lefteyebrow.write(70);
      servo_righteyebrow.write(120);

      servo_leftLip.write(60);
      servo_rightLip.write(140);

      servo_verticalEye_left.write(80);
      servo_verticalEye_right.write(140);

      servo_horizontalEye_left.write(108);
      servo_horizontalEye_right.write(40);
      
      servo_lefteyelid.write(80);
      servo_righteyelid.write(80);
      
      servo_jaw.write(55);
      servo_nod.write(50);
     
    } 
      //  NEUTRAL FACE
      else if (input == "2") {
      servo_lefteyebrow.write(90);
      servo_righteyebrow.write(90);

      servo_leftLip.write(80);
      servo_rightLip.write(90);

      servo_verticalEye_left.write(90);
      servo_verticalEye_right.write(130);

      servo_horizontalEye_left.write(80);
      servo_horizontalEye_right.write(80);
      
      servo_lefteyelid.write(50);
      servo_righteyelid.write(80);
      
      servo_jaw.write(100);
      servo_nod.write(90);
      
    } //  SAD FACE
      else if (input == "3") {
      servo_lefteyebrow.write(60);
      servo_righteyebrow.write(130);

      servo_leftLip.write(140);
      servo_rightLip.write(40);

      servo_verticalEye_left.write(90);
      servo_verticalEye_right.write(130);

      servo_horizontalEye_left.write(108);
      servo_horizontalEye_right.write(80);
      
      servo_lefteyelid.write(90);
      servo_righteyelid.write(10);
      
      servo_jaw.write(100);
      servo_nod.write(110);
    } 
      //  ANGRY FACE
      else if (input == "4") {
      servo_lefteyebrow.write(120);
      servo_righteyebrow.write(70);

      servo_leftLip.write(140);
      servo_rightLip.write(40);

      servo_verticalEye_left.write(90);
      servo_verticalEye_right.write(130);

      servo_horizontalEye_left.write(80);
      servo_horizontalEye_right.write(80);
      
      servo_lefteyelid.write(100);
      servo_righteyelid.write(10);
      
      servo_jaw.write(100);
      servo_nod.write(70);
    } 
      //  SURPRISED FACE
      else if (input == "5") {
      servo_lefteyebrow.write(120);
      servo_righteyebrow.write(70);

      servo_leftLip.write(140);
      servo_rightLip.write(40);

      servo_verticalEye_left.write(110);
      servo_verticalEye_right.write(90);

      servo_horizontalEye_left.write(80);
      servo_horizontalEye_right.write(80);
      
      servo_lefteyelid.write(70);
      servo_righteyelid.write(70);
      
      servo_jaw.write(30);
      servo_nod.write(30);
    } 
      //  HAPPY FACE
      else if (input == "6") {
      servo_lefteyebrow.write(120);
      servo_righteyebrow.write(70);

      servo_leftLip.write(140);
      servo_rightLip.write(40);

      servo_verticalEye_left.write(90);
      servo_verticalEye_right.write(130);

      servo_horizontalEye_left.write(80);
      servo_horizontalEye_right.write(80);
      
      servo_lefteyelid.write(20);
      servo_righteyelid.write(0);
      
      servo_jaw.write(70);
      for(int i = 0; i < 4; i++)
      {
        servo_nod.write(90);
        delay(200);
        servo_nod.write(70);
      }
    } else {
      // Convert the string to a float
      float estimated_time = input.toFloat();
      Serial.print("Received estimated speech time: ");
      Serial.println(estimated_time);
      Serial.println(" seconds.");

      estimated_time =  ((estimated_time * 2));
      // Move servo for the estimated time
      servo_lefteyebrow.write(90);
      servo_righteyebrow.write(90);

      servo_leftLip.write(80);
      servo_rightLip.write(90);

      servo_verticalEye_left.write(90);
      servo_verticalEye_right.write(130);

      servo_horizontalEye_left.write(80);
      servo_horizontalEye_right.write(80);
      
      servo_lefteyelid.write(50);
      servo_righteyelid.write(80);
      
      servo_jaw.write(100);
      servo_nod.write(90);
      
      delay(1000);
      for (int i = 0; i < estimated_time; i++) {
        servo_jaw.write(70);  // move servo to maximum position
        delay(200);
        servo_jaw.write(90);    // move servo to minimum position
        delay(200);
      }
    }
  }
}