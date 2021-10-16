/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Constants.h"
#include "subsystems/ShooterSubsystem.h"
#include "stdio.h"

#define USE_SHOOTER_PID ( 1 )


ShooterSubsystem::ShooterSubsystem( )  : 
    m_pid        { ShooterConstants::kP, ShooterConstants::kI, ShooterConstants::kD },
    m_motorShooterLeft  { ShooterConstants::kLeftMotorCanId  },
    m_motorShooterRight { ShooterConstants::kRightMotorCanId },
    m_motorAngle { ShooterConstants::kAnglePwmId },
    m_ajdA       { ShooterConstants::kjda },
    m_ajdB       { ShooterConstants::kjdb },
    m_jdA        { m_ajdA },
    m_jdB        { m_ajdB }

{
    int kTimeoutMs = 30;
    m_motorShooterLeft.ConfigFactoryDefault();
    m_motorShooterLeft.SetInverted(true);
    /* first choose the sensor */
    m_motorShooterLeft.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, ShooterConstants::kSensorId, kTimeoutMs);
    m_motorShooterLeft.SetSensorPhase(true);

    /* set the peak and nominal outputs */
    m_motorShooterLeft.ConfigNominalOutputForward(0, kTimeoutMs);
    m_motorShooterLeft.ConfigNominalOutputReverse(0, kTimeoutMs);
    m_motorShooterLeft.ConfigPeakOutputForward(1, kTimeoutMs);
    m_motorShooterLeft.ConfigPeakOutputReverse(-1, kTimeoutMs);
    /* set closed loop gains in slot0 */
    double const F = 0.0420;
    double const P = 0.25;

    m_motorShooterLeft.Config_kF(ShooterConstants::kSensorId, F, kTimeoutMs);
    m_motorShooterLeft.Config_kP(ShooterConstants::kSensorId, P, kTimeoutMs);
    m_motorShooterLeft.Config_kI(ShooterConstants::kSensorId, 0.0, kTimeoutMs);
    m_motorShooterLeft.Config_kD(ShooterConstants::kSensorId, 0.0, kTimeoutMs);

    m_motorShooterRight.ConfigFactoryDefault();
    /* first choose the sensor */
    m_motorShooterRight.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, ShooterConstants::kSensorId, kTimeoutMs);
    m_motorShooterRight.SetSensorPhase(true);

    /* set the peak and nominal outputs */
    m_motorShooterRight.ConfigNominalOutputForward(0, kTimeoutMs);
    m_motorShooterRight.ConfigNominalOutputReverse(0, kTimeoutMs);
    m_motorShooterRight.ConfigPeakOutputForward(1, kTimeoutMs);
    m_motorShooterRight.ConfigPeakOutputReverse(-1, kTimeoutMs);
    /* set closed loop gains in slot0 */
    m_motorShooterRight.Config_kF(ShooterConstants::kSensorId, F, kTimeoutMs);
    m_motorShooterRight.Config_kP(ShooterConstants::kSensorId, P, kTimeoutMs);
    m_motorShooterRight.Config_kI(ShooterConstants::kSensorId, 0.0, kTimeoutMs);
    m_motorShooterRight.Config_kD(ShooterConstants::kSensorId, 0.0, kTimeoutMs);

#if USE_SHOOTER_PID
    m_pid.SetTolerance(0.01, 10);
#else
    m_goodAngleCount = 0;
#endif
}

// This method will be called once per scheduler run
void ShooterSubsystem::Periodic() {
    if ( 1 )
    {
        extern nt::NetworkTableEntry yEntry;
        extern nt::NetworkTableEntry xEntry;
        double const yVal = yEntry.GetDouble( -1.0 );
        double const xVal = xEntry.GetDouble( -1.0 );



        if ( 1 )
        {
            std::cout << "angle " << 
                yVal << " " <<  
                GetRotationDegreeA() <<  "\n";
        }
    }
    if ( 0 )
    {
        //std::cout << "angle " << GetRotationDegreeA() << " " << GetRotationDegreeB() << "\n";
        std::cout << "shoot " << 
        m_motorShooterLeft.GetMotorOutputPercent() << " " << 
        m_motorShooterLeft.GetSelectedSensorVelocity( ShooterConstants::kSensorId ) << " " << " " << 
        m_motorShooterRight.GetMotorOutputPercent() << " " << 
        m_motorShooterRight.GetSelectedSensorVelocity( ShooterConstants::kSensorId ) << "\n";
    }
}


void ShooterSubsystem::SpinupShooter() {

    m_motorShooterLeft.Set(  
        ctre::phoenix::motorcontrol::ControlMode::Velocity,
        ShooterConstants::ShooterRpmTarget
        //ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
        //-1.0
    );
    m_motorShooterRight.Set(
        ctre::phoenix::motorcontrol::ControlMode::Velocity,
        ShooterConstants::ShooterRpmTarget
        //ctre::phoenix::motorcontrol::ControlMode::PercentOutput,
        //1.0
    );
}


