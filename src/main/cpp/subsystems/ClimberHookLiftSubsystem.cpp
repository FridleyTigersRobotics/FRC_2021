/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClimberHookLiftSubsystem.h"
#include <stdio.h>


ClimberHookLiftSubsystem::ClimberHookLiftSubsystem() :
    m_hookMotor { HookLiftSubsystemConstants::kHookMotorCanId }
{
    m_hookMotor.SetNeutralMode( ctre::phoenix::motorcontrol::NeutralMode::Brake );
}

void ClimberHookLiftSubsystem::Lift() {
    m_hookMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
    HookLiftSubsystemConstants::kHookMotorLiftSpeed );
    std::cout << "Hook Lift\n";
}

void ClimberHookLiftSubsystem::Lower() {
    m_hookMotor.Set(ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
    -HookLiftSubsystemConstants::kHookMotorLiftSpeed );
    std::cout << "Hook Lower\n";
}

void ClimberHookLiftSubsystem::Hold() {
    m_hookMotor.Set( ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
    0.0 );
    std::cout << "Hook Hold\n";
}



// This method will be called once per scheduler run
void ClimberHookLiftSubsystem::Periodic() {}
