class LED_Controls {
  public:

    void Begin(byte GPIO_pin) {
      pinMode(GPIO_pin, OUTPUT);
    }

    void ON(byte GPIO_pin){
      digitalWrite(GPIO_pin, HIGH);
    }

    void OFF(byte GPIO_pin){
      digitalWrite(GPIO_pin,LOW);
    }

    void flash(byte GPIO_pin, int flash_speed, int flashes){
      for (int f=0; f < flashes; f = f +1){
        ON(GPIO_pin);
        delay(flash_speed);
        OFF(GPIO_pin);
        delay(flash_speed);
      }
    }
};

// Class      Object
LED_Controls   LED;

void setup() {
  LED.Begin(LED_BUILTIN);
}



void loop() {
  LED.ON(LED_BUILTIN);
  delay(1000);
  LED.OFF(LED_BUILTIN);
  delay(1000);
  LED.flash(LED_BUILTIN,100,10);
}
