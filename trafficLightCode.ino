int r_led =2;//номер пин'а, который будет обеспечивает работу красного светодиода
int y_led =3;//номер пин'а, который будет обеспечивает работу жёлтого светодиода
int g_led =4;//номер пин'а, который будет обеспечивает работу зелёного светодиода
int button = 5;//номер пин'a, который будет отвечать за работу кнопки
boolean butt;//проверка  нажатия кнопки
unsigned long preMillis=0;
unsigned long curMillis=0;
long interval=5000;


void setup()
{
  pinMode(button,INPUT_PULLUP);//кнопке в этом режиме не требуется дополнительный резистор, в ардруине включится свой (встроенный)
  pinMode(r_led, OUTPUT);//красный пин на "вывод" информации
  pinMode(y_led, OUTPUT);//жёлтый пин на "вывод" информации
  pinMode(g_led, OUTPUT);//зелёный пин на "вывод" информации
	Serial.begin(9600);
}

void flash(){
  digitalWrite(y_led, HIGH);//включаю жёлый светодиод
  
    	delay(1000); // ждём 0.5 секунду
   
  digitalWrite(y_led, LOW);//включаю жёлый светодиод
  
    	delay(200); // ждём 0.4 секунду
  
  digitalWrite(y_led, HIGH);//включаю жёлый светодиод
  
  		delay(500); // ждём 0.3 секунду  
  
  digitalWrite(y_led, LOW);//включаю жёлый светодиод
  
    	delay(200); // ждём 0.4 секунду
  
  digitalWrite(y_led, HIGH);//включаю жёлый светодиод
  
  		delay(500); // ждём 0.3 секунду  
  
  digitalWrite(y_led, LOW);//включаю жёлый светодиод
  
    	delay(200); // ждём 0.4 секунду
  return;
}



void loop()
{
  butt=!digitalRead(button);
  if(butt==0){
    start:
    	digitalWrite(y_led, LOW);//выключен
    	digitalWrite(g_led, LOW);//выключен
    	digitalWrite(r_led, HIGH);//включаю красный светодиод
    		delay(interval);
    	digitalWrite(r_led, LOW);//выключен
    		if(butt==1){
        		flash();
    			goto start;
    		}
    	flash();
    		if(butt==1){
        		flash();
    			goto start;
    		}
    preMillis=millis();
    digitalWrite(g_led, HIGH);//включаю зелёный светодиод
    
    	Serial.print("PreMillis ");
		Serial.println(millis());

    while(millis()-preMillis<interval){
    preMillis = millis();
      Serial.print("CurMillis ");
		Serial.println(millis());       
    if(curMillis-preMillis>interval){
      
		
      digitalWrite(g_led, LOW);//выключен
      		if(butt==1){
        		flash();
    			goto start;
            	}
    		}
    else if(butt==1){
      			digitalWrite(g_led, LOW);
        		flash();
    			goto start;
    	}
    }
    	flash();
  }
  else {
    flash();
    goto start;
  }
  		}