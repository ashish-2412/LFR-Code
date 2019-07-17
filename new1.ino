#define lc 0
#define sc 1

#define lm1 10
#define lm2 9
#define rm1 6
#define rm2 5

int s1,s2,s3,s4,s5,s6,s7,s8;
int error=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
pinMode(lm1,OUTPUT);
pinMode(lm2,OUTPUT);
pinMode(rm1,OUTPUT);
pinMode(rm2,OUTPUT);

}

void readsensors()
{
  s1=digitalRead(A0);
  s2=digitalRead(A1);
  s3=digitalRead(A2);
  s4=digitalRead(A3);
  s5=digitalRead(A4);
  s6=digitalRead(A5);
  s7=digitalRead(2);
  s8=digitalRead(4);
}
void straight()
{
  analogWrite(lm1,120);
  analogWrite(lm2,0);
  analogWrite(rm1,120);
  analogWrite(rm2,0);
}
void left_turn(double d)
{
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,d*200);
  analogWrite(rm2,0);
}
void right_turn(double d)
{
  analogWrite(lm1,d*200);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}
void stop()
{
  analogWrite(lm1,0);
  analogWrite(lm2,0);
  analogWrite(rm1,0);
  analogWrite(rm2,0);
}

void loop() {
  // put your main code here, to run repeatedly:

    readsensors();
    double la=(s1+s2+s3+s4)/4.0;
    double ra=(s5+s6+s7+s8)/4.0;
    double d=la-ra;

    if(la>ra)
    {
      right_turn(d);
    }
    else if(ra>la)
    {
      left_turn(d);
      
    }
    else if(s1==0.0 ||s2==0.0 ||s3==0.0 ||s4==0.0 ||s5==0.0 ||s6==0.0 ||s7==0.0 ||s8==0.0 ||)
    {
      stop();
    }
    else{
      straight();
    }
}














    
