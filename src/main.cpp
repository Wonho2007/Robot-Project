#include <FEH.h>
#include <FEHIO.h>
#include <FEHServo.h>
#include <FEHLCD.h>
#include <Arduino.h>


// Declare things like Motors, Servos, etc. here
// For example:
// FEHMotor leftMotor(FEHMotor::Motor0, 6.0);
// FEHServo servo(FEHServo::Servo0);


void ERCMain()
{


    
    FEHMotor rightDrive(FEHMotor::Motor0, 9.0);
    FEHMotor leftDrive(FEHMotor::Motor1, 9.0);
    DigitalInputPin backLeftBumper(FEHIO::Pin8);
    DigitalInputPin backRightBumper(FEHIO::Pin1);
    DigitalInputPin frontLeftBumper(FEHIO::Pin14);
    DigitalInputPin frontRightBumper(FEHIO::Pin3);


    
    //Wait for input
    while(backLeftBumper.Value());

    Sleep(1);

    rightDrive.SetPercent(-25);
    leftDrive.SetPercent(25);

    //Wait for front bumpers to get hit
    while(frontLeftBumper.Value() || frontRightBumper.Value());

    //Turn right
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(25);

    //Wait for back bumper to hit wal
    while(backLeftBumper.Value() || backRightBumper.Value());

    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);

    Sleep(1);

    //Drive forward
    leftDrive.SetPercent(25);
    rightDrive.SetPercent(-25);

    //PART 2

    //Wait for front bumpers to get hit
    while(frontLeftBumper.Value() || frontRightBumper.Value());

    //Stop
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);
    Sleep(0.5);

    //Turn left
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(25);

    //Wait for back bumper to hit wal
    while(backLeftBumper.Value());

    //Align with wall
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);
    Sleep(0.5);

    leftDrive.SetPercent(-25);
    rightDrive.SetPercent(0);

    while(backRightBumper.Value());

    //Stop
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);
    Sleep(0.5);

    rightDrive.SetPercent(25);
    leftDrive.SetPercent(-25);

    //Wait for front bumpers to get hit
    while(frontLeftBumper.Value() || frontRightBumper.Value());
     //Stop
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);
    Sleep(0.5);


    leftDrive.SetPercent(-25);
    rightDrive.SetPercent(25);
    
    Sleep(1.0);

    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);

    Sleep(1.0);
    leftDrive.SetPercent(25);
    rightDrive.SetPercent(25);




}