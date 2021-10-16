/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <ctre/Phoenix.h>
#include "Constants.h"

class ClimberHookLiftSubsystem : public frc2::SubsystemBase {
 public:
  ClimberHookLiftSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

void Lift();

void Lower();

void Hold();


 private:
    ctre::phoenix::motorcontrol::can::VictorSPX m_hookMotor;
};
