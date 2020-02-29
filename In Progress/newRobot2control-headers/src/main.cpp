#include "userControl.h"
using namespace vex;

void pre_auton(void) {
  task userControls(userControl);
  motorHold(true);
  calibrateInertial();
  task pickAutonmous(pickAuton);
}

void autonomous(void) {
  calibrateInertial();
  userControlEnabled=false;
  redAutonBottom();
  //runAuton();
}

void usercontrol(void) {//User Control
  userControlEnabled = true;
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
