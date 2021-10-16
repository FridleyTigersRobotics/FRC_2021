/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/PrepareToShoot.h"

PrepareToShoot::PrepareToShoot( 
  DriveSubsystem*   driveSubsystem,
  ShooterSubsystem* shooterSubsystem,
  IntakeSubsystem*  intakeSubsystem,
  bool              endWhenReadyToShoot,
  std::function<double()> rotation )
 :
  m_driveSubsystem{driveSubsystem},
  m_shooterSubsystem{shooterSubsystem},
  m_intakeSubsystem{intakeSubsystem},
  m_endWhenReadyToShoot{endWhenReadyToShoot},
  m_rotation{rotation}
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({driveSubsystem, shooterSubsystem, intakeSubsystem});
  m_readyToShoot = false;
}


// Called when the command is initially scheduled.
void PrepareToShoot::Initialize() {
  extern nt::NetworkTableEntry ledStateEntry;
  ledStateEntry.SetDouble( 1 );
  m_shooterSubsystem->SpinupShooter();
  m_timer.Reset();
  m_timer.Start();
  m_driveSubsystem->m_pid.Reset();
  m_shooterSubsystem->m_pid.Reset();
  m_driveSubsystem->m_pidCounter = 0;
}

// Called repeatedly when this Command is scheduled to run
void PrepareToShoot::Execute() {
  if ( m_intakeSubsystem->IsBotLimitEngaged() == false )
  {
    m_shooterSubsystem->StopShooterAngle();
    //m_intakeSubsystem->LowerIntake();
    m_driveSubsystem->ArcadeDrive( 0.0, 0.0 );
  }
  else
  {
    bool xReady = true;//m_driveSubsystem->RotateToTarget();
    bool yReady = m_shooterSubsystem->TiltToTarget();
    m_driveSubsystem->ArcadeDrive( 0.0, m_rotation()*0.8 );
    //m_driveSubsystem->ArcadeDrive( 0.0, 0.0 );
    //std::cout << "ready" << xReady << " " << yReady << m_endWhenReadyToShoot << "\n";
    m_readyToShoot = xReady && yReady;
  }
}

// Called once the command ends or is interrupted.
void PrepareToShoot::End(bool interrupted) {
  extern nt::NetworkTableEntry ledStateEntry;
  ledStateEntry.SetDouble( 0 );

  m_driveSubsystem->ArcadeDrive( 0.0, 0.0 );
  if ( !m_endWhenReadyToShoot )
  {
    m_shooterSubsystem->SpindownShooter();
  }
  
  m_shooterSubsystem->StopShooterAngle();
}

// Returns true when the command should end.
bool PrepareToShoot::IsFinished() { 
  if ( m_endWhenReadyToShoot )
  {
    if ( m_readyToShoot ||
        ( m_timer.Get() >= 3.0 ) )
      {
        return true;
      }
      else
      {
        return false;
      }
  }
  else
  {
    return false;
  }
  
  return m_endWhenReadyToShoot && ( m_readyToShoot ); 
}
