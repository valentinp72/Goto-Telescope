#include <AccelStepper.h>

#define STEP_ANGLE        1.8
#define RESOLUTION        16
#define REAL_STEP_ANGLE   STEP_ANGLE / RESOLUTION

// Speeds and accelerations (RPS = Rotations Per Second)
#define MAX_RPS 30
#define DEFAULT_ACCELERATION 500

class Motor {

private:

	int stepPin;
	int dirPin;
	int enablePin;

	bool emergencyStopped;
	AccelStepper stepper;

public:

	Motor(int stepPin, int dirPin, int enablePin) {
		this->stepPin   = stepPin;
		this->dirPin    = dirPin;
		this->enablePin = enablePin;
		this->stepper   = AccelStepper(AccelStepper::DRIVER, stepPin, dirPin);
		this->stepper.setMaxSpeed(calcStepsAngle(MAX_RPS * 360));
		this->stepper.setAcceleration(DEFAULT_ACCELERATION);
		this->emergencyStopped = false;
		this->enable();
	}

	void setAlignement(long theoricalAngle) {
		stepper.setCurrentPosition(calcStepsAngle(theoricalAngle));
	}

	void setTarget(long angle) {
		stepper.moveTo(calcStepsAngle(angle));
	}

	void configurationTest() {
/*
		this->disable();
		delay(5000);
		this->enable();
		this->setAlignement(0);

		this->setTarget(90);

		this->setTarget(-135);*/
		//if(stepper->distanceToGo() == 0) {
		//	/* code */
		//}


		this->setTarget(9000);
	}

	void run() {
		if(!emergencyStopped)
		stepper.run();
	}

	void runToPosition() {
    while(stepper.isRunning() != 0) {
        run();
    }
	}

	void emergencyStop(bool active) {
		if(active) {
      stepper.setAcceleration(10000000);
      while(stepper.distanceToGo() != 0) {
        stepper.moveTo(stepper.currentPosition());
        stepper.run();
      }
      stepper.setAcceleration(DEFAULT_ACCELERATION);
		}
		emergencyStopped = active;
	}

	void enable() {
		digitalWrite(enablePin, LOW);
	}

	void disable() {
		digitalWrite(enablePin, HIGH);
	}


private:

	long calcStepsAngle(long angle) {
		return angle / (REAL_STEP_ANGLE * 1.0);
	}

};
