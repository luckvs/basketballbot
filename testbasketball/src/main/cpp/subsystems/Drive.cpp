// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drive.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <wpi/raw_ostream.h> // for wpi outs()

Drive::Drive(){
    SetName("Drive");
    SetSubsystem("Drive");

    AddChild("DifferentialDrive", &m_differentialDrive);
    m_differentialDrive.SetSafetyEnabled(true);
    m_differentialDrive.SetExpiration(0.1_s);
    m_differentialDrive.SetMaxOutput(1.0);

    AddChild("m_rightWheels", &m_rightWheels);
    m_rightWheels.SetInverted(true);

    AddChild("m_leftWheels", &m_leftWheels);
    m_leftWheels.SetInverted(false);
}

void Drive::Periodic() {
    // Put code here to be run every loop
}

void Drive::SimulationPeriodic() {
    // This method will be called once per scheduler run when in simulation
}

// Functions called by robot commands
void Drive::Motivate(double leftSpeed, double rightSpeed) {

    m_differentialDrive.ArcadeDrive(leftSpeed,rightSpeed, true);
}

void Drive::Stop(){
    // cease your actions!!
    m_differentialDrive.ArcadeDrive(0.0, 0.0, true);
}