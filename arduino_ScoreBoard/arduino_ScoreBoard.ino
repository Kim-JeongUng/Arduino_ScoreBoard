#define btn1 A0
#define btn2 A1

byte to7seg[10][7] = {    
 {0, 0, 0, 0, 0, 0, 1}, //0
  {1, 0, 0, 1, 1, 1, 1}, //1
  {0, 0, 1, 0, 0, 1, 0}, //2
  {0, 0, 0, 0, 1, 1, 0}, //3
  {1, 0, 0, 1, 1, 0, 0}, //4
  {0, 1, 0, 0, 1, 0, 0}, //5
  {0, 1, 0, 0, 0, 0, 0}, //6
  {0, 0, 0, 1, 1, 1, 1}, //7
  {0, 0, 0, 0, 0, 0, 0}, //8
  {0, 0, 0, 0, 1, 0, 0}, //9
};

int score1=0;
int score2=0;


void writeSegment(byte digit, int player)  
{
  if(player == 1){
    for (byte i = 0; i < 7; i++) 
      digitalWrite(i, to7seg[digit][i]);    
  }
  else{
    for (byte i = 0; i < 7; i++) 
      digitalWrite(i+7, to7seg[digit][i]);    
  }
  
}

void setup()
{
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  
  for (byte pinNum = 0; pinNum <= 13; pinNum++)
    pinMode(pinNum, OUTPUT);       

  writeSegment(0,1); 
  writeSegment(0,2); 
} 
 
void loop()
{  
  if(analogRead(btn1)==0){
    if(score1 >= 5) score1 = 0;
    else score1 ++;
    writeSegment(score1,1); 
    delay(500);
  }
  if(analogRead(btn2)==0){
    if(score2 >= 5) score2 = 0;
    else score2 ++;
    writeSegment(score2,2); 
    delay(500);
  }
  
}
