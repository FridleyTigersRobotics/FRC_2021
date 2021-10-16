/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc/PWMVictorSPX.h>
#include <ctre/Phoenix.h>
#include <frc/AnalogEncoder.h>
#include <frc/AnalogInput.h>
#include <frc/controller/PIDController.h>

class ShooterSubsystem : public frc2::SubsystemBase {
 public:
  ShooterSubsystem( );

  void Periodic() override;

  void SpinupShooter();

  void SpindownShooter();

  bool IsShooterReady();

  void AngleShooterUp(); 

  void AngleShooterDown();

  void StopShooterAngle() ;

  double GetRotationDegreeA();

  double GetRotationDegreeB();

  void ResetEncoder();

  bool TiltToAngle( double angle );

  bool TiltToTarget();

  double GetMaxAngle();

  double GetMinAngle();

  bool IsShooterFullyLowered();

  void MoveShooter( double speed );
   frc2::PIDController                         m_pid;
 private:
   ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterLeft;
   ctre::phoenix::motorcontrol::can::TalonSRX  m_motorShooterRight;
   frc::PWMVictorSPX                           m_motorAngle;
   frc::AnalogInput                            m_ajdA;
   frc::AnalogInput                            m_ajdB;
   frc::AnalogEncoder                          m_jdA;
   frc::AnalogEncoder                          m_jdB;



  double CalculateTargetAngleFromCameraValue( double );

  int m_goodAngleCount;

};
