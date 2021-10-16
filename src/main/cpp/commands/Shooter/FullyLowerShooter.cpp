/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/FullyLowerShooter.h"

FullyLowerShooter::FullyLowerShooter( ShooterSubsystem* shooterSubsystem ) :
  m_shooterSubsystem{shooterSubsystem}
{
  AddRequirements( { shooterSubsystem } );
}

// Called when the command is initially scheduled.
void FullyLowerShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void FullyLowerShooter::Execute() {
  m_shooterSubsystem->AngleShooterDown();
}

// Called once the command ends or is interrupted.
void FullyLowerShooter::End(bool interrupted) {
  m_shooterSubsystem->StopShooterAngle();
}

// Returns true when the command should end.
bool FullyLowerShooter::IsFinished() { return m_shooterSubsystem->IsShooterFullyLowered(); }
