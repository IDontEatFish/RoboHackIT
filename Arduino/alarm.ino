#include "MCreatorLink.h"

int active = 7;
int passive = 8;

void dataEvent(String command, String data)
{

    if (data.equals("alarm"))
    {

        for (int i = 2; i < 20; i++)
        {

            digitalWrite(passive, HIGH);

            for (int x = 1; x < 6; x++)
            {
                digitalWrite(x, HIGH);
            }

            delay(60);

            for (int x = 1; x < 6; x++)
            {
                digitalWrite(x, LOW);
            }
            delay(60);
        }
    }

    digitalWrite(passive, LOW);
}

void setup()
{

    pinMode(passive, OUTPUT);
    pinMode(active, OUTPUT);

    for (int i = 2; i < 6; i++)
    {
        pinMode(i, OUTPUT);
    }

    Serial.begin(115200);
    Serial.setTimeout(20);
    MCreatorLink.setup(Serial, "Device Name");
    MCreatorLink.setListener(dataEvent);
}

void loop()
{
    MCreatorLink.loop();
}
