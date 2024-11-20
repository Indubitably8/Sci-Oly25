#include <Servo.h>


/*
  Methods:

  Driving:
    changeSpeed(power); // (+):Speed Up; (-):Slow Down 
    Drive(power); // (+):Forward; (-):Reverse; (0):Brake 
    toggleDrive(power); 
    setDrive(power, time); //Milliseconds(Cannot exceed 3000) 
    Turn(power); // (-):Turn Left; (+): Turn Right 
    toggleTurn(power); 
    setTurn(power, time);
*/

double powers[6];

//Driving Methods
void changeSpeed(double amount){
  speed += amount;
  if(speed > 1){
    speed = 1;
  } else if(speed < 0){
    speed = 0;
  }
}
unsigned long driveTime;
void Drive(double power){
  if(safeDrive){
    driveTime = millis()+3000;
  }
  for(int i = 0; i < 4; i++){
    powers[i] = power;
  }
}
void toggleDrive(double power){
  if(powers[0] == power){
    Drive(0);
  } else {
    Drive(power);
  }
}
void setDrive(double power, int time){
  driveTime = millis()+time;
  Drive(power);
}

void Turn(double power){
  if(safeDrive){
    driveTime = millis()+3000;
  }
  powers[0] = power;
  powers[1] = -power;
  powers[2] = power;
  powers[3] = -power;
}
void toggleTurn(double power){
  if(powers[0] == power){
    Drive(0);
  } else {
    Turn(power);
  }
}
void setTurn(double power, int time){
  driveTime = millis()+time;
  Turn(power);
}



void updateMovement(){
  unsigned long time = millis();
  for(int i = 0; i < 6; i++){
    setMotor(i, powers[i]);
  }
  if(driveTime != 0){
    if(millis() > driveTime){
      Drive(0);
      driveTime = 0;
    }
  }
  if(intakeTime != 0){
    if(millis() > intakeTime){
      Intake(0);
      intakeTime = 0;
    }
  }
  if(toggleIntakeTime != 0){
    if(millis() > toggleIntakeTime){
      intakeShaft(!intake);
      toggleIntakeTime = 0;
    }
  }
  if(putterTime != 0){
    if(millis() > putterTime){
      pullPutter(0);
      putterTime = 0;
    }
  }
  if(togglePutterTime != 0){
    if(millis() > togglePutterTime){
      Engage(!engaged);
      togglePutterTime = 0;
    }
  }
  if(engaged){
    wormServo.write(0.9*180);
  } else {
    wormServo.write(0.65*180);
  }
  if(intake){
    intakeServo.write(0.7*180);
  } else {
    intakeServo.write(0.2*180);
  }
}

void shutOff(){
  for(int i = 0; i < 6; i++){
    setMotor(i, 0);
  }
}

void setMotor(int motor, double power){ //power: value -1 through 1
/*
0 - frontLeft
1 - frontRight
2 - backLeft
3 - backRight
*/
  if(power < 0){
    digitalWrite(22+motor*4, LOW);
    digitalWrite(23+motor*4, HIGH);
  } else if(power > 0){
    digitalWrite(22+motor*4, HIGH);
    digitalWrite(23+motor*4, LOW);
  } else{
    digitalWrite(22+motor*4, LOW);
    digitalWrite(23+motor*4, LOW);
  }
  if(motor % 2 == 0){
    analogWrite(24+motor*4 , abs(power*255));
  } else {
    analogWrite(21+motor*4 , abs(power*255));
  }
}