/*********************************************************
* Arduino Multiple Cores
*
* Demonstrates how to run tasks on separate processor
* cores.
*
* By John M. Wargo
* https://johnwargo.com
**********************************************************/

TaskHandle_t Task0;
TaskHandle_t Task1;

void setup() {
  Serial.begin(115200);
  Serial.println();

  //create a task that executes the Task0code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(Task0code, "Task0", 10000, NULL, 1, &Task0, 0);
  //create a task that executes the Task0code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(Task1code, "Task1", 10000, NULL, 1, &Task1, 1);
}

void loop() {
  // nothing to do here, everything happens in the Tast1Code and Task2Code functions
  Serial.println("Loop");
  delay((int)random(1000, 3000));
}


void Task0code(void* pvParameters) {
  Serial.print("Task0 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    Serial.println("Core 0 processing");
    delay((int)random(100, 1000));
  }
}

void Task1code(void* pvParameters) {
  Serial.print("Task1 running on core ");
  Serial.println(xPortGetCoreID());

  for (;;) {
    Serial.println("Core 1 processing");
    delay((int)random(100, 1000));
  }
}