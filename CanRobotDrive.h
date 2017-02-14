/*
 * CanRobotDrive.h
 *
 *  Created on: Feb 1, 2017
 *      Author: mriri
 */

#ifndef SRC_CANROBOTDRIVE_H_
#define SRC_CANROBOTDRIVE_H_

#include <memory>
#include <ErrorBase.h>
#include <MotorSafety.h>
#include <MotorSafetyHelper.h>
#include <CANTalon.h>

class CanRobotDrive: public frc::ErrorBase, public frc::MotorSafety
{
public:
	CanRobotDrive(CANTalon * leftMotor1, CANTalon * leftMotor2,
			CANTalon * rightMotor1, CANTalon * rightMotor2,
			bool invertLeftSide, bool invertRightSide);
	CanRobotDrive(CANTalon * leftMotor1, CANTalon * leftMotor2,
			CANTalon * leftMotor3, CANTalon * rightMotor1,
			CANTalon * rightMotor2, CANTalon * rightMotor3,
			bool invertLeftSide, bool invertRightSide);
	virtual ~CanRobotDrive();

	CanRobotDrive(const CanRobotDrive&) = delete;
	CanRobotDrive& operator=(const CanRobotDrive&) = delete;

	void TankDrive(double leftSide, double rightSide);

	void SetExpiration(double timeout) override;
	double GetExpiration() const override;
	bool IsAlive() const override;
	void StopMotor() override;
	bool IsSafetyEnabled() const override;
	void SetSafetyEnabled(bool enabled) override;
	void GetDescription(std::ostringstream& desc) const override;

private:
	int GetNumMotors();
	void InitRobotDrive(CANTalon * leftMotor1, CANTalon * leftMotor2,
			CANTalon * leftMotor3, CANTalon * rightMotor1,
			CANTalon * rightMotor2, CANTalon * rightMotor3,
			bool invertLeftSide, bool invertRightSide);
	double Limit(double num);

	static const int kMaxNumberOfMotors = 6;

	std::shared_ptr<CANTalon> m_leftMotor1;
	std::shared_ptr<CANTalon> m_leftMotor2;
	std::shared_ptr<CANTalon> m_leftMotor3;
	std::shared_ptr<CANTalon> m_rightMotor1;
	std::shared_ptr<CANTalon> m_rightMotor2;
	std::shared_ptr<CANTalon> m_rightMotor3;
	std::unique_ptr<MotorSafetyHelper> m_safetyHelper;

	bool m_invertLeftSide;
	bool m_invertRightSide;
};

#endif /* SRC_CANROBOTDRIVE_H_ */
