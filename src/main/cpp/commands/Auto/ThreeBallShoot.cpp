/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/DriveSubsystem.h>
#include <subsystems/ShooterSubsystem.h>
#include <subsystems/IntakeSubsystem.h>
#include <subsystems/IndexerSubsystem.h>

#include <frc2/command/WaitCommand.h>

#include "commands/Auto/ThreeBallShoot.h"
#include "commands/RotateAngle.h"
#include "commands/DriveForTime.h"
#include "commands/PrepareToShoot.h"
#include "commands/Indexer/IndexerInCommand.h"
#include "commands/Indexer/IndexerStopCommand.h"
#include "commands/Shooter/Shoot.h"
#include "commands/Shooter/StopShoot.h"


// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ThreeBallShoot::ThreeBallShoot( 
  DriveSubsystem   *driveSubsystem,
  ShooterSubsystem *shooterSubsystem,
  IntakeSubsystem  *intakeSubsystem,
  IndexerSubsystem *indexerSubsystem
) 
{
  AddCommands(
    //RotateAngle( 90, driveSubsystem ),
    //DriveForTime( 3.0, driveSubsystem ),
    //RotateAngle( -90, driveSubsystem ),
    //PrepareToShoot( driveSubsystem, shooterSubsystem, intakeSubsystem, true ),
    Shoot( indexerSubsystem ),
    frc2::WaitCommand( (units::second_t)3.0 ),
    StopShoot( indexerSubsystem ),
    DriveForTime( 4.0, driveSubsystem )
  );

}
