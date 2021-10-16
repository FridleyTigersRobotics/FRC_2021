/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/I2C.h>

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

namespace DriveConstants {
    constexpr int kLeftMotor1Port  = 4;
    constexpr int kRightMotor1Port = 3;
    constexpr int kLeftMotor2Port  = 6;
    constexpr int kRightMotor2Port = 5;

    constexpr float kCenterTargetPosition = 320;

    constexpr float kP    = 0.004f;
    constexpr float kI    = 0.01f;
    constexpr float kD    = 0.000f;
}

namespace ShooterConstants {
    constexpr int kLeftMotorCanId  = 1;
    constexpr int kRightMotorCanId = 2;
    constexpr int kjda = 1; //analog input channel A for John Deere rotation sensor
    constexpr int kjdb = 2; //analog input channel B for John Deere rotation sensor
    constexpr double kDistPerRotation = 360;  //how far the nechanism travels in 1 rotation of the encoder in angular degrees

    constexpr int kLoaderMotorCanId = 3;
    constexpr int kAnglePwmId       = 2;

    constexpr int kSensorId         = 0;


    constexpr float ShooterRpmTarget = 20000.0f; // 20000~30000
    constexpr float ShooterRpmMin    = 480.0f;
    constexpr float ShooterRpmMax    = 520.0f;

    constexpr float kP    = 20.0f;
    constexpr float kI    = 0.0f;
    constexpr float kD    = 1.0f;
}  // namespace ShooterConstants

namespace IntakeConstants {
    constexpr int kIntakeRotateMotorPwmId = 0;
    constexpr int kIntakeExtendMotorPwmId = 1;
    constexpr int kIntakeTopLimitDioPort = 2;
    constexpr int kIntakeBotLimitDioPort = 3;

    constexpr double kIntakeMotorSpeed  = 1.0;
}  // namespace IntakeConstants

namespace DriverStationConstants {
    constexpr int kDriverControllerPort = 0;
}  // namespace DriverStationConstants

namespace IndexerSubsystemConstants {
    constexpr int    kIndexerMotorCanId  = 5;

    constexpr double kIndexerMotorSpeed  = 0.6;
}  // namespace IndexerSubsystemConstants

namespace ClimbSubsystemConstants { 
    constexpr int    kClimbMotorCanId     = 6;
    constexpr double kClimbUpMotorSpeed   = 1.0;
    constexpr double kClimbDownMotorSpeed = 0.4;
}

namespace HookLiftSubsystemConstants { 
    constexpr int    kHookMotorCanId     = 7;
    constexpr double kHookMotorLiftSpeed = 1.0;
}
