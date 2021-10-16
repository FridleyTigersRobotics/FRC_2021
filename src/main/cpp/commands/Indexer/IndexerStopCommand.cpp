/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Indexer/IndexerStopCommand.h"

IndexerStopCommand::IndexerStopCommand( IndexerSubsystem* indexerSubsystem ) :
  m_indexerSubsystem{indexerSubsystem}
{
  AddRequirements( { indexerSubsystem } );
}

// Called when the command is initially scheduled.
void IndexerStopCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IndexerStopCommand::Execute() {
  m_indexerSubsystem->StopIndexer();
}

// Called once the command ends or is interrupted.
void IndexerStopCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool IndexerStopCommand::IsFinished() { return false; }
