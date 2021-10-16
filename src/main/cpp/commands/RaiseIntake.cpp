/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <stdio.h>

#include "commands/RaiseIntake.h"

RaiseIntake::RaiseIntake( IntakeSubsystem*  intakeSubsystem ) :
  m_intakeSubsystem {intakeSubsystem}
{
  AddRequirements( { intakeSubsystem } );
}

// Called when the command is initially scheduled.
void RaiseIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void RaiseIntake::Execute() 
{
  m_intakeSubsystem->RaiseIntake();
}

// Called once the command ends or is interrupted.
void RaiseIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool RaiseIntake::IsFinished() { return true; }
