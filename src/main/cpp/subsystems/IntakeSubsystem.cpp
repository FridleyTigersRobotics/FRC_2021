/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <stdio.h>

#include <Constants.h>
#include <subsystems/IntakeSubsystem.h>

IntakeSubsystem::IntakeSubsystem() :
    m_intakeState      { INTAKE_STATE_HOLD },
    m_motorIntakeRotate{ IntakeConstants::kIntakeRotateMotorPwmId },
    m_motorIntakeExtend{ IntakeConstants::kIntakeExtendMotorPwmId },
    m_topLimitSwitch   { IntakeConstants::kIntakeTopLimitDioPort },
    m_botLimitSwitch   { IntakeConstants::kIntakeBotLimitDioPort }
{

}

// This method will be called once per scheduler run
void IntakeSubsystem::Periodic() { 
    double extendMotorSpeed = 0.0;
    //std::cout << "m_intakeState: " << m_intakeState  << " " << IsTopLimitEngaged() << " " << IsBotLimitEngaged() << "\n";
    switch ( m_intakeState )
    {
        case INTAKE_STATE_RAISE:
        {
            if ( IsTopLimitEngaged() == true )
            {
                extendMotorSpeed = 0.0;
                m_intakeState    = INTAKE_STATE_HOLD;
            }
            else
            {
                extendMotorSpeed = 1.0;
            } 
            
            break;
        }
        case INTAKE_STATE_LOWER:
        {
            if ( IsBotLimitEngaged() == true )
            {
                extendMotorSpeed = 0.0;
                m_intakeState    = INTAKE_STATE_HOLD;
            }
            else
            {
                extendMotorSpeed = -1.0;
            }
            break;
        }
        default:
        case INTAKE_STATE_HOLD:
        {
            extendMotorSpeed = 0.0;
            break;
        }
    }

    m_motorIntakeExtend.Set( extendMotorSpeed );
}

void IntakeSubsystem::StartIntake() {
    m_motorIntakeRotate.Set( IntakeConstants::kIntakeMotorSpeed );
}


void IntakeSubsystem::StartIntakeReverse() {
    
    m_motorIntakeRotate.Set( -IntakeConstants::kIntakeMotorSpeed );

}


void IntakeSubsystem::StopIntake() {
    m_motorIntakeRotate.Set( 0.0 );
}   


void IntakeSubsystem::LowerIntake() 
{
    m_intakeState = INTAKE_STATE_LOWER;
}

void IntakeSubsystem::HoldIntake() 
{
    m_intakeState = INTAKE_STATE_HOLD;
}

void IntakeSubsystem::RaiseIntake() 
{
    m_intakeState = INTAKE_STATE_RAISE;
}   


bool IntakeSubsystem::IsTopLimitEngaged() 
{
    return m_topLimitSwitch.Get();
}   

bool IntakeSubsystem::IsBotLimitEngaged() 
{
    return m_botLimitSwitch.Get();
}   

