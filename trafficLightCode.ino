int r_led =2;//номер пин'а, который будет обеспечивает работу красного светодиода
int y_led =3;//номер пин'а, который будет обеспечивает работу жёлтого светодиода
int g_led =4;//номер пин'а, который будет обеспечивает работу зелёного светодиода
int button = 5;//номер пин'a, который будет отвечать за работу кнопки
boolean butt;//проверка  нажатия кнопки
unsigned long preMillis=0;//таймер
long interval=5000;//интервал переключения светодиодов


void setup()
{
  pinMode(button,INPUT_PULLUP);//кнопке в этом режиме не требуется дополнительный резистор, в ардруине включится свой (встроенный)
  pinMode(r_led, OUTPUT);//красный пин на "вывод" информации
  pinMode(y_led, OUTPUT);//жёлтый пин на "вывод" информации
  pinMode(g_led, OUTPUT);//зелёный пин на "вывод" информации
  Serial.begin(9600);
}


void flash(){
  
  /*Мигание зелёного светодиода*/
  
  //выключаю все светодиоды
  digitalWrite(y_led, LOW);
  digitalWrite(r_led,LOW);
  digitalWrite(g_led, LOW);
    	delay(400); // ждём 0.4 секунды
  digitalWrite(g_led, HIGH);//включаю светодиод
  		delay(800); // ждём 0.8 секунды  
  digitalWrite(g_led, LOW);//выключаю светодиод
    	delay(350); // ждём 0.35 секунды
  digitalWrite(g_led, HIGH);//включаю светодиод
  		delay(700); // ждём 0.7 секунды  
  digitalWrite(g_led, LOW);//выключаю светодиод
    	delay(300); // ждём 0.3 секунды
  digitalWrite(g_led, HIGH);//включаю светодиод
  		delay(600); // ждём 0.6 секунды  
  digitalWrite(g_led, LOW);//выключаю светодиод
    delay(200); // ждём 0.2 секунды
  return;
}

void yellow(){
  
  	//загорается жёлтый светодиод
  
    digitalWrite(y_led, HIGH);//включаю жёлтый светодиод,который сигнализирует о скором включении красного
  		delay(1000);//задержка в 1 секунду
    digitalWrite(y_led, LOW);//выключаю
  
}

void loop()
{
  
    butt=!digitalRead(button);//считыватель нажатия кнопки
    	start://метка для возврата
 	digitalWrite(y_led, LOW);//выключен
    digitalWrite(g_led, LOW);//выключен
    digitalWrite(r_led, HIGH);//включаю красный светодиод
    	delay(interval-1000);//задержка в 4 секунд
    	yellow();//желтый свет
    digitalWrite(r_led, LOW);//выключаю красный светодиод
    	preMillis = millis();
    digitalWrite(g_led, HIGH);//включаю зелёный светодиод 
  
  /*поменял delay на цикл,что бы можно было включить жёлтый свет,
  как только он понадобится*/
  
    	while(millis()-preMillis<interval+10){
          
		  //проверка была ли нажата кнопка	
          if(butt==1){
            
        		flash();//Предупреждение о скором включении запрещающего сигнала
                yellow();//включаю жёлтый свет
    			goto start;//возвращаюсь к началу программы
    		
          }
            //проверка прошло ли 5 секунд
    		else if(millis()-preMillis>interval)
      			flash();//Предупреждение о скором включении запрещающего сигнала     
    	}
  
    yellow();//включаю жёлтый свет
  
  }