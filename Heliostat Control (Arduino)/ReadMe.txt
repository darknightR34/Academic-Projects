1 - Download "main" folder
2 - Extract folder to a location of your choice
3 - Open "main.ino" using arduino
4 - Connect esp32 and press upload

Once connected to usb, the setup function initiates by homing all motors with a default timeout of
20,000 milliseconds which is 20 seconds.
After that, you can input commands:

1 - 'h' or 'H' followed by the time you want the motor to rotate before timing out. (ex: h 20000)
2 - 'a' or 'A' followed by the amount to rotate in steps and the speed in rpm to rotate in Azymuth direction (Big motor). (ex: a 300 10)
3 - 'e' or 'E' followed by the amount to rotate in steps and the speed in rpm to rotate in Elevation direction (4 mirror motors). (ex: e 100 20)
They will all move one by one with a one second delay inbetween motors.