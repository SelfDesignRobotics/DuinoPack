# DuinoPack

The Duinobot controller is an Arduino clone; it can be programmed with the tools available for any Arduino controller board.  These instructions are for setting up the Duinobot V2.3 controller and the modified Arduino IDE from this git.

##CDC/HID USB mode

The USB port on the Duinobot V2.3 controller can be setup in CDC or HID mode.  There are advantages to either mode but if you plan to use the Duinobot controller with the Arduino IDE you want to set it up in CDC mode.  By default the controller is set to HID mode; to change the mode a jumper needs to be installed connecting the two pins labelled CDC on the front face of the board.  The rest of these instructions assume the controller is set to CDC USB mode.

##Installing the Arduino IDE

###Installing the Arduino IDE For Windows

Follow these steps to install the Arduino IDE for Windows (these instructions are adapted from http://arduino.cc/en/guide/windows#toc4 ... if you get stuck following the steps listed below these original directions may help you out):

1. Download the ZIP file for this repository to your computer
2. Unzip the downloaded file, the unzipped file contains a top-level sub-directory called 'win'.
3. Launch arduino.exe (found in win subdirectory of the zip file) and follow on-screen instructions

####Installing the Windows USB Driver

You also need to manually install the Windows driver for the Duinobot controller (see additional note below for Windows 8/8.1):

1. Plug in the Duinobot controller to your computer using the supplied USB cable.  
2. If a green LED on the controller does not light up and stay on (meaning that the Duinobot controller is 'on') press the 'Power' button on the controller so that the green LED turns on.
3. Wait for Windows to begin it's driver installation process. After a few moments, the process will fail.
Click on the Windows Start Menu, and open up the Control Panel from the start menu.
4. In the Control Panel navigate to System and Security. Next, click on System. Once the System window is up, open the Device Manager.
5. If you are unable to locate the Device Manager as described above, it appears at the top level of the Control Panel on Windows 7. You can also search for "Device Manager" from the Windows Start menu search bar.
6. In the Device Manager look under Ports (COM & LPT). You should see an open port named "Duinobot ...". If there is no COM & LPT section, look under "Other Devices" for "Unknown Device".
7. Right click on the "Duinobot ..." device that you just identified and choose the "Update Driver Software" option.
8. Next, choose the "Browse my computer for Driver software" option. 
9. Finally, navigate to and select the driver file named "Multiplo.USBSerial.inf", located in the "Drivers" folder of the unzipped 'win' folder.
10. On some systems you will not be able to browse the actual file.  If this is the case just choose the 'drivers' directory and the computer should figure out the appropriate driver.
11. Select 'OK' and Windows will finish up the driver installation from there.
12. You may see a warning that the publisher of the driver cannot be verified.  Select 'Install this driver software only'.

**See also:** [step-by-step screenshots for installing an Uno under Windows XP if you need more help.](http://arduino.cc/en/Guide/UnoDriversWindowsXP)

**NOTE:** On Windows 8/8.1 you will need to disable the requirement that all drivers be digitally signed; an unsigned driver cannot be used on Windows 8 unless this requirement is disabled.  Practically this means that prior to installing the Duinobot driver you should follow the instructions outlined [here](http://mytechblog.com/tutorials/arduino/install-arduino-drivers-on-windows-8/).

###Installing the Arduino IDE For Mac

1. Download the zip file for this repository to your computer
2. Decompress the zip file if this did not happen automatically.
3. Using a file browser drag the 'Arduino.app' sub-directory to your Applications folder

###Installing the Arduino IDE for Linux

We have not tried this yet.

