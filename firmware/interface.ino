#define OUT_PIN  D3

int on = 0;

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
    Spark.function("toggleOn", toggleOn);
    Spark.variable("on", &on, INT);
}

void loop() {
    delay(2000);
}
