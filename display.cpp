#include "display.h"

// Display Definitions
void display(int a, int b)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Recyclable:");
    lcd.print(a);
    lcd.setCursor(0, 1);
    lcd.print("Non-recyclable:");
    lcd.print(b);
}
