int r_led =2;//номер пин'а, который будет обеспечивает работу красного светодиода
int y_led =3;//номер пин'а, который будет обеспечивает работу жёлтого светодиода
int g_led =4;//номер пин'а, который будет обеспечивает работу зелёного светодиода
int button = 5;//номер пин'a, который будет отвечать за работу кнопки

void setup()
{
  pinMode(button,INPUT_PULLUP);//кнопке в этом режиме не требуется дополнительный резистор, в ардруине включится свой (встроенный)
  pinMode(r_led, OUTPUT);//красный пин на "вывод" информации
  pinMode(y_led, OUTPUT);//жёлтый пин на "вывод" информации
  pinMode(g_led, OUTPUT);//зелёный пин на "вывод" информации
	Serial.begin(9600);
}

void loop()
{
  bool button1 = !digitalRead(5);//переменная для проверки нажатия кнопки
  
  Serial.print("\n Button1: ");Serial.print(button1);//способ проверки кнопки с выводом информации в консоль 0 - кнопка отпущена, а 1 - конпка нажата 
  
  digitalWrite(r_led, HIGH);//включаю красный светодиод
  digitalWrite(y_led, LOW);//выключен
  digitalWrite(g_led, LOW);//выключен
  	delay(1000); // ждём 1 секунду
  digitalWrite(r_led, LOW);//выключен
  digitalWrite(y_led, HIGH);//включаю жёлый светодиод
  digitalWrite(g_led, LOW);//выключен
  	delay(1000); // ждём 1 секунду
  digitalWrite(r_led, LOW);//выключен
  digitalWrite(y_led, LOW);//выключен
  digitalWrite(g_led, HIGH);//включаю зелёный светодиод
  	delay(1000);// ждём 1 секунду
}