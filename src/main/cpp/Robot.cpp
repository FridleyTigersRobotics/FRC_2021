/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <stdio.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>


#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

nt::NetworkTableEntry xEntry;
nt::NetworkTableEntry yEntry;
nt::NetworkTableEntry ledStateEntry;

void Robot::RobotInit() {
  auto inst  = nt::NetworkTableInstance::GetDefault();
  auto table = inst.GetTable("targetCoords");
  auto ledTable = inst.GetTable("ledState");
  xEntry = table->GetEntry("xVal");
  yEntry = table->GetEntry("yVal");
  ledStateEntry = ledTable->GetEntry("val");
  m_container.InTestMode = false;
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { 
  frc2::CommandScheduler::GetInstance().Run(); 
  }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomousCommand = m_container.GetAutonomousCommand();

  if (m_autonomousCommand != nullptr) {
    std::cout << "CommandListScheduled\n";
    m_autonomousCommand->Schedule();
  }
  else
  {
      std::cout << "CommandList NOT Scheduled\n";
  }
}




void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  //m_container.ahrs.Reset();
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }

  m_container.InTestMode = false;
}



void Robot::TestInit() {
  //m_container.ahrs.Reset();
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }

  m_container.InTestMode = true;
}


/**
 * This function is called periodically during operator control.
 */

int reportCount = 0;

void Robot::TeleopPeriodic() {




reportCount++;

if ( reportCount == 20 )
{
  /*for ( int idx = 1; idx < 16; idx++ )
  {
    if ( m_container.m_buttonBoard.GetRawButtonPressed( idx ) )
    {
      //std::cout << "Button: " << idx << "\n";
    }
  }*/
  //std::cout << "x " << m_container.ahrs.GetRawGyroX() << " ";
  //std::cout << "y " << m_container.ahrs.GetRawGyroY() << " ";
  //std::cout << "z " << m_container.ahrs.GetRawGyroZ() << "\n";

  //std::cout << "angle " << m_container.m_gyro.GetAngle() << "\n";
  reportCount = 0;
}

}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {
  frc2::CommandScheduler::GetInstance().Run(); 
}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
