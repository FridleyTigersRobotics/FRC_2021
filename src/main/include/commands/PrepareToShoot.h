/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <subsystems/DriveSubsystem.h> 
#include <subsystems/IntakeSubsystem.h> 
#include <subsystems/IndexerSubsystem.h> 
#include <subsystems/ShooterSubsystem.h> 


/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class PrepareToShoot
    : public frc2::CommandHelper<frc2::CommandBase, PrepareToShoot> {
 public:
  PrepareToShoot( DriveSubsystem*   driveSubsystem,
                  ShooterSubsystem* shooterSubsystem,
                  IntakeSubsystem*  intakeSubsystem,
                  bool              endWhenReadyToShoot,
                  std::function<double()> rotation );

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

 private:
  DriveSubsystem*   m_driveSubsystem; 
  ShooterSubsystem* m_shooterSubsystem;
  IntakeSubsystem*  m_intakeSubsystem;
  bool              m_endWhenReadyToShoot;
  bool m_readyToShoot;
  std::function<double()> m_rotation;
  frc::Timer m_timer;  
};
