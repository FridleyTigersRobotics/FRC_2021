/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Indexer/IndexerInCommand.h"

IndexerInCommand::IndexerInCommand( IndexerSubsystem* indexerSubsystem ) :
  m_indexerSubsystem{indexerSubsystem}
{
  AddRequirements( { indexerSubsystem } );
}

// Called when the command is initially scheduled.
void IndexerInCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IndexerInCommand::Execute() {
  m_indexerSubsystem->StartIndexer();
}

// Called once the command ends or is interrupted.
void IndexerInCommand::End(bool interrupted) {
  m_indexerSubsystem->StopIndexer();
}

// Returns true when the command should end.
bool IndexerInCommand::IsFinished() { return false; }
