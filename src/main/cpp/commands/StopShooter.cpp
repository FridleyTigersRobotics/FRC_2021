/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StopShooter.h"

StopShooter::StopShooter(ShooterSubsystem* shooterSubsystem) :
  m_shooterSubsystem{ shooterSubsystem }
{
  AddRequirements({shooterSubsystem});
}

// Called when the command is initially scheduled.
void StopShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void StopShooter::Execute() {
  m_shooterSubsystem->StopShooterAngle();
}

// Called once the command ends or is interrupted.
void StopShooter::End(bool interrupted) {
  m_shooterSubsystem->StopShooterAngle();
}

// Returns true when the command should end.
bool StopShooter::IsFinished() { return false; }
