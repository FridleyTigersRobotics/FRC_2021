/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <stdio.h>
#include "commands/RotateAngle.h"



RotateAngle::RotateAngle(double angleChange, DriveSubsystem* subsystem) :
  m_angleChange{angleChange},
  m_drive{subsystem}
{
  AddRequirements({subsystem});
}

// Called when the command is initially scheduled.
void RotateAngle::Initialize() {
  double const startingAngle = m_drive->GetAngle();
  m_targetAngle = startingAngle + m_angleChange;
  m_angleCorrectCount = 0;
  std::cout << "Change Init " << m_angleChange << "\n";
}

// Called repeatedly when this Command is scheduled to run
void RotateAngle::Execute() {
  double const angleDiffMaxPower    = 90;
  double const angleDiff            = m_drive->GetAngle() - m_targetAngle;
  double const rotateSpeedAbsMin    = 0.4;
  double const rotateSpeedAbsMax    = 0.5;
  double const rotateSpeed          = angleDiff / angleDiffMaxPower;
  double const rotateSpeedSaturated =
    ( rotateSpeed > 0 ) ? 
        std::clamp( rotateSpeed,  rotateSpeedAbsMin,  rotateSpeedAbsMax ) :
        std::clamp( rotateSpeed, -rotateSpeedAbsMax, -rotateSpeedAbsMin );

  std::cout << "Change Execute " << angleDiff << " " << rotateSpeedSaturated << "\n";
  //m_angleCorrectCount = 5;
  //m_drive->ArcadeDrive( 0.0, 0.0 );
  m_drive->ArcadeDrive( 0.0, rotateSpeedSaturated );

  if ( fabs( angleDiff ) < 10.0 )
  {
    m_angleCorrectCount++;
  }
  else
  {
    m_angleCorrectCount = 0;
  }
}

// Called once the command ends or is interrupted.
void RotateAngle::End(bool interrupted) {
  std::cout << "Change Angle Done" << "\n" << std::flush;
}

// Returns true when the command should end.
bool RotateAngle::IsFinished() 
{ 
  return m_angleCorrectCount > 4; 
}
