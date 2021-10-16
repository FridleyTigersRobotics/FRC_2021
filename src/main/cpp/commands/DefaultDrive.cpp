/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DefaultDrive.h"
#include <subsystems/DriveSubsystem.h>

DefaultDrive::DefaultDrive(DriveSubsystem* subsystem,
                           std::function<double()> forward,
                           std::function<double()> rotation)
    : m_drive{subsystem}, m_forward{forward}, m_rotation{rotation} 
{
  AddRequirements({subsystem});
}

void DefaultDrive::Execute() {
  //std::cout << "defaultDrive: " << m_forward() << " " << m_rotation() << "\n";
  m_drive->ArcadeDrive(m_forward(), m_rotation());
}

// Called when the command is initially scheduled.
void DefaultDrive::Initialize() {}

// Called once the command ends or is interrupted.
void DefaultDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool DefaultDrive::IsFinished() { return false; }
