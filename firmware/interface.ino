#define IN_PIN   D1
#define OUT_PIN  D3

int on = 0;
int state = 0;
int previous_reading = 1;
int reading;

long toggled_time = 0;
long debounce = 500;

int toggleOn(String status) {
    if (status == "on") {
        digitalWrite(OUT_PIN, 1);
        on = 1;
        return 1;
    } else {
        digitalWrite(OUT_PIN, 0);
        on = 0;
        return 0;
    }
}

void setup() {
    Serial.begin(9960);
    delay(500);

    pinMode(OUT_PIN, OUTPUT);
    pinMode(IN_PIN, INPUT);
    Spark.function("toggleOn", toggleOn);
    Spark.variable("on", &on, INT);
}

void loop() {
    reading = digitalRead(IN_PIN);
    if (reading == 1 && previous_reading == 0 && millis() - toggled_time > debounce) {
      if (on == 1) {
        toggleOn("off");
        /*Spark.publish("off");*/
      } else {
        toggleOn("on");
        /*Spark.publish("on");*/
      }

      toggled_time = millis();
    }
    previous_reading = reading;
    delay(100);
}
