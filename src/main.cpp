#include <FEH.h>
#include <Arduino.h>

// Declare things like Motors, Servos, etc. here
// For example:
// FEHMotor leftMotor(FEHMotor::Motor0, 6.0);
// FEHServo servo(FEHServo::Servo0);

void explorationOne();
void explorationTwo();
enum LineStates
{
    MIDDLE,
    RIGHT,
    LEFT
};

void ERCMain()
{

    // Your code here!

    explorationTwo();
}

void lineFolowing()
{

    FEHMotor rightDrive(FEHMotor::Motor0, 9.0);
    FEHMotor leftDrive(FEHMotor::Motor1, 9.0);
    DigitalInputPin backRightBumper (FEHIO::Pin0);
    AnalogInputPin rightOpt(FEHIO::Pin8);
    AnalogInputPin middleOpt(FEHIO::Pin9);
    AnalogInputPin leftOpt(FEHIO::Pin10);

    int state = MIDDLE;

    while(backRightBumper.Value());

    while (true)
    { // I will follow this line forever!

        switch (state)
        {

            // If I am in the middle of the line...

        case MIDDLE:

            // Set motor powers for driving straight

            rightDrive.SetPercent(25);
            leftDrive.SetPercent(25);

            if (rightOpt.Value() > 3)
            {
                state = RIGHT; // update a new state
            }

            /* Code for if left sensor is on the line */
            if (leftOpt.Value() > 2.5)
            {
                state = LEFT; // update a new state
            }

            break;

            // If the right sensor is on the line...

        case RIGHT:

            // Set motor powers for right turn

            rightDrive.SetPercent(10);
            leftDrive.SetPercent(25);

            if (rightOpt.Value() < 2)
            {
                state = MIDDLE;
            }

            break;

            // If the left sensor is on the line...

        case LEFT:

            /* Mirror operation of RIGHT state */
            rightDrive.SetPercent(25);
            leftDrive.SetPercent(10);

            if (leftOpt.Value() < 2)
            {
                state = MIDDLE;
            }

            break;

        default: // Error. Something is very wrong.

            break;
        }

        // Sleep a bit
    }
}






void explorationOne()
{
    FEHMotor rightDrive(FEHMotor::Motor0, 9.0);
    FEHMotor leftDrive(FEHMotor::Motor1, 9.0);
    DigitalInputPin backLeftBumper(FEHIO::Pin8);
    DigitalInputPin backRightBumper(FEHIO::Pin1);
    DigitalInputPin frontLeftBumper(FEHIO::Pin14);
    DigitalInputPin frontRightBumper(FEHIO::Pin3);

    // Wait for input
    while (backLeftBumper.Value())
        ;

    Sleep(1.);

    rightDrive.SetPercent(25);
    leftDrive.SetPercent(25);

    // Wait for front bumpers to get hit
    while (frontLeftBumper.Value() || frontRightBumper.Value())
        ;

    // Turn right
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(-25);

    // Wait for back bumper to hit wal
    while (backRightBumper.Value())
        ;

    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);

    Sleep(1.);

    leftDrive.SetPercent(-25);
    rightDrive.SetPercent(0);

    while (backLeftBumper.Value())
        ;

    // Drive forward
    leftDrive.SetPercent(25);
    rightDrive.SetPercent(25);

    // PART 2

    // Wait for front bumpers to get hit
    while (frontLeftBumper.Value() || frontRightBumper.Value())
        ;

    // Stop
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);
    Sleep(0.5);

    // Turn back left
    leftDrive.SetPercent(-25);
    rightDrive.SetPercent(0);

    // Wait for back bumper to hit wal
    while (backLeftBumper.Value())
        ;

    // Align with wall
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);
    Sleep(0.5);

    leftDrive.SetPercent(0);
    rightDrive.SetPercent(-25);

    while (backRightBumper.Value())
        ;

    // Stop
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);
    Sleep(0.5);

    // forward
    rightDrive.SetPercent(25);
    leftDrive.SetPercent(25);

    // Wait for front bumpers to get hit
    while (frontLeftBumper.Value() || frontRightBumper.Value())
        ;
    // Stop
    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);
    Sleep(0.5);

    leftDrive.SetPercent(-25);
    rightDrive.SetPercent(-25);

    Sleep(1.0);

    leftDrive.SetPercent(0);
    rightDrive.SetPercent(0);

    Sleep(1.0);
    leftDrive.SetPercent(25);
    rightDrive.SetPercent(-25);
}