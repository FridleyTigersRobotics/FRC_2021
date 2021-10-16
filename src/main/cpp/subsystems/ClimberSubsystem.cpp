/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Constants.h>

#include "subsystems/ClimberSubsystem.h"

ClimberSubsystem::ClimberSubsystem() 
    //m_climbMotor{ ClimbSubsystemConstants::kClimbMotorCanId, rev::CANSparkMax::MotorType::kBrushless }
{ 
}

void ClimberSubsystem::ClimbUp() {
    //m_climbMotor.Set( -ClimbSubsystemConstants::kClimbUpMotorSpeed );
}

void ClimberSubsystem::ClimbDown() {
    //m_climbMotor.Set( ClimbSubsystemConstants::kClimbDownMotorSpeed );
}

void ClimberSubsystem::ClimbHold() {
    //m_climbMotor.Set( 0.0 );
}


// This method will be called once per scheduler run
void ClimberSubsystem::Periodic() {}
