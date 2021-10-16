/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <subsystems/DriveSubsystem.h>
#include <stdio.h>

#define USE_PID_FOR_ROTATE ( 1 )

using namespace DriveConstants;

DriveSubsystem::DriveSubsystem( std::function<double()> currentAngle )
    : m_pid{ DriveConstants::kP, DriveConstants::kI, DriveConstants::kD },
      m_left1{kLeftMotor1Port},
      m_left2{kLeftMotor2Port},
      m_right1{kRightMotor1Port},
      m_right2{kRightMotor2Port},
      m_currentAngle{currentAngle}
{
  m_drive.SetMaxOutput(0.95);
  m_pidCounter = 0;
#if USE_PID_FOR_ROTATE
    m_pid.SetTolerance(5.0, 10);
    m_pid.SetIntegratorRange(-0.6, 0.6);
#endif

}

double DriveSubsystem::GetAngle() 
{
  return m_currentAngle();
}


// This method will be called once per scheduler run
void DriveSubsystem::Periodic() {


}

void DriveSubsystem::ArcadeDrive(double fwd, double rot) {
  //std::cout << "ArcadeDrive: " << fwd << " " << rot << "\n";
  m_drive.ArcadeDrive(-fwd, rot);
}

void DriveSubsystem::SetMaxOutput(double maxOutput) {
  m_drive.SetMaxOutput(maxOutput);
}


bool DriveSubsystem::RotateToTarget()
{
  bool const debugOutput = false;

  extern nt::NetworkTableEntry xEntry;
  double const xVal = xEntry.GetDouble( -1.0 );

  if ( debugOutput )
  {
    std::cout << "xVal: " << xVal << "\n";
  }
  
#if USE_PID_FOR_ROTATE

  double const motorControl = m_pid.Calculate( xVal, kCenterTargetPosition );
  if ( 0 )
  {
    extern nt::NetworkTableEntry yEntry;
    extern nt::NetworkTableEntry xEntry;
    double const yVal = yEntry.GetDouble( -1.0 );
    double const xVal = xEntry.GetDouble( -1.0 );

    

      std::cout << "x " <<  
          xVal << " " << 
          m_pid.GetPositionError() << " " <<
          m_pid.GetSetpoint() <<   " " <<
          motorControl << " " <<
          "\n";
  }


  if ( xVal > -1 )
  {
    m_drive.ArcadeDrive( 0.0, std::clamp( motorControl, -1.0, 1.0 )  );
  }
  else
  {
    m_pid.Reset();
    m_drive.ArcadeDrive( 0.0, 0.0 );
  }

  return m_pid.AtSetpoint();
#else
  if ( xVal < 0 )
  {
    m_goodAngleCount = 0;
    m_drive.ArcadeDrive( 0.0, 0.0 );
  }
  else
  {
    double const center = 150;
    double const offset = xVal - center;
    if ( debugOutput )
    {
      std::cout << "offset: " << offset << " " << fabs( offset ) << "\n";
    }

    if ( fabs( offset ) < 8 )
    {
      m_goodAngleCount++;
    }
    else
    {
      {
        m_goodAngleCount = 0;
      }
    }
    

    if ( fabs( offset ) > 5 )
    {
      double const minSpeed = 0.5;
      double const maxSpeed = 1.0;
      double const speed = fabs( offset ) / 150;
      double const tempSpeed = ( speed < minSpeed ) ? minSpeed : speed;
      double const finalSpeed = ( tempSpeed > maxSpeed ) ? maxSpeed : tempSpeed;


      

      if ( offset > 0 )
      {
        std::cout << "rot: " << -finalSpeed  << "\n";
        m_drive.ArcadeDrive( 0.0, -finalSpeed );
      }
      else
      {
        std::cout << "rot: " << finalSpeed  << "\n";
        m_drive.ArcadeDrive( 0.0, finalSpeed );
      }
      
    }
    else
    {
      m_drive.ArcadeDrive( 0.0, 0.0 );
    } 
  }

  return m_goodAngleCount > 2;
#endif
}



