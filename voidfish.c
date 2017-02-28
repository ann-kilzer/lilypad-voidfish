

// tri-color led
const int r = A0;
const int g = 11;
const int b = 12;

// tentacles
const int t1 = 6;
const int t2 = 7;
const int t3 = 8;
const int t4 = A1;
const int t5 = A3;

// vibe board
const int vibe = 4;    

void setup() {
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(t3, OUTPUT);
  pinMode(t4, OUTPUT);
  pinMode(t5, OUTPUT);
  pinMode(vibe, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}


void loop() {
  fish();
}

// OMG
void fish() {
  rainbow();
  setColorRgb(255, 0, 0);
  tentacleFlicker();
  rgbOff();
  vibrate(1000);
}

void vibrate(int duration) {
  digitalWrite(vibe, HIGH);
  delay(duration);
  digitalWrite(vibe, LOW);
}

void tentacleFlicker() {
    digitalWrite(t1, HIGH); 
    delay(200);
    digitalWrite(t2, HIGH); 
    delay(200);   
    digitalWrite(t1, LOW); 
    delay(200);   
    digitalWrite(t3, HIGH);
    delay(200); 
    digitalWrite(t2, LOW);  
    delay(200); 
    digitalWrite(t4, HIGH); 
    delay(200);
    digitalWrite(t3, LOW);  
    delay(200);
    digitalWrite(t5, HIGH);   
    delay(200);
    digitalWrite(t4, LOW);  
    delay(200);
    digitalWrite(t5, LOW);
}

void flash() {
    digitalWrite(t1, HIGH);
    digitalWrite(t2, HIGH);
    digitalWrite(t3, HIGH);
    digitalWrite(t4, HIGH);
    digitalWrite(t5, HIGH);
    purple(500);
    delay(2000);
    digitalWrite(t1, LOW); 
    digitalWrite(t2, LOW); 
    digitalWrite(t3, LOW); 
    digitalWrite(t4, LOW); 
    digitalWrite(t5, LOW); 
   
}

// ***** COLOR STUFF ***** 

void rainbow() {
  int dur = 400;
  pink(dur);
  red(dur);
  orange(dur);
  yellow(dur);
  green(dur);
  aqua(dur);
  cyan(dur);
  blue(dur);
  blueviolet(dur);
  purple(dur);
}

void white(int duration) {
  setColorRgb(0, 0, 0, duration, 10);
}

void pink(int duration) {
  mix(255, 0, 0, 255, 0, 255, duration, 1, 1, 1);
}

void red(int duration) {
  setColorRgb(255, 0, 255, duration, 1);
}

void orange(int duration) {
  mix(255, 0, 255, 0, 0, 255, duration, 3, 1, 1);
}

void yellow(int duration) {
  setColorRgb(0, 0, 255, duration, 1);
}

void green(int duration) {
  setColorRgb(0, 255, 255, duration, 1);
}

void aqua(int duration) {
  mix(0, 255, 255, 0, 255, 0, duration, 5, 1, 2);
}

void cyan(int duration) {
  setColorRgb(0, 255, 0, duration, 1);
}

void blue(int duration) {
  setColorRgb(255, 255, 0, duration, 1);
}

void blueviolet(int duration) {
  mix(255, 255, 0, 255, 0, 0, duration, 5, 1, 1);
}

void purple(int duration) {
  setColorRgb(255, 0, 0, duration, 1);
}

void setColorRgb(unsigned int rv, unsigned int gv, unsigned int bv, 
                 int duration, unsigned int step) {
  if (step < 1) {
    step = 1;
  }
  int count = 0;
  while (count < duration) {
    setColorRgb(rv, gv, bv);
    delay(step);
    rgbOff();
    delay(step);
    count = count + step + step;
  }
}

void mix(unsigned int r1, unsigned int g1, unsigned int b1, 
         int r2, unsigned int g2, unsigned int b2,
         int duration, unsigned int step1, unsigned int step2,
         unsigned int step3) {
  if (step1 < 1) {
    step1 = 1;
  }
  int count = 0;
  while (count < duration) {
    setColorRgb(r1, g1, b1);
    delay(step1);
    setColorRgb(r2, g2, b2);
    delay(step2);
    rgbOff();
    delay(step3);
    count = count + step1 + step2;
  }          
}

void rgbOff() {
  setColorRgb(255, 255, 255);
}

void setColorRgb(unsigned int rv, unsigned int gv, unsigned int bv) {
  analogWrite(r, rv);
  analogWrite(g, gv);
  analogWrite(b, bv);
}
