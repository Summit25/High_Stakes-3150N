#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
// are we cooked? are we cooking?

void mogo_rush(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    MoveEncoderPID(TestPara, -60, 28, 0.2, 0, true);
    wait(250,msec);
    Clamp.set(false);
    wait(250,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -110, 1, true);
    MoveEncoderPID(TestPara, 60, 25, 0.2, -110, true);
    wait(700,msec);
    TurnMaxTimePID(TestPara, 60, 1, true);
    MoveEncoderPID(TestPara, 60, 43, 0.2, 60, true);
    Clamp.set(true);
    IntakeLift.set(true);
    
}