#include "garbage_collection.h"

// Garbage Collection Definitions
void collect_garbage()
{
    claw.write(0);
    delay(1000);
    claw.write(100);
    delay(1000);
}

void release_garbage(void)
{
    delay(700);
    claw.write(0);
    delay(2000);
}

void move_extension_down(int position)
{
    for (int i = position; i >= 0; i--)
    {
        extension.write(i);
        delay(20);
    }
    delay(1000);
}

void move_extension_up(int garbage_type)
{
    for (int i = 0; i <= garbage_type; i++)
    {
        extension.write(i);
        delay(20);
    }
    delay(1000);
}

int recyclable_garbage(void)
{
    int recyclable = counterA++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Recyclable.");
    delay(1000);
    display(recyclable, counterB);
    move_extension_up(180);
    release_garbage();
    return recyclable;
}

int non_recyclable_garbage(void)
{
    int non_recyclable = counterB++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("NON-Recyclable.");
    delay(1000);
    display(counterA, non_recyclable);
    move_extension_up(155);
    release_garbage();
    return non_recyclable;
}
