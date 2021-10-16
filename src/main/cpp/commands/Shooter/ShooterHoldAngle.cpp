/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/ShooterHoldAngle.h"

ShooterHoldAngle::ShooterHoldAngle( ShooterSubsystem* shooterSubsystem ) :
  m_shooterSubsystem{shooterSubsystem}
{
  AddRequirements( { shooterSubsystem } );
}

// Called when the command is initially scheduled.
void ShooterHoldAngle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShooterHoldAngle::Execute() {
  m_shooterSubsystem->StopShooterAngle();
}

// Called once the command ends or is interrupted.
void ShooterHoldAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool ShooterHoldAngle::IsFinished() { return false; }
