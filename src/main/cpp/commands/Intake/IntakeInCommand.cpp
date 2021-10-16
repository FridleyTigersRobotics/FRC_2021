/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Intake/IntakeInCommand.h"

IntakeInCommand::IntakeInCommand( IntakeSubsystem*  intakeSubsystem ) :
  m_intakeSubsystem {intakeSubsystem}
{
  AddRequirements( { intakeSubsystem } );
}

// Called when the command is initially scheduled.
void IntakeInCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeInCommand::Execute() {
  m_intakeSubsystem->StartIntake();
  m_intakeSubsystem->HoldIntake();
}

// Called once the command ends or is interrupted.
void IntakeInCommand::End(bool interrupted) {
  m_intakeSubsystem->StopIntake();m_intakeSubsystem->StopIntake();
}

// Returns true when the command should end.
bool IntakeInCommand::IsFinished() { return false; }
