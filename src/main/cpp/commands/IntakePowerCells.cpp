/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakePowerCells.h"
#include "stdio.h"

IntakePowerCells::IntakePowerCells( IntakeSubsystem*  intakeSubsystem,
                                    IndexerSubsystem* indexerSubsystem ) :
  m_intakeSubsystem {intakeSubsystem},
  m_indexerSubsystem{indexerSubsystem}
{
  AddRequirements( { intakeSubsystem, indexerSubsystem } );
}

// Called when the command is initially scheduled.
void IntakePowerCells::Initialize() 
{
  //std::cout << "IntakePowerCells::Initialize";
  m_indexerSubsystem->InitIndexer();
}

// Called repeatedly when this Command is scheduled to run
void IntakePowerCells::Execute() 
{
  //std::cout << "IntakePowerCells::Execute";
  if ( m_intakeSubsystem->IsBotLimitEngaged() == false )
  {
      //m_intakeSubsystem->LowerIntake();
  }
  else
  {
    m_intakeSubsystem->HoldIntake();
    m_intakeSubsystem->StartIntake();

    m_indexerSubsystem->GetBalls();
  }
}

// Called once the command ends or is interrupted.
void IntakePowerCells::End(bool interrupted) 
{
  //std::cout << "IntakePowerCells::End";
  m_intakeSubsystem->StopIntake();
  m_indexerSubsystem->StopIndexer();
}

// Returns true when the command should end.
bool IntakePowerCells::IsFinished() { return false; }
