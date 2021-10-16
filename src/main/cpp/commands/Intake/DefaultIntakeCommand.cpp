/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/DefaultIntakeCommand.h"

DefaultIntakeCommand::DefaultIntakeCommand( IntakeSubsystem*  intakeSubsystem ) :
  m_intakeSubsystem {intakeSubsystem}
{
  AddRequirements( { intakeSubsystem } );
}

// Called when the command is initially scheduled.
void DefaultIntakeCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DefaultIntakeCommand::Execute() {
  
}

// Called once the command ends or is interrupted.
void DefaultIntakeCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool DefaultIntakeCommand::IsFinished() { return false; }
