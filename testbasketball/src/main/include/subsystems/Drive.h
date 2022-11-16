// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/Spark.h>
#include <frc2/command/SubsystemBase.h>

class Drive: public frc2::SubsystemBase {

private:
    // left
    frc::Spark m_leftWheels{0};
    
    // right
    frc::Spark m_rightWheels{1};

    frc::DifferentialDrive m_differentialDrive{m_leftWheels, m_rightWheels};

public:
    Drive();
    void Periodic() override;
    void SimulationPeriodic() override;
    void Motivate(double leftSpeed, double rightSpeed);
    void Stop();
};