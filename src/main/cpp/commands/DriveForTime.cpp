/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveForTime.h"



DriveForTime::DriveForTime(double driveTime, DriveSubsystem* subsystem) :
  m_drive{subsystem}
{
  // Use addRequirements() here to declare subsystem dependencies.
  m_driveTime = driveTime;
}

// Called when the command is initially scheduled.
void DriveForTime::Initialize()  {
  m_timer.Reset();
  m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveForTime::Execute() {
  m_drive->ArcadeDrive( 0.8, 0.0 );
}

// Called once the command ends or is interrupted.
void DriveForTime::End(bool interrupted) {
  m_drive->ArcadeDrive( 0.0, 0.0 );
}

// Returns true when the command should end.
bool DriveForTime::IsFinished() { 
  return ( m_timer.Get() >= m_driveTime ); 
}
