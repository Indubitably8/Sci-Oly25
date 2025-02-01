bool wasClear = false;
bool ran = false;

const int ir = 10;

/*
FL+, FL-,
FR+, FR-,
BL+, BL-,
BR+, BR-
*/
const int mot[] = {
  0, 1, 
  3, 2,
  6, 7,
  4, 5
};

void setup(){
  for(int i = 0; i < sizeof(mot); i++){
    pinMode(mot[i], OUTPUT);
  }
  pinMode(ir, INPUT);
}

void loop(){
  if(digitalRead(ir) == LOW){
    if(wasClear && !ran){
      ran = true;
      delay(500);
      run();
    }
  } else {
    wasClear = true;
  }
}

void run(){
  // 26 s / cm
  drive(true, 26*825);
}