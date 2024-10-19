#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
// are we cooked? are we cooking?

void safe_5_ring_route_flip(){
    //version number 1.0 draft route
    //issues: intake range, time to end
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize 1.5, 0.1, 0.15
    MoveEncoderPID(TestPara, -60, 28, 0.2, 0, true);
    wait(250,msec);
    Clamp.set(false);
    wait(250,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 140, 1, true);
    MoveEncoderPID(TestPara, 50, 43.5, 0.2, 140, true);
    MoveEncoderPID(TestPara, -60, 4, 0.2, 140, true);
    TurnMaxTimePID(TestPara, 130, 0.5, true);
    MoveEncoderPID(TestPara, 50, 17, 0.2, 130, true);
    wait(250,msec);
    MoveEncoderPID(TestPara, -60, 20, 0.2, 130, true);
    TurnMaxTimePID(TestPara, 80, 1, true);
    MoveEncoderPID(TestPara, 60, 12, 0.2, 80, true);
    TurnMaxTimePID(TestPara, 26, 1, true);
    MoveEncoderPID(TestPara, 100, 70, 0.2, 26, true);
    MoveTimePID(TestPara, 100, 0.3, 0.2, 26, false);
    TurnMaxTimePID(TestPara, 50, 1, true);
    MoveEncoderPID(TestPara, -100, 70, 0.2, 50, true);
    RunRoller(40);
    MoveEncoderPID(TestPara, -60, 15, 0.2, 50, true);





  //  Clamp.set(true);
   // MoveEncoderPID(TestPara, -100, 10, 0.2, 0, true);
//    MoveEncoderPID(TestPara, -40, 22, 0.2, 0, false);
//    wait(500,msec);
//    Clamp.set(false);
//    wait(500,msec);
//    RunRoller(100);
//    wait(500,msec);
//    TurnMaxTimePID(TestPara, -60, 1, true);
//    MoveEncoderPID(TestPara, 60, 22, 0.2, -60, true);
//    MoveEncoderPID(TestPara, -60, 1, 0.2, -60, true);
//    TurnMaxTimePID(TestPara, -140, 1, true);
//    MoveEncoderPID(TestPara, 60, 22, 0.2, -140, true);
//    MoveEncoderPID(TestPara, -60, 3, 0.2, -140, true);
//    TurnMaxTimePID(TestPara, -110, 1, true);
//    MoveEncoderPID(TestPara, 60, 11, 0.2, -110, true);
//    MoveEncoderPID(TestPara, -60, 6, 0.2, -110, true);
//   TurnMaxTimePID(TestPara, 2.5, 1, true);
//    MoveEncoderPID(TestPara, 60, 100, 0.2, 2.5, true);
  //  TurnMaxTimePID(TestPara, -5, 1, true);
  ///  MoveEncoderPID(TestPara, -60, 100, 0.2, 2.5, true);



}