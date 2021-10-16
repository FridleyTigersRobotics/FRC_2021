/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DefaultIntakeControl.h"

DefaultIntakeControl::DefaultIntakeControl(IntakeSubsystem*  intakeSubsystem ) :
  m_intakeSubsystem {intakeSubsystem}
{
  AddRequirements( { intakeSubsystem } );
}

// Called when the command is initially scheduled.
void DefaultIntakeControl::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DefaultIntakeControl::Execute() 
{
  m_intakeSubsystem->LowerIntake();
}

// Called once the command ends or is interrupted.
void DefaultIntakeControl::End(bool interrupted) {}

// Returns true when the command should end.
bool DefaultIntakeControl::IsFinished() { return false; }
