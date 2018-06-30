int IRpin = A0;               
int IRemitter = 2;          
int ambientIR;                
int obstacleIR;              
int value[10];                
int distance;                 

void setup(){
  Serial.begin(9600);        
  pinMode(IRemitter,OUTPUT);  
  digitalWrite(IRemitter,LOW);
  pinMode(11,OUTPUT);         
}

void loop(){
  distance = readIR(5);       
  Serial.println(distance);   
  // buzzer();                
}

int readIR(int times){
  for(int x=0;x<times;x++){     
    digitalWrite(IRemitter,LOW);         
    delay(1);                                             
    ambientIR = analogRead(IRpin);  
    digitalWrite(IRemitter,HIGH);          
    delay(1);                                            
    obstacleIR = analogRead(IRpin);  
    value[x] = ambientIR-obstacleIR;   
  }
 
  for(int x=0;x<times;x++){        
    distance+=value[x];
  }
  return(distance/times);            
}



void buzzer(){
  if (distance>1){
    if(distance>100){ 
      digitalWrite(11,HIGH);
    }
    else{  
      digitalWrite(11,HIGH);
      delay(150-distance); 
      digitalWrite(11,LOW);
      delay(150-distance);  
    }
  }
  else{  
    digitalWrite(11,LOW);
  }
}
