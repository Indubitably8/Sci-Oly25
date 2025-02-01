void drive(bool p, int t){
  for(int i = 0; i < 2; i++){
    digitalWrite(mot[i], -abs(p-i)); //FL
    digitalWrite(mot[2+i], abs(p-i)); //FR
    digitalWrite(mot[4+i], -abs(p-i)); //BL
    digitalWrite(mot[6+i], -abs(p-i)); //BR
  }
  delay(t);
  for(int i = 0; i < sizeof(mot); i++){
    digitalWrite(mot[i], LOW);
  }
  delay(250);
}

void drive2W(bool p, int t){
  for(int i = 0; i < 2; i++){
    digitalWrite(mot[i], abs(p-i)); //FL
    digitalWrite(mot[4+i], abs(p-i)); //FR
  }
  delay(t);
  for(int i = 0; i < sizeof(mot)/2; i++){
    digitalWrite(mot[i], LOW);
  }
  delay(250);
}

void turn(bool p, int t){
for(int i = 0; i < 2; i++){
    digitalWrite(mot[i], abs(p-i));
    digitalWrite(mot[2+i], -abs(p-i));
    digitalWrite(mot[4+i], abs(p-i));
    digitalWrite(mot[6+i], -abs(p-i));
  }
  delay(t);
  for(int i = 0; i < sizeof(mot); i++){
    digitalWrite(mot[i], LOW);
  }
  delay(250);
}

void turn2W(bool p, int t){
for(int i = 0; i < 2; i++){
    digitalWrite(mot[6+i], abs(p-i));
    digitalWrite(mot[4+i], -abs(p-i));
  }
  delay(t);
  for(int i = 0; i < sizeof(mot)/2; i++){
    digitalWrite(mot[i], LOW);
  }
  delay(250);
}