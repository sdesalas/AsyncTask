#include <AsyncTask.h>

AsyncTask asyncTask;

unsigned int repeatId;

void setup() {
  Serial.begin(9600);

  // Run this task once after 1 second
  asyncTask.once(taskOne, 1000);

  // Run this task every 2 seconds
  repeatId = asyncTask.repeat(taskTwo, 2000);

  // Run this anonymous task once after 3 second
  asyncTask.once([]() {
    Serial.println("i'm anonymous function task");
  }, 3000);

  asyncTask.once([]() {
    Serial.println("Task Two stopped!");
    asyncTask.remove(repeatId);
  }, 10000);
}

void loop() {
  // Check and run scheduled tasks
  asyncTask.loop();
}

void taskOne() {
  Serial.println("Task One executed (once)!");
}

void taskTwo() {
  Serial.println("Task Two executed (repeating)!");
}
