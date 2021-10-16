/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Shooter/StopShoot.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
StopShoot::StopShoot( IndexerSubsystem*  indexerSubsystem ) :
  m_indexerSubsystem {indexerSubsystem}
{
  AddRequirements( { indexerSubsystem } );
}

// Called when the command is initially scheduled.
void StopShoot::Initialize() {
  m_indexerSubsystem->StopLoadShooter();
  
}