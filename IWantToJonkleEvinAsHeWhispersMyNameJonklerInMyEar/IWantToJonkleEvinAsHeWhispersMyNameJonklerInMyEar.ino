bool running = false;

void setup(){
  pinMode(0, INPUT);
  pinMode(2, OUTPUT);
}

void loop(){
  if(digitalRead(0) == LOW){
    if(!running){
      run();
    }
  }
}

void run(){
    digitalWrite(2, HIGH);
}