void ShooterSubsystem::SpindownShooter() {
    m_motorShooterLeft.NeutralOutput( );
    m_motorShooterRight.NeutralOutput( );
}

double ShooterSubsystem::GetMaxAngle()
{
    return 2.995;
}

double ShooterSubsystem::GetMinAngle()
{
    return 1.90;
}

void ShooterSubsystem::AngleShooterUp() 
{
    MoveShooter( -0.8 );
}


bool ShooterSubsystem::IsShooterFullyLowered() 
{
    return ( GetRotationDegreeA() < GetMinAngle() );
}


void ShooterSubsystem::AngleShooterDown() 
{
    MoveShooter( 0.8 );
}


void ShooterSubsystem::MoveShooter( double speed ) 
{
    double moveSpeed = 0.0;
    if ( speed > 0.0 )
    {
        if ( GetRotationDegreeA() > GetMinAngle() )
        {
           moveSpeed = speed;
        }
    }

    if ( speed < 0.0 )
    {
        if ( GetRotationDegreeA() < GetMaxAngle() ) 
        {
           moveSpeed = speed;
        }
    }

    m_motorAngle.Set( moveSpeed );
}




void ShooterSubsystem::StopShooterAngle() 
{   
    MoveShooter( 0.0 );
}


bool ShooterSubsystem::IsShooterReady() {
    float const rpmLeft = \
        m_motorShooterLeft.GetSelectedSensorVelocity( 
            ShooterConstants::kSensorId );

    float const rpmRight = \
        m_motorShooterRight.GetSelectedSensorVelocity( 
            ShooterConstants::kSensorId );
            
    bool ready = true;

    if ( rpmLeft < ShooterConstants::ShooterRpmMin &&
         rpmLeft > ShooterConstants::ShooterRpmMax )
    {
        ready = false;
    }

    if ( rpmRight < ShooterConstants::ShooterRpmMin &&
         rpmRight > ShooterConstants::ShooterRpmMax )
    {
        ready = false;
    }

    return ready;
}

double ShooterSubsystem::GetRotationDegreeA() {
   return m_jdA.GetDistance();
}

double ShooterSubsystem::GetRotationDegreeB() {
   return m_jdB.GetDistance();
}

void ShooterSubsystem::ResetEncoder() {
    m_jdA.Reset();  //Reset the Encoder distance to Zero
    m_jdB.Reset();
    m_jdA.SetDistancePerRotation(ShooterConstants::kDistPerRotation);
    m_jdB.SetDistancePerRotation(ShooterConstants::kDistPerRotation);
}



double ShooterSubsystem::CalculateTargetAngleFromCameraValue( double cameraValue ) {
    if ( cameraValue >= 0 )
    {
        return ( 3.37 - 0.03 - 4.21e-3 * cameraValue + 5.64e-6 * cameraValue * cameraValue );
    }
    else
    {
        return -1;
    }
    
}



bool ShooterSubsystem::TiltToAngle( double angle ) {

 #if USE_SHOOTER_PID
  double const motorControl =  -m_pid.Calculate( GetRotationDegreeA(), angle );
  if ( 0 )
  {
    extern nt::NetworkTableEntry yEntry;
    extern nt::NetworkTableEntry xEntry;
    double const yVal = yEntry.GetDouble( -1.0 );
    double const xVal = xEntry.GetDouble( -1.0 );

    

      std::cout << "x " <<  
          GetRotationDegreeA() << " " << 
          m_pid.GetPositionError() << " " <<
          m_pid.GetSetpoint() <<   " " <<
          motorControl << " " <<
          "\n";
  }


  if ( angle > -1 )
  {
      MoveShooter( std::clamp( motorControl, -1.0, 1.0 ) );
  }
  else
  {
    m_pid.Reset();
    MoveShooter( m_pid.Calculate( GetRotationDegreeB(), angle ) );
  }


    return m_pid.AtSetpoint();
 #else
    if ( GetRotationDegreeB() < ( angle - 0.005) )
    {
        m_goodAngleCount = 0;
        AngleShooterUp();
    }
    else if (  GetRotationDegreeB() > ( angle + 0.005) )
    {
        m_goodAngleCount = 0;
        AngleShooterDown();
    }
    else
    {
        m_goodAngleCount++;
        StopShooterAngle();
    }
    return m_goodAngleCount > 5;
 #endif
}



bool ShooterSubsystem::TiltToTarget() {
   extern nt::NetworkTableEntry yEntry;
   double const yVal = yEntry.GetDouble( -1.0 );
   bool goodAngle = false;
   //if ( yVal > 0 )
   {
    double const angle = CalculateTargetAngleFromCameraValue( yVal );
    //std::cout << "yVal: " << yVal << " " << angle << "\n";

     goodAngle = TiltToAngle( angle );
   }
   return goodAngle;
}



