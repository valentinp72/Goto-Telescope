#include <AccelStepper.h>

#define STEP_ANGLE        1.8
#define RESOLUTION        16
#define REAL_STEP_ANGLE   STEP_ANGLE / RESOLUTION

// Speeds and accelerations (RPS = Rotations Per Second)
#define MAX_RPS 30
#define DEFAULT_ACCELERATION 5000

class Motor {

private:

	int stepPin;
	int dirPin;
	int enablePin;

	bool emergencyStopped;
	AccelStepper stepper;

public:

	Motor::Motor(int stepPin, int dirPin, int enablePin) {
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
		// alignement procedure
		this->disable();
		delay(5000);
		this->enable();
		this->setAlignement(0);

		this->setTarget(90);
		this->runToPosition();

		this->setTarget(-135);
		this->runToPosition();

		this->setTarget(900);
		this->runToPosition();

		this->setTarget(0);
		this->runToPosition();
	}

	void run() {
		if(!emergencyStopped)
		stepper.run();
	}

	void runToPosition() {
		if(!emergencyStopped)
		stepper.runToPosition();
	}

	void emergencyStop(bool active) {
		if(active) {
			stepper.setAcceleration(10000000);
			stepper.moveTo(stepper.currentPosition());
			stepper.runToPosition();
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
