/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <subsystems/DriveSubsystem.h>
#include <subsystems/ShooterSubsystem.h>
#include <subsystems/IntakeSubsystem.h>
#include <subsystems/IndexerSubsystem.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>

class ThreeBallShoot
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 ThreeBallShoot> {
 public:
  ThreeBallShoot( 
    DriveSubsystem   *driveSubsystem,
    ShooterSubsystem *shooterSubsystem,
    IntakeSubsystem  *intakeSubsystem,
    IndexerSubsystem *indexerSubsystem
  );
};
