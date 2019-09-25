int r_led =0;//назвиние пин'а, который обеспечивает работу красного светодиода
int y_led =1;//назвиние пин'а, который обеспечивает работу жёлтого светодиода
int g_led =2;//назвиние пин'а, который обеспечивает работу зелёного светодиода


void setup()
{
  pinMode(r_led, OUTPUT);//назначаю 0 - красный пин на "вывод" информации
  pinMode(y_led, OUTPUT);//назначаю 1 - жёлтый пин на "вывод" информации
  pinMode(g_led, OUTPUT);//назначаю 2 - зелёный пин на "вывод" информации
}

void loop()
{
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
