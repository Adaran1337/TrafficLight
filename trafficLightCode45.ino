#define potent A5
int r_led =2;//номер пин'а, который будет обеспечивает работу красного светодиода
int y_led =3;//номер пин'а, который будет обеспечивает работу жёлтого светодиода
int g_led =4;//номер пин'а, который будет обеспечивает работу зелёного светодиода
int button = 5;//номер пин'a, который будет отвечать за работу кнопки
boolean butt;//проверка  нажатия кнопки
unsigned long preMillis=0;//таймер
long interval;//интервал переключения светодиодов


void setup()
{
  pinMode(button,INPUT_PULLUP);//кнопке в этом режиме не требуется дополнительный резистор, в ардруине включится свой (встроенный)
  pinMode(r_led, OUTPUT);//красный пин на "вывод" информации
  pinMode(y_led, OUTPUT);//жёлтый пин на "вывод" информации
  pinMode(g_led, OUTPUT);//зелёный пин на "вывод" информации
  Serial.begin(9600);
}


void flash(){
  
  //Мигание зелёного светодиода
  
  //выключаю все светодиоды
  digitalWrite(y_led, LOW);
  digitalWrite(r_led,LOW);
  digitalWrite(g_led, LOW);
    	delay(interval/10); //ждём столько сколько определенно значением interval
  digitalWrite(g_led, HIGH);//включаю светодиод
  		delay(interval/5); //ждём столько сколько определенно значением interval 
  digitalWrite(g_led, LOW);//выключаю светодиод
    	delay(interval/12); //ждём столько сколько определенно значением interval
  digitalWrite(g_led, HIGH);//включаю светодиод
  		delay(interval/6); //ждём столько сколько определенно значением interval 
  digitalWrite(g_led, LOW);//выключаю светодиод
    	delay(interval/14); //ждём столько сколько определенно значением interval
  digitalWrite(g_led, HIGH);//включаю светодиод
  		delay(interval/7); //ждём столько сколько определенно значением interval 
  digitalWrite(g_led, LOW);//выключаю светодиод
    delay(interval/16); //ждём столько сколько определенно значением interval
  return;
}

void yellow(){
  
  	//загорается жёлтый светодиод
  
    digitalWrite(y_led, HIGH);//включаю жёлтый светодиод,который сигнализирует о скором включении красного
  		delay(interval/4);//задержка определенна значением interval
    digitalWrite(y_led, LOW);//выключаю
  
}

void check_interval(){
  
  //Проверка текущего значения потенциометра
  
 interval=analogRead(potent);//говорю что делать с потенциометром
 interval=map(interval,0,1023,2000,5000);//меняю диапозон значений с 0-1023 до 2000-5000 в будущем это будет скоростью переключения светодиодов
 interval=constrain(interval,2000,5000);//ограничение выхода из диапозона
  
}

void loop()
{ 
    butt=!digitalRead(button);//считыватель нажатия кнопки
    	start://метка для возврата
 	digitalWrite(y_led, LOW);//выключен
    digitalWrite(g_led, LOW);//выключен 
  	preMillis=millis();//начальное время
  
  /*поменял delay на цикл,что бы можно было выбирать 
  время свечения светодиода*/
  
  while((millis()-preMillis)<(interval-(interval/4))){
  		check_interval();//Проверяю врменя задержки
        digitalWrite(r_led, HIGH);//включаю красный светодиод
  }
    	yellow();//желтый свет
    digitalWrite(r_led, LOW);//выключаю красный светодиод
    	preMillis = millis();//начальное время
    digitalWrite(g_led, HIGH);//включаю зелёный светодиод 
  
  /*поменял delay на цикл,что бы можно было включить жёлтый свет,
  а затем и красный, как только они понадобятся*/
  
    	while(millis()-preMillis<interval+50){
          check_interval();//Проверяю врменя задержки
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